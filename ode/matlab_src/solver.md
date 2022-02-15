# ソルバを使って解く
簡単な一次元の微分方程式から考える．  
<img src="https://latex.codecogs.com/png.image?\dpi{120}&space;\bg_white&space;\dot{x}=ax" title="\bg_white \dot{x}=ax" />  
<br>
この微分方程式ソルバを使って解く．  

### 微分方程式の定義
次のように定義する．  
```MATLAB
%% 解く
function dx = myODE(t, x)
    % 微分方程式
    a = 1;
    dx = a * x;
end
```
初期値，時間区間をセットする．  
```MATLAB
tspan = [0.0, 5.0];  % 時間
x0 = 1.0;  % 初期値
```
`ode45`を使って解く．  
```MATLAB
[t, y] = ode45(@myODE, tspan, x0);  % 解く
```
解をプロットして確認  
```MATLAB
%% グラフ化
plot(t, y);
legend('soltion');
grid on
```
(こんなグラフのウィンドウが表示されます．)  


## 解析解と比較
![pic](picture/eb1.png)

### 解析解と比較
上記の微分方程式には厳密解がある．  
<br>
<img src="https://latex.codecogs.com/svg.image?x&space;=&space;Ce^{t}" title="x = Ce^{t}" />  
<br>
数値解`y`と厳密解を同時にプロットしてみる．  

```MATLAB
analy = exp(t)
plot(t, y);
xlabel('time t');
ylabel('x');
legend('soltion');
grid on
```