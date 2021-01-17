% -------------------------------------------------------------------
%  Generated by MATLAB on 24-Nov-2020 07:52:20
%  MATLAB version: 9.9.0.1495850 (R2020b) Update 1
% -------------------------------------------------------------------
saveVarsMat = load('pagerank.mat');

ConnectivityMatrix = ...
  [0 1 1 1 1;
   1 0 0 1 0;
   0 0 0 0 0;
   1 1 1 0 0;
   0 1 0 1 0];

D = zeros(5,5);
D(1,1) = 0.5;
D(2,2) = 0.33333333333333331;
D(3,3) = 0.5;
D(4,4) = 0.33333333333333331;
D(5,5) = 1;
D = sparse(D);

PageRank = [0.32105348086675889; 0.23618046199996406; 0.030000000000000002; ...
            0.246115526935029; 0.16665053019824805];

Q = ...
  [1 1 1 1 1;
   1 1 1 1 1;
   1 1 1 1 1;
   1 1 1 1 1;
   1 1 1 1 1];

StochasticMatrix = ...
  [0 0.33333333333333331 0.5 0.33333333333333331 1;
   0.5 0 0 0.33333333333333331 0;
   0 0 0 0 0;
   0.5 0.33333333333333331 0.5 0 0;
   0 0.33333333333333331 0 0.33333333333333331 0];

TransitionMatrix = ...
  [0.030000000000000006 0.31333333333333335 0.455 0.31333333333333335 0.88 ...
   ;
   0.455 0.030000000000000006 0.030000000000000006 0.31333333333333335 ...
   0.030000000000000006;
   0.030000000000000006 0.030000000000000006 0.030000000000000006 0.030000000000000006 ...
   0.030000000000000006;
   0.455 0.31333333333333335 0.455 0.030000000000000006 0.030000000000000006 ...
   ;
   0.030000000000000006 0.31333333333333335 0.030000000000000006 0.31333333333333335 ...
   0.030000000000000006];

column = saveVarsMat.column; % <1x0 double> empty object

columns = 5;

columnsums = [2 3 2 3 1];

dimension = 5;

i = 100;

p = 0.85;

row = saveVarsMat.row; % <1x0 double> empty object

rows = 5;

zerocolumns = [1 2 3 4 5];

clear saveVarsMat;
