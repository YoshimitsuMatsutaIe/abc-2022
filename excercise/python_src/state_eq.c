/******************************************************************************
 *                       Code generated with sympy 1.8                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                      This file is part of 'state_eq'                       *
 ******************************************************************************/
#include "state_eq.h"
#include <math.h>

void state_eq(double D_theta, double D_x, double M, double g, double l, double m, double u, double *x, double *out_3232618913704681887) {

   out_3232618913704681887[0] = x[1];
   out_3232618913704681887[1] = 3*D_theta*cos(x[2])*x[3]/(4*M*l + 3*l*m*pow(sin(x[2]), 2) + l*m) - 4*D_x*l*x[1]/(4*M*l + 3*l*m*pow(sin(x[2]), 2) + l*m) - 3*g*l*m*sin(2*x[2])/(8*M*l + 6*l*m*pow(sin(x[2]), 2) + 2*l*m) + 4*pow(l, 2)*m*sin(x[2])*pow(x[3], 2)/(4*M*l + 3*l*m*pow(sin(x[2]), 2) + l*m) + 4*l*u/(4*M*l + 3*l*m*pow(sin(x[2]), 2) + l*m);
   out_3232618913704681887[2] = x[3];
   out_3232618913704681887[3] = -3*D_theta*M*x[3]/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2)) - 3*D_theta*m*x[3]/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2)) + 3*D_x*l*m*cos(x[2])*x[1]/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2)) + 3*M*g*l*m*sin(x[2])/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2)) + 3*g*l*pow(m, 2)*sin(x[2])/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2)) - 3*pow(l, 2)*pow(m, 2)*sin(2*x[2])*pow(x[3], 2)/(8*M*pow(l, 2)*m + 6*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + 2*pow(l, 2)*pow(m, 2)) - 3*l*m*u*cos(x[2])/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2));

}
