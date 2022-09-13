/**
 * @file lorenz.c
 * @author your name (you@domain.com)
 * @brief ローレンツ方程式を解く
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3  // システムの次元

/**
 * @brief ローレンツ方程式のパラメータ
 * 
 */
struct lorenz_param{
    double p;
    double r;
    double b;
};


void lorenz(double *x, double *x_dot, struct lorenz_param* p){
    x_dot[0] = -(*p).p*x[0] + (*p).p*x[1];
    x_dot[1] = -x[0]*x[2] + (*p).r*x[0] - x[1];
    x_dot[2] = x[0]*x[1] - (*p).b*x[2];
}


void runge_kutta(int imax, double dt, double *x0, double *t, double **x, struct lorenz_param* p){
    // 初期値代入
    t[0] = 0.0;
    for (int i=0; i < N; i++){
        x[0][i] = x0[i];
    }

    double temp_x[N];  // 係数kの計算に使用
    double k1[N], k2[N], k3[N], k4[N];
    
    for (int i=0; i < imax-1; i++){
        t[i+1] = t[i] + dt;

        for (int j=0; j < N; j++){
            temp_x[j] = x[i][j];
        }

        lorenz(temp_x, k1, p);

        for (int j=0; j < N; j++){
            temp_x[j] = x[i][j] + 0.5 * dt * k1[j];
        }
        lorenz(temp_x, k2, p);

        for (int j=0; j < N; j++){
            temp_x[j] = x[i][j] + 0.5 * dt * k2[j];
        }
        lorenz(temp_x, k3, p);

        for (int j=0; j < N; j++){
            temp_x[j] = x[i][j] + dt * k3[j];
        }
        lorenz(temp_x, k4, p);

        for (int j=0; j < N; j++){
            x[i+1][j] = x[i][j] + dt/6.0*(k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j]);
        }
    }
}



int main(){
    // 初期値など
    double x0[N] = {0.0, 4.0, 28.0};

    struct lorenz_param param = {10.0, 28.0, 8.0/3.0};
    
    double dt = 0.01;
    double T = 50.0;
    
    // 結果を書き出す配列を準備
    int imax = T / dt;  // ループ回数
    double *t;
    t = (double *)malloc(imax * sizeof(double));  // 時間を格納する配列
    
    double **x;
    x = malloc(imax * sizeof(double *));
    for (int i=0; i<imax; i++){
        x[i] = (double *)malloc(N * sizeof(double));
    }

    // データを保存するcsv
    FILE *f;

    // ルンゲクッタ法
    runge_kutta(imax, dt, x0, t, x, &param);  // 解く

    // csvに保存
    f = fopen("lorenz_runge_kutta.csv", "w");
    fprintf(f, "t,x,y,z\n");
    for (int i=0; i < imax; i++){
        fprintf(f, "%lf", t[i]);
        for (int j=0; j < N; j++){
            fprintf(f, ",%lf", x[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    // メモリ解放
    free(t);

    for (int i=0; i<imax; i++){
        free(x[i]);
    }
    free(x);

    return 0;
}