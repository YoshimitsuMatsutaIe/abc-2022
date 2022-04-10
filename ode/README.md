# 常微分方程式を解く
常微分方程式の初期値問題を解くプログラムの作成方法を説明します．  
ライブラリ等で用意されているソルバーを使う方法と，自分で実装する方法の２つを載せています．  
アルゴリズムの導出過程は省略するので，自分で調べてみてください．  

扱う常微分方程式は2つです．  

1. 一次元常微分方程式  
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\dot{x}=ax" title="\bg_white \dot{x}=ax" />  
<br>

2. 連立常微分方程式（ローレンツ方程式）  
<img src=https://latex.codecogs.com/svg.image?\begin{pmatrix}\dot{x}\\\dot{y}\\\dot{z}\end{pmatrix}&space;=&space;\begin{pmatrix}-px&plus;py\\-xz&plus;rx-y\\xy-bz\end{pmatrix}>  
<br>

# 演習課題
練習としてVan der Pol方程式の初期値問題を解くプログラムを作成してみてください．  
* Van der Pol方程式  
<img src="https://latex.codecogs.com/png.latex?\bg_white&space;\frac{\mathrm{d}^2&space;x}{\mathrm{d}&space;t^2}&space;=&space;K(1-x^2)\frac{\mathrm{d}&space;x}{\mathrm{d}&space;t}-x">  
<br>


