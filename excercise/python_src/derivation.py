"""
jupyter notebookのpythonコードだけまとめたもの
"""

import sympy as sy
from sympy.utilities.codegen import codegen
from sympy.printing.numpy import NumPyPrinter


# 必要なシンボリック文字を用意
t = sy.Symbol("t")  # 時刻
M = sy.Symbol("M")  # 台車の質量
m = sy.Symbol("m")  # 振り子の質量
l = sy.Symbol("l")  # 長さ
L = 2*l
g = sy.Symbol("g")  # 重力加速度
D_theta, D_x = sy.symbols("D_theta, D_x")  # 回転方向と並進方向の摩擦係数

x = sy.Function("x")  # 台車の位置
theta = sy.Function("theta")  # 振り子の角度
u = sy.Symbol("u")  # 制御入力


### エネルギーを定義 ###
# 運動エネルギー
K = sy.Rational(2, 3)*m*l**2*sy.Derivative(theta(t), t)**2 +\
    m*l*sy.Derivative(x(t), t)*sy.Derivative(theta(t), t)*sy.cos(theta(t)) +\
        sy.Rational(1, 2)*(M+m)*sy.Derivative(x(t), t)**2

# ポテンシャルエネルギー
U = m*g*l*sy.cos(theta(t))

# 損失エネルギー
D = sy.Rational(1, 2)*D_theta*sy.Derivative(theta(t), t)**2 + sy.Rational(1, 2)*D_x*sy.Derivative(x(t), t)**2


### ラグランジュの運動方程式に代入 ###
# x方向
dKdv = sy.diff(K, sy.Derivative(x(t), t))
dKdv_dot = sy.diff(dKdv, t)
dKdx = sy.diff(K, x(t))
dUdx = sy.diff(U, x(t))
dDdv = sy.diff(D, sy.Derivative(x(t), t))
u_x = u

# theta方向
dKdomega = sy.diff(K, sy.Derivative(theta(t), t))
dKdomega_dot = sy.diff(dKdomega, t)
dKdtheta = sy.diff(K, theta(t))
dUdtheta = sy.diff(U, theta(t))
dDdomega = sy.diff(D, sy.Derivative(theta(t), t))
u_theta = 0

# 代入
f_x = dKdv_dot - dKdx + dUdx + dDdv - u_x
f_theta = dKdomega_dot - dKdtheta + dUdtheta + dDdomega - u_theta

# 加速度=の式に変形
sol = sy.solve(
    [f_x, f_theta],
    [sy.Derivative(sy.Derivative(x(t), t), t), sy.Derivative(sy.Derivative(theta(t), t), t)]
)
for k in sol.keys():
    sol[k] = sol[k].simplify()


a_x = sol[sy.Derivative(x(t), (t, 2))]
a_theta = sol[sy.Derivative(theta(t), (t, 2))]


### 状態方程式を求める ###
# 状態ベクトル
X = sy.Matrix(sy.MatrixSymbol('x', 4, 1))

# 状態方程式
x1_dot = X[1, 0]
x3_dot = X[3, 0]

x2_dot = a_x.subs([
    (sy.Derivative(x(t), t), X[1, 0]),
    (sy.Derivative(theta(t), t), X[3, 0]),
    (x(t), X[0, 0]),
    (theta(t), X[2, 0])
])

x4_dot = a_theta.subs([
    (sy.Derivative(x(t), t), X[1, 0]),
    (sy.Derivative(theta(t), t), X[3, 0]),
    (x(t), X[0, 0]),
    (theta(t), X[2, 0])
])


Fxu = sy.Matrix([
    [x1_dot],
    [x2_dot],
    [x3_dot],
    [x4_dot],
])


### 状態方程式の線形化 ###

fx = Fxu.subs(u, 0)

Fxu = Fxu.expand()
B = sy.Matrix([
    [Fxu[0,0].coeff(u, 1)],
    [Fxu[1,0].coeff(u, 1)],
    [Fxu[2,0].coeff(u, 1)],
    [Fxu[3,0].coeff(u, 1)],
])

A = fx.jacobian(X)


### コード生成 ###
# pythonコード
with open("state_eq.py", "w") as f:
    numpy_word = "import numpy\n\ndef f(x, u, m, M, l, g, D_x, D_theta):\n    return "
    f.write(numpy_word)
    f.write(NumPyPrinter().doprint(Fxu))

with open("A.py", "w") as f:
    numpy_word = "import numpy\n\ndef f(x, m, M, l, g, D_x, D_theta):\n    return "
    f.write(numpy_word)
    f.write(NumPyPrinter().doprint(A))

with open("B.py", "w") as f:
    numpy_word = "import numpy\n\ndef f(x, m, M, l, g, D_x, D_theta):\n    return "
    f.write(numpy_word)
    f.write(NumPyPrinter().doprint(B))


# cコード
codegen(
    name_expr = ("state_eq", Fxu),
    language = "C",
    project= "state_eq",
    to_files = True
)

codegen(
    name_expr = ("A", A),
    language = "C",
    project= "A",
    to_files = True
)
codegen(
    name_expr = ("B", B),
    language = "C",
    project= "B",
    to_files = True
)