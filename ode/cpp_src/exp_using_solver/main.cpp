/**
 * @file solver_exp.cpp
 * @author your name (you@domain.com)
 * @brief 参考にしました．  https://qiita.com/YukiMiyatake/items/bb16475278ccd93de312#boost-c-with-boost
 * @version 0.1
 * @date 2022-02-07
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
    using state = std::array<double, 1>;
    double alpha;
    System(double alpha_):alpha(alpha_){};

    void operator()(const state& x, state& dx, double t)
    {
        dx[0] = alpha * x[0];
    }
};

struct csv_observer
{
    using state = System::state;
    std::ofstream fout;
    csv_observer(const std::string& FileName) :fout(FileName){};
    void operator()(const state& x, double t)
    {
        fout << t << "," << x[0] << std::endl;
    }
};




int main()
{
    std::cout << "running..." << std::endl;

    //オイラー法
    System sys(1.0);
    System::state State = {1.0};
    boost::numeric::odeint::euler<System::state> Stepper;
    csv_observer Observer("euler.csv");
    boost::numeric::odeint::integrate_const(
        Stepper, sys, State, 0.0, 5.0, 0.05, std::ref(Observer)
    );

    //ルンゲクッタ法
    System sys2(1.0);
    System::state State2 = {1.0};
    boost::numeric::odeint::runge_kutta_cash_karp54<System::state> Stepper2;
    csv_observer Observer2("rk.csv");
    boost::numeric::odeint::integrate_const(
        Stepper2, sys2, State2, 0.0, 5.0, 0.05, std::ref(Observer2)
    );

    std::cout << "done!" << std::endl;
}