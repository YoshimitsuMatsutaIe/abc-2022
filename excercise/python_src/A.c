/******************************************************************************
 *                       Code generated with sympy 1.8                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                          This file is part of 'A'                          *
 ******************************************************************************/
#include "A.h"
#include <math.h>

void A(double D_theta, double D_x, double M, double g, double l, double m, double *x, double *out_1139776175234781779) {

   out_1139776175234781779[0] = 0;
   out_1139776175234781779[1] = 1;
   out_1139776175234781779[2] = 0;
   out_1139776175234781779[3] = 0;
   out_1139776175234781779[4] = 0;
   out_1139776175234781779[5] = -4*D_x/(4*M + 3*m*pow(sin(x[2]), 2) + m);
   out_1139776175234781779[6] = -6*m*(3*D_theta*cos(x[2])*x[3] - 4*D_x*l*x[1] - 3.0/2.0*g*l*m*sin(2*x[2]) + 4*pow(l, 2)*m*sin(x[2])*pow(x[3], 2))*sin(x[2])*cos(x[2])/(l*pow(4*M + 3*m*pow(sin(x[2]), 2) + m, 2)) + (-3*D_theta*sin(x[2])*x[3] - 3*g*l*m*cos(2*x[2]) + 4*pow(l, 2)*m*cos(x[2])*pow(x[3], 2))/(l*(4*M + 3*m*pow(sin(x[2]), 2) + m));
   out_1139776175234781779[7] = (3*D_theta*cos(x[2]) + 8*pow(l, 2)*m*sin(x[2])*x[3])/(l*(4*M + 3*m*pow(sin(x[2]), 2) + m));
   out_1139776175234781779[8] = 0;
   out_1139776175234781779[9] = 0;
   out_1139776175234781779[10] = 0;
   out_1139776175234781779[11] = 1;
   out_1139776175234781779[12] = 0;
   out_1139776175234781779[13] = 3*D_x*cos(x[2])/(l*(4*M + 3*m*pow(sin(x[2]), 2) + m));
   out_1139776175234781779[14] = -18*(-D_theta*M*x[3] - D_theta*m*x[3] + D_x*l*m*cos(x[2])*x[1] + M*g*l*m*sin(x[2]) + g*l*pow(m, 2)*sin(x[2]) - 1.0/2.0*pow(l, 2)*pow(m, 2)*sin(2*x[2])*pow(x[3], 2))*sin(x[2])*cos(x[2])/(pow(l, 2)*pow(4*M + 3*m*pow(sin(x[2]), 2) + m, 2)) + 3*(-D_x*l*m*sin(x[2])*x[1] + M*g*l*m*cos(x[2]) + g*l*pow(m, 2)*cos(x[2]) - pow(l, 2)*pow(m, 2)*cos(2*x[2])*pow(x[3], 2))/(pow(l, 2)*m*(4*M + 3*m*pow(sin(x[2]), 2) + m));
   out_1139776175234781779[15] = 3*(-D_theta*M - D_theta*m - pow(l, 2)*pow(m, 2)*sin(2*x[2])*x[3])/(pow(l, 2)*m*(4*M + 3*m*pow(sin(x[2]), 2) + m));

}
