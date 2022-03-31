# C++


オイラー法，ルンゲクッタ法の更新式については[pythonの資料](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/python_src/simple.ipynb) を見てください．  

## 扱う微分方程式
### 1 1次元の常微分方程式 : ?
<br>
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\dot{x}=ax" title="\bg_white \dot{x}=ax" />  
<br>

[src](exp_using_solver)  
<br>

### 2 連立常微分方程式 : ローレンツ方程式
<br>
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\begin{pmatrix}\dot{x}\\&space;\dot{y}\\&space;\dot{z}\end{pmatrix}=\begin{pmatrix}-px&plus;py\\-xz&plus;rx-y\\&space;xy-bz\\\end{pmatrix}" title="\bg_white \begin{pmatrix}\dot{x}\\ \dot{y}\\ \dot{z}\end{pmatrix}=\begin{pmatrix}-px+py\\-xz+rx-y\\ xy-bz\\\end{pmatrix}" />  
<br>

パラメータ，初期値は以下を使用．  
```python
[x0, y0, z0] = [0, 4, 28]  
p = 10, r = 26, b = 8/3  
```

[eigen使用](lorenz)  
[boost使用](lorenz_using_solver)  
<br>

## グラフ
matplotlibでのグラフ作成 : [https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/cpp_src/plot_from_csv.ipynb](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/cpp_src/plot_from_csv.ipynb)  


# Requirement
## Eigen  
一部でEigenを使ってます．  
Eigenはヘッダオンリーで使用できる行列演算ライブラリで，numpyのように行列の和や積，逆行列，LU分解等が簡単に計算できます．  
### ubuntu
```bash
sudo apt install libeigen3-dev
```
上のコマンドで`/usr/include/eigen3/`にインストールされる．  
### windows
公式ページ[https://gitlab.com/libeigen/eigen/-/releases/3.4.0](https://gitlab.com/libeigen/eigen/-/releases/3.4.0)からダウンロードし，Eigenを使うソースコードと同じディレクトリに置いてください．  

## boost  
常微分方程式のソルバー`boost::odeint`を使用  

## cmake  
各ディレクトリにはCMakeLists.txtを置いておくので，以下のコマンドでビルドしてもよい．  
```bash
cmake -S . -B build
cmake --build build/
```
実行ファイルは`./build/main`．