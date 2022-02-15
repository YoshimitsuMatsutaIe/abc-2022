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
#include <boost/numeric/odeint.hpp>


using namespace std;
//using namespace boost::numeric::odeint;

struct lv_system
{
public:
    using state = std::array<double, 2>;
public:
    double alpha;
    double beta;
    double gamma;
    double delta;
public:
    lv_system(double alpha_,double beta_,double gamma_,double delta_)
        :alpha(alpha_),beta(beta_),gamma(gamma_),delta(delta_){}

    void operator()(const state& x, state& dx, double t){
       dx[0] = x[0] * (alpha - beta* x[1]);
       dx[1] = - x[1] * (gamma - delta * x[0]);
    }
};






int main(){
    lv_system System(2.0, 3.0, 4.0, 5.0);
    lv_system::state State = {1.0,0.5};

    std::cout << "time=0 " << "x=" << State[0] << " " << "y=" << State[1] << std::endl;

    //オイラー法を使ってみる
    boost::numeric::odeint::euler<lv_system::state> Stepper;

    //time = 0 -> 5まで、時間発展を計算してみる
    boost::numeric::odeint::integrate_const(
        Stepper, System, State, 0.0, 5.0, 0.05
    );

    std::cout << "time=5 " << "x=" << State[0] << " " << "y=" << State[1] << std::endl;
}