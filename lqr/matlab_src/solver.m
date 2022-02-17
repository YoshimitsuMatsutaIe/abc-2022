clear;

%% システム

x0 = [1, 0.5];

% システム
A = [
    1.1 2
    -0.3 -1
];
B = [
    1 2
    0.847 3
];
C = [
    1. 0.
    0. 1.
];

sys = ss(A, B, C, zeros(2, 2));

%% 初期値応答
initial(sys,x0)


%% リカッチ題数方程式を解く
Q = diag([10.0, 10.0]);
R = diag([1., 1.]);


S = [];
E = [];
G = [];

[P, K, L] = icare(A, B, Q, R, S, E, G);

%% 最適レギュレータ
sys.A = sys.A -B*K;  % 更新
initial(sys,x0)