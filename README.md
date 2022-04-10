# abc_2022

準備中  

# 内容
* ~線形代数 : [la](/la)~
* グラフ作成 : [graph](/graph)
* 常微分方程式 : [ode](/ode)
* 線形二次レギュレータ : [lqr](/lqr)  
* シンボリック演算 : [symbolic](/symbolic)  
* その他（C関数の呼び出し，自動微分など）:[other](/other/)

最後に総合演習として車両型倒立振子の制御シミュレーションを扱う．  
* [exercise](/excercise/)

# Requirement
環境構築でうまくいかないときは，M1やM2に相談してください．  
## C
特になし  

## C++  
C++11以上であればOK．  
一部で行列演算のために`Eigen`，微分方程式を解くために`boost`を利用しています（必須ではありません）．  
* Eigen  
* boost  

### OSがubuntuのとき
ターミナルで次のコマンドを入力するとインストールできる．  
```bash
sudo apt install libeigen3-dev
sudo apt install libboost-all-dev
```
成功すると`/usr/include/eigen3/`，`/usr/include/boost/`にダウンロードされる．  

### OSがubuntu以外のとき
公式サイトからダウンロードし，適当な場所に保存してください．  
本レポジトリのソースコードにある`#include "~/Eigen/Core"`等のパスを適宜変更してください．  


## Python
Python3  
必要なライブラリ  

* pyyaml
* control  

以下はAnacondaを使っている場合はインストール済み  
* numpy
* matplotlib
* scipy
* sympy
* pandas

適当なターミナルで以下のコマンドを入力し，一括インストール  
### conda
```bash
conda install -c anaconda pyyaml
conda install -c conda-forge control
```
### pip
```bash
pip install numpy matplotlib scipy sympy pandas PyYAML control
```


## julia
* Plots
* LaTeXStrings
* DifferentialEquations
* ParameterizedFunctions
* DataFrames
* CSV
* Symbolics
* Latexify
* LinearAlgebra
* MatrixEquations
* BenchmarkTools  

<br>

juliaを起動し`]`を押してPkgモードに入る．以下のコマンドで一括インストールできる．  
```julia
add Plots,LaTeXStrings,DifferentialEquations,ParameterizedFunctions,DataFrames,CSV,Symbolics,Latexify,LinearAlgebra,MatrixEquations,BenchmarkTools
```

## MATLAB
次のツールボックスを使います．  
* Symbolic Math Toolbox
* Control System Toolbox
研究室の計算機に入ってるMATLABでは使えます．  



# Note
2021年度の反省をもとに，本当に基礎的なことだけ書くようにします．  



## Author
* Matsuta Yoshimitsu
* email : sbb03104@st.osakafu-u.ac.jp