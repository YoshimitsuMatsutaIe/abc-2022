/**
 * @file exp_euler.cpp
 * @brief オイラー法で次の微分方程式を解く  x' = a*x
 * つらい
 * @copyright Copyright (c) 2022
 * 
 */

# include <iostream>
# include <fstream>
# include <cmath>
# include <array>
# include <vector>

using namespace std;



/**
 * @brief 微分方程式
 * 
 * @param x 状態変数
 * @param a パラメーター
 * @return double 
 */
double dX(double x, double a){
    return a * x;
}


void euler(int imax, double dt, double x0, double a){
    std::vector<double> t(imax);
    std::vector<double> x(imax);

    for ()
}





int main(){

    // 初期値など
    double x0 = 1.0;
    double a = 1.0;
    double dt = 0.1;
    double T = 5.0;

    int imax = T / dt;  // ループ回数


    return 0;
}