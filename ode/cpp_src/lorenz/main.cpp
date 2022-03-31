/**
 * @file main.cpp
 * @brief Eigenで書いた例
 * つらい
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include "/usr/include/eigen3/Eigen/Core"


/**
 * @brief ローレンツ方程式のパラメータ
 * 
 */
struct lorenz_param
{
    double p;
    double r;
    double b;
};



/**
 * @brief ローレンツ方程式
 * 
 * @param x 
 * @param x_dot 
 * @param p 
 */
void lorenz(
    const Eigen::Vector3d& x, Eigen::Vector3d& x_dot, struct lorenz_param& p
)
{
    x_dot[0] = -p.p*x[0] + p.p*x[1];
    x_dot[1] = -x[0]*x[2] + p.r*x[0] - x[1];
    x_dot[2] = x[0]*x[1] - p.b*x[2];
}


/**
 * @brief ルンゲクッタ法
 * 
 * @param T 
 * @param dt 
 * @param x0 
 * @param p 
 */
void runge_kutta(double T, double dt, const Eigen::Vector3d& x0, struct lorenz_param p)
{
    
    Eigen::Vector3d x, k1, k2, k3, k4;
    x = x0;

    std::ofstream ofs("rk.csv");
    ofs << "t,x,y,z" << std::endl;
    ofs << 0.0 << "," << x[0] << "," << x[1] << "," << x[2] << std::endl;

    int imax = T / dt;  // ループ回数
    for (int i=0; i<imax; i++){
        lorenz(x, k1, p);
        lorenz(x + dt/2*k1, k2, p);
        lorenz(x + dt/2*k2, k3, p);
        lorenz(x + dt*k3, k4, p);
        x += dt/6 *(k1 + 2*k2 + 2*k3 + k4);
        ofs << dt*i << "," << x[0] << "," << x[1] << "," << x[2] << std::endl;
    }
}


int main()
{
    std::cout << "running..." << std::endl;

    // 初期値など
    Eigen::Vector3d x0 = {0.0, 4.0, 28.0};
    lorenz_param p = {10.0, 28.0, 8/3};
    double dt = 0.01;
    double T = 50.0;


    runge_kutta(T, dt, x0, p);


    std::cout << "done!" << std::endl;
}