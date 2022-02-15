# ans_2022

準備中  

# 内容
研究でよく使うプログラムの実装方法をまとめた．  
* 線形代数 : [la](/la)
* グラフ作成 : [graph](/graph)
* 常微分方程式を解く : [ode](/ode)
* 線形二次レギュレータ : [lqr](/lqr)  
* シンボリック演算 : [symbolic](/symbolic)  

最後に総合演習として車両型倒立振子の制御シミュレーションを扱う．  
* [exercise](/excercise/)

# Requirement
## C
?  

## C++
?  
* Eigen
* boost

## Python
Python3です  
必要なライブラリ一覧  

* pyyaml
* control  

以下はAnacondaを使っている場合インストール不要  
* numpy
* matplotlib
* scipy
* sympy
* pandas

以下のコマンドで一括インストール  
```bash
conda install 
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

`]`を押してPkgモードに入り，以下のコマンドで一括インストール  
```julia
add Plots,LaTeXStrings,DifferentialEquations,ParameterizedFunctions,DataFrames,CSV,Symbolics,Latexify,LinearAlgebra,MatrixEquations,BenchmarkTools
```

## MATLAB
研究室の計算機に入ってるMATLABでは使える  
* Symbolic Math Toolbox
* Control System Toolbox




# Note
2021年度の反省をもとに，本当に基礎的なことだけ書くようにします．  



## Author
* Matsuta Yoshimitsu
* email : sbb03104@edu.osakafu-u.ac.jp