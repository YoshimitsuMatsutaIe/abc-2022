# C++


オイラー法，ルンゲクッタ法の更新式については[pythonの資料](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/python_src/simple.ipynb) を見てください．  

## 扱う微分方程式

### 連立常微分方程式 : ローレンツ方程式
<br>
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\begin{pmatrix}\dot{x}\\&space;\dot{y}\\&space;\dot{z}\end{pmatrix}=\begin{pmatrix}-px&plus;py\\-xz&plus;rx-y\\&space;xy-bz\\\end{pmatrix}" title="\bg_white \begin{pmatrix}\dot{x}\\ \dot{y}\\ \dot{z}\end{pmatrix}=\begin{pmatrix}-px+py\\-xz+rx-y\\ xy-bz\\\end{pmatrix}" />  
<br>

パラメータ，初期値は以下を使用．  
```python
[x0, y0, z0] = [0, 4, 28]  
p = 10, r = 26, b = 8/3  
```

[eigen使用](lorenz.cpp)  
[boost使用](lorenz_using_odeint.cpp)  
<br>

## グラフ
matplotlibでのグラフ作成 : [https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/cpp_src/plot_from_csv.ipynb](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/cpp_src/plot_from_csv.ipynb)  


# Requirement
## Eigen  
Eigenを使ってます．  
Eigenはヘッダオンリーで使用できる行列演算ライブラリで，numpyのように行列の和や積，逆行列，LU分解等が簡単に計算できます．  
### ubuntu
```bash
sudo apt install libeigen3-dev
```
上のコマンドで`/usr/include/eigen3/`にインストールされる．  
### windows
公式ページ[https://gitlab.com/libeigen/eigen/-/releases/3.4.0](https://gitlab.com/libeigen/eigen/-/releases/3.4.0)からダウンロードし，適当なディレクトリに置いてください．  

## boost  
常微分方程式のソルバー`boost::odeint`を使用  
