/******************************************************************************
 *                       Code generated with sympy 1.8                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                          This file is part of 'B'                          *
 ******************************************************************************/
#include "B.h"
#include <math.h>

void B(double M, double l, double m, double *x, double *out_7874428527157509535) {

   out_7874428527157509535[0] = 0;
   out_7874428527157509535[1] = 4*l/(4*M*l + 3*l*m*pow(sin(x[2]), 2) + l*m);
   out_7874428527157509535[2] = 0;
   out_7874428527157509535[3] = -3*l*m*cos(x[2])/(4*M*pow(l, 2)*m + 3*pow(l, 2)*pow(m, 2)*pow(sin(x[2]), 2) + pow(l, 2)*pow(m, 2));

}
