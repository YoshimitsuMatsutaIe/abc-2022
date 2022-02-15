clear;

syms M m l D_x D_theta g u
syms t x(t) theta(t)

assume(M, 'positive');
assume(m, 'positive');
assume(l, 'positive');
assume(D_x, 'positive');
assume(D_theta, 'positive');
assume(g, 'positive');


v = diff(x(t), t);
omega = diff(theta, t);

%% エネルギー

K = 2/3*m*l^2*omega^2 +...
    m*l*v*omega*cos(theta) +...
        1/2*(M+m)*v^2;

U = m*g*l*cos(theta);

D = 1/2*D_theta*omega^2 + 1/2*D_x*v^2;


%% ラグランジュの運動方程式に代入
% x方向
dKdv = diffDepVar(K, v, x);
dKdv_dot = diff(dKdv, t);
dKdx = diffDepVar(K, x, t);
dUdx = diffDepVar(U, x, t);
dDdv = diffDepVar(D, v, x);
u_x = u;
f_x = dKdv_dot - dKdx + dUdx + dDdv - u_x;

% theta方向
dKdomega = diffDepVar(K, omega, theta);
dKdomega_dot = diff(dKdomega, t);
dKdtheta = diffDepVar(K, theta, t);
dUdtheta = diffDepVar(U, theta, t);
dDdomega = diffDepVar(D, omega, theta);
u_theta = 0;
f_theta = dKdomega_dot - dKdtheta + dUdtheta + dDdomega;

diffeq = [f_x; f_theta] == [0;0];
diffeq = simplify(diffeq)

q = sym("q", [4 1]);
syms a_x a_theta

diffeq = subs(diffeq, [diff(x,t,t) diff(theta,t,t)], [a_x a_theta]);
diffeq = subs(diffeq, [diff(x,t) diff(theta,t)], [q(2) q(4)]);
diffeq = subs(diffeq, [x theta], [q(1) q(3)]);

S = solve(diffeq, a_x, a_theta);



dq2 = simplify(S.a_x);
dq4 = simplify(S.a_theta);

%% 状態方程式 
Fxu = [q(2); dq2; q(4); dq4]
J = jacobian(Fxu, q)
A = subs(J, u, 0)

b2 = coeffs(Fxu(2), u);
b4 = coeffs(Fxu(4), u);
B = [0; b2(2); 0; b4(2)]

%% コード生成
matlabFunction(Fxu,'file','Fxu.m');
matlabFunction(A,'file','A.m');
matlabFunction(B,'file','B.m');

ccode(Fxu,'File','Fxu.c');
ccode(A,'File','A.c');
ccode(B,'File','B.c');

function res = diffDepVar(fun, depVar, Var)
    % funをdepVarで微分する
    % depVarはVarに依存する
    % 以下のぺージを参考にしました
    % :https://jp.mathworks.com/matlabcentral/answers/102597-how-can-i-solve-the-euler-lagrange-equation-in-the-symbolic-toolbox-5-3-r2009b
syms xx yy
res = diff(subs(fun,[depVar Var],[xx yy]),xx);
res = subs(res,[xx yy],[depVar Var]);
end


