# 状態方程式の導出

まずはシンボリック変数を準備  

```MATLAB
syms M m l D_x D_theta g u
syms t x(t) theta(t)

v = diff(x(t), t);
omega = diff(theta, t);
```
変数に対する仮定を定義  

```MATLAB
assume(M, 'positive');
assume(m, 'positive');
assume(l, 'positive');
assume(D_x, 'positive');
assume(D_theta, 'positive');
assume(g, 'positive');
```
# エネルギー
運動エネルギー<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\mathfrak{K}" title="\bg_white \mathfrak{K}" />，ポテンシャルエネルギー<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\mathfrak{U}" title="\bg_white \mathfrak{U}" />，損失エネルギー<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\mathfrak{D}" title="\bg_white \mathfrak{D}" />は次である．  

<br>  

<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\mathfrak{K}=\frac{2}{3}ml^2\dot{\theta}^2&plus;ml\dot{x}\dot{\theta}&plus;\frac{1}{2}(M&plus;m)\dot{x}^2\\\\~~~~~~\mathfrak{U}=&space;mgl\cos(\theta)\\\\~~~~~~\mathfrak{D}=&space;\frac{1}{2}D_{\theta}\dot{\theta}^2&plus;\frac{1}{2}D_{x}\dot{x}^2\\" title="\bg_white \mathfrak{K}=\frac{2}{3}ml^2\dot{\theta}^2+ml\dot{x}\dot{\theta}+\frac{1}{2}(M+m)\dot{x}^2\\\\~~~~~~\mathfrak{U}= mgl\cos(\theta)\\\\~~~~~~\mathfrak{D}= \frac{1}{2}D_{\theta}\dot{\theta}^2+\frac{1}{2}D_{x}\dot{x}^2\\" />


```MATLAB
K = 2/3*m*l^2*omega^2 +...
    m*l*v*omega*cos(theta) +...
        1/2*(M+m)*v^2;

U = m*g*l*cos(theta);

D = 1/2*D_theta*omega^2 + 1/2*D_x*v^2;
```


# ラグランジュの運動方程式に代入

ラグランジュの運動方程式は次式．  
<br>
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\frac{\mathrm{d}&space;}{\mathrm{d}&space;t}(\frac{\partial&space;\mathfrak{K}}{\partial&space;\dot{q}_i})-\frac{\partial&space;\mathfrak{K}}{\partial&space;q_i}&plus;\frac{\partial&space;\mathfrak{U}}{\partial&space;q_i}&plus;\frac{\partial&space;\mathfrak{D}}{\partial&space;\dot{q}_i}=u_i,~i=1,...,l" title="\bg_white \frac{\mathrm{d} }{\mathrm{d} t}(\frac{\partial \mathfrak{K}}{\partial \dot{q}_i})-\frac{\partial \mathfrak{K}}{\partial q_i}+\frac{\partial \mathfrak{U}}{\partial q_i}+\frac{\partial \mathfrak{D}}{\partial \dot{q}_i}=u_i,~i=1,...,l" />
<br>

次の関数を使う．  
```MATLAB
function res = diffDepVar(fun, depVar, Var)
    % funをdepVarで微分する
    % depVarはVarに依存する
    % 以下のぺージを参考にしました
    % :https://jp.mathworks.com/matlabcentral/answers/102597-how-can-i-solve-the-euler-lagrange-equation-in-the-symbolic-toolbox-5-3-r2009b
syms xx yy
res = diff(subs(fun,[depVar Var],[xx yy]),xx);
res = subs(res,[xx yy],[depVar Var]);
end
```
この関数はソースコードの最後に書いておく．  
順番に代入する．  

```MATLAB
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
```

## 加速度を求める
`x`, `theta`, `v`, `omega`の時刻依存が邪魔なので一般化位置で置き換える．  
```MATLAB
q = sym("q", [4 1]);
syms a_x a_theta

diffeq = subs(diffeq, [diff(x,t,t) diff(theta,t,t)], [a_x a_theta]);
diffeq = subs(diffeq, [diff(x,t) diff(theta,t)], [q(2) q(4)]);
diffeq = subs(diffeq, [x theta], [q(1) q(3)]);
```

`solve`関数で加速度，角加速度の連立方程式を解く．  
```MATLAB
S = solve(diffeq, a_x, a_theta);
dq2 = simplify(S.a_x);
dq4 = simplify(S.a_theta);
```
以上で加速度が求まった．  

# 状態方程式
状態方程式  
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\dot{\textbf{x}}=f(\textbf{x},&space;u)" title="\bg_white \dot{\textbf{x}}=f(\textbf{x}, u)" />  
は次になる．  

```MATLAB
Fxu = [q(2); dq2; q(4); dq4]
```

# 状態方程式の線形化
まず状態方程式を入力アフィンの形にする  
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\dot{\textbf{x}}=f(\textbf{x})&space;&plus;&space;\textbf{B}u" title="\bg_white \dot{\textbf{x}}=f(\textbf{x}) + \textbf{B}u" />  

## B行列
`Fxu`の入力`u`に関する係数を求め，B行列を作成する．  

```MATLAB
b2 = coeffs(Fxu(2), u);
b4 = coeffs(Fxu(4), u);
B = [0; b2(2); 0; b4(2)]
```

## A行列
fxを状態ベクトルで偏微分し，x'近傍で線形化する  
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;f(\textbf{x})\approx\left.\begin{matrix}\frac{\partial&space;f}{\partial&space;\textbf{x}}\end{matrix}\right|_{\textbf{x}=\textbf{x}'}\textbf{x}=\textbf{A}\textbf{x}&space;" title="\bg_white f(\textbf{x})\approx\left.\begin{matrix}\frac{\partial f}{\partial \textbf{x}}\end{matrix}\right|_{\textbf{x}=\textbf{x}'}\textbf{x}=\textbf{A}\textbf{x} " />  

```MATLAB
J = jacobian(Fxu, q)
A = subs(J, u, 0)
```

# コード生成
MATLABコード  
```MATLAB
matlabFunction(Fxu,'file','Fxu.m');
matlabFunction(A,'file','A.m');
matlabFunction(B,'file','B.m');
```

Cコード  

```MATLAB
ccode(Fxu,'File','Fxu.c');
ccode(A,'File','A.c');
ccode(B,'File','B.c');
```