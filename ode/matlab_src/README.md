# MATLAB

オイラー法，ルンゲクッタ法の更新式については[pythonの資料](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/python_src/simple.ipynb) を見てください．  


## 扱う微分方程式
### 1 1次元の常微分方程式 : ?
<br>
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\dot{x}=ax" title="\bg_white \dot{x}=ax" />  
<br>

[src](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/c_src/exp.c)  
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

[src](https://github.com/YoshimitsuMatsutaIe/ans_2022/blob/main/ODE/c_src/lorenz.c)  
<br>


