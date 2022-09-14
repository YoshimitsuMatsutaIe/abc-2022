#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <boost/numeric/odeint.hpp>
#include <eigen3/Eigen/Core>

using std::cout;
using std::endl;

struct System
{
    using state = std::array<double, 3>;  //状態ベクトル

    double p;
    double r;
    double b;

    System(double p, double r, double b)
    {
        this->p = p;
        this->r = r;
        this->b = b;
    }

    void operator()(const state& x, state& dx, double t)
    {
        dx[0] = -this->p*x[0] + this->p*x[1];
        dx[1] = -x[0]*x[2] + this->r*x[0] - x[1];
        dx[2] = x[0]*x[1] - this->b*x[2];
    }
};


struct CSV_Observer
{
    using state = System::state;
    std::ofstream fout;
    CSV_Observer(const std::string& FileName)
    {
        this->fout = std::ofstream(FileName);
    }
    
    void operator()(const state& x, double t)
    {
        fout << t << "," << x[0] << "," << x[1] << "," << x[2] << endl;
    }
};



int main()
{
    cout << "running..." << endl;

    std::string csv_path = "rx.csv";  //結果の保存先

    double time_init = 1.0;
    double time_span = 50.0;
    double time_interval = 0.01;
    System sys(10.0, 28.0, 8.0/3.0);
    System::state state = {0.0, 4.0, 28.0};  //初期値
    
    boost::numeric::odeint::runge_kutta_cash_karp54<System::state> stepper;
    CSV_Observer observer(csv_path);
    boost::numeric::odeint::integrate_const(
        stepper, sys, state, time_init, time_span, time_interval, std::ref(observer)
    );

    cout << "done!" << endl;
}