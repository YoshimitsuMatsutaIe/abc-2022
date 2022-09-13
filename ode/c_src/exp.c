/**
 * @file exp.c
 * @author your name (you@domain.com)
 * @brief 次の微分方程式を数値的に解く dydt = a * y
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

double dx(double x, double a){return a * x;}

void euler(int imax, double dt, double x0, double *t, double *x, double a)
{
    t[0] = 0.0;
    x[0] = x0;

    for (int i=0; i < imax-1; i++){
        t[i+1] = t[i] + dt;
        x[i+1] = x[i] + dx(x[i], a) * dt;
    }
}


void runge_kutta(int imax, double dt, double x0, double *t, double *x, double a)
{
    t[0] = 0.0;
    x[0] = x0;
    double k1, k2, k3, k4;
    
    for (int i=0; i < imax-1; i++){
        t[i+1] = t[i] + dt;

        k1 = dx(x[i], a);
        k2 = dx(x[i] + 0.5*dt*k1, a);
        k3 = dx(x[i] + 0.5*dt*k2, a);
        k4 = dx(x[i] + dt*k3, a);

        x[i+1] = x[i] + dt/6.0 * (k1 + 2.0*k2 + 2.0*k3 + k4);
    }
}


int main()
{
    // はじめにシミュレーションデータを全て作成してからcsvに書き出す方式にした．
    // データを後で使わないなら，ループ毎にcsvに書き出したほうが早いかも．

    // 初期値など
    double x0 = 1.0;
    double a = 1.0;
    double dt = 0.1;
    double T = 5.0;
    
    // 結果を書き出す配列を準備
    int imax = T / dt;  // ループ回数
    double *t, *x;
    t = (double *)malloc(imax * sizeof(double));  // 時間を格納する配列
    x = (double *)malloc(imax * sizeof(double));  // 状態変数を格納する配列

    // データを保存するcsv
    FILE *fe;
    FILE *fr;


    // 微分方程式を解いてcsvに出力

    // オイラー法
    euler(imax, dt, x0, t, x, a);  // 解く

    // csvに保存
    fe = fopen("exp_euler.csv", "w");
    fprintf(fe, "t,x\n");
    for (int i=0; i < imax; i++){
        fprintf(fe, "%lf,%lf\n", t[i], x[i]);
    }
    fclose(fe);


    // ルンゲクッタ法
    runge_kutta(imax, dt, x0, t, x, a);  // 解く

    // csvに保存
    fr = fopen("exp_runge_kutta.csv", "w");
    fprintf(fr, "t,x\n");
    for (int i=0; i < imax; i++){
        fprintf(fr, "%lf,%lf\n", t[i], x[i]);
    }
    fclose(fr);

    // メモリ解放
    free(t);
    free(x);

    return 0;
}