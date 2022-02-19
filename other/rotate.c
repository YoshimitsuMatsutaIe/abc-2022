#include <math.h>
void rotate(double *x, double theta, double *out)
{
    out[0] = x[0]*cos(theta) - x[1]*sin(theta);
    out[1] = x[0]*sin(theta) + x[1]*cos(theta);
}