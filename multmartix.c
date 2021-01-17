/*Names: Mihir Bhatia and Ratish Juneja
CSID: mbhati01 and rj1200
student ID: 76149921 and 61975405
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#define BUFSIZE 256


int main(void) {
    Engine* ep = NULL; // A pointer to a MATLAB engine object
    mxArray* testArray1 = NULL; // mxArray is the fundamental type underlying MATLAB data
    mxArray* result = NULL;
    mxArray* testArray2 = NULL;

    double time1[3][3] = { { 15.0, 26.0, 31.0 }, {42.0, 5.0, 69.0 }, {67.0, 18.0, 69.0 } };    //test matrix 1
    double time2[3][3] = { { 61.0, 21.0, 33.0 }, {47.0, 52.0, 61.0 }, {64.0, 82.0, 19.0 } };     //test matrix 2




    /* Starts a MATLAB process */
    if (!(ep = engOpen(NULL))) {
        fprintf(stderr, "\nCan't start MATLAB engine\n");
        system("pause");
        return 1;
    }

    testArray1 = mxCreateDoubleMatrix(3, 3, mxREAL);
    testArray2 = mxCreateDoubleMatrix(3, 3, mxREAL);

    memcpy((void*)mxGetPr(testArray1), (void*)time1, 9 * sizeof(double));
    memcpy((void*)mxGetPr(testArray2), (void*)time2, 9 * sizeof(double));

    if (engPutVariable(ep, "testArray1", testArray1)) {
        fprintf(stderr, "\nCannot write test array to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }

    if (engPutVariable(ep, "testArray2", testArray2)) {
        fprintf(stderr, "\nCannot write test array to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }

    if (engEvalString(ep, "testArrayProduct = mtimes(testArray1,testArray2)")) {
        fprintf(stderr, "\nError can't multiply  \n");
        system("pause");
        exit(1);
    }

    printf("The first matrix was:\n");
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            printf("%f ", time1[l][k]);
        }
        printf("\n");
    }

    printf("The second matrix was:\n");

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            printf("%f ", time2[l][k]);
        }
        printf("\n");
    }



    if ((result = engGetVariable(ep, "testArrayProduct")) == NULL) {
        fprintf(stderr, "\nFailed to retrieve result matrix\n");
        system("pause");
        exit(1);
    }

    else {
        size_t sizeOfResult = mxGetNumberOfElements(result);
        size_t i = 0;

        printf("The matrix product is:\n");

        for (i = 0; i < sizeOfResult / 3; ++i) {
            printf("%f %f %f\n", *(mxGetPr(result) + i), *(mxGetPr(result) + 3 + i), *(mxGetPr(result) + 6 + i));

        }


    }

    char buffer[BUFSIZE + 1];

    if (engOutputBuffer(ep, buffer, BUFSIZE)) {
        fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
        system("pause");
        return 1;
    }
    buffer[BUFSIZE] = '\0';

    engEvalString(ep, "whos");
    printf("%s\n", buffer);


    mxDestroyArray(testArray1);
    mxDestroyArray(testArray2);
    mxDestroyArray(result);
    testArray1 = NULL;
    testArray2 = NULL;
    result = NULL;
    if (engClose(ep)) {
        fprintf(stderr, "\nFailed to close MATLAB engine\n");
    }

    system("PAUSE");
    return 0;

}