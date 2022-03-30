/**
 * @file main.cpp
 * @brief 
 * つらい
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include "/usr/include/eigen3/Eigen/Core"

//using namespace std;

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
    const Eigen::Vector3d& x, const Eigen::Vector3d& x_dot, const struct lorenz_param& p
)
{
    x_dot[0] = -p.p*x[0] + p.p*x[1];
    x_dot[1] = -x[0]*x[2] + p.r*x[0] - x[1];
    x_dot[2] = x[0]*x[1] - p.b*x[2];
}


void euler(int imax, double dt, Eigen::Vector3d x0, struct lorenz_param p)
{
    Eigen::Vector3d x;
    Eigen::Vector3d x_dot;
    x = x0;
    lorenz(x0, x_dot, p);
    
    for (int i=0; i<imax; i++){
        lorenz(x, x_dot, p);
        x += x_dot * dt;
        std::cout << x << std::endl;
    }
}





int main()
{
    std::cout << "running..." << std::endl;

    // 初期値など
    Eigen::Vector3d x0 = {0.0, 4.0, 28.0};
    lorenz_param p = {10.0, 28.0, 8/3};
    double dt = 0.1;
    double T = 5.0;

    int imax = T / dt;  // ループ回数

    euler(imax, dt, x0, p);


    std::cout << "done!" << std::endl;
}