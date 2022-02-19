#include <math.h>
double sigmoid(double x, double a)
{
    return 1 / (1 + exp(-a*x));
}