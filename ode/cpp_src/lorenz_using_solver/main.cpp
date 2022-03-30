/**
 * @file lorenz.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include <array>
#include "/usr/include/boost/numeric/odeint.hpp"




struct System
{
    public:
    using state = std::array<double, 3>;
    double p;
    double r;
    double b;
    System(double p_, double r_, double b_):p(p_), r(r_), b(b_){};

    void operator()(const state& x, state& dx, double t)
    {
        dx[0] = -p*x[0] + p*x[1];
        dx[1] = -x[0]*x[2] + r*x[0] - x[1];
        dx[2] = x[0]*x[1] - b*x[2];
    }
};

struct csv_observer
{
    using state = System::state;
    std::ofstream fout;
    csv_observer(const std::string& FileName) :fout(FileName){};
    void operator()(const state& x, double t)
    {
        fout << t << "," << x[0] << "," << x[1] << "," << x[2] << std::endl;
    }
};




int main()
{
    std::cout << "running..." << std::endl;

    //ルンゲクッタ法
    System sys(10.0, 28.0, 8/3);
    System::state State = {0.0, 4.0, 28.0};
    boost::numeric::odeint::runge_kutta_cash_karp54<System::state> Stepper;
    csv_observer Observer("rk.csv");
    boost::numeric::odeint::integrate_const(
        Stepper, sys, State, 0.0, 50.0, 0.01, std::ref(Observer)
    );

    std::cout << "done!" << std::endl;
}