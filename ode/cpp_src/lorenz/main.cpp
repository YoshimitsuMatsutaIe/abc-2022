#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Core>


using Eigen::VectorXd;


struct Lorenz
{
    double p;
    double r;
    double b;

    Lorenz(double p, double r, double b)
    {
        this->p = p;
        this->r = r;
        this->b = b;
    }

    void operator()(const VectorXd& x, VectorXd& x_dot)
    {
        x_dot(0) = -this->p*x(0) + this->p*x(1);
        x_dot(1) = -x(0)*x(2) + this->r*x(0) - x(1);
        x_dot(2) = x(0)*x(1) - this->b*x(2);
    }
};



int main()
{
    using std::cout;
    using std::endl;
    cout << "running..." << endl;

    const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ",", "\n");

    VectorXd x(3);  //状態変数
    x << 0.0, 4.0, 28.0;  //初期値

    auto lorenz = Lorenz(10.0, 28.0, 8/3);
    
    const double dt = 0.01;
    const double time_span = 50.0;

    VectorXd k1(3), k2(3), k3(3), k4(3);

    std::ofstream ofs("rk.csv");  //結果のcsvファイル
    ofs << "t,x,y,z" << endl;  //ヘッダ作成
    ofs << 0.0 << "," << x.transpose().format(CSVFormat) << endl;  //初期値書き込み

    const int imax = time_span / dt;  // ループ回数
    for (int i=0; i<imax; ++i){
        lorenz(x, k1);
        lorenz(x + 0.5*dt*k1, k2);
        lorenz(x + 0.5*dt*k2, k3);
        lorenz(x + dt*k3, k4);
        x += dt/6.0 * (k1 + 2.0*k2 + 2.0*k3 + k4);
        ofs << dt*i << "," << x.transpose().format(CSVFormat) << endl;
    }

    cout << "done!" << endl;
}