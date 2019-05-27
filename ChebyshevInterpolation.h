//
// Created by davron on 27/05/19.
//

#ifndef CHEBYSHEVINTERPOLATION_CHEBYSHEVINTERPOLATION_H
#define CHEBYSHEVINTERPOLATION_CHEBYSHEVINTERPOLATION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

size_t memsize(int n);
void Chebyshev_interpolation(int n, double *X, double *FX, double *tmp, int k, double a, double b);
double Pf(int n, double a, double b, double x);
int draw(int n, int k, double a, double b, double (*Pf)(int, double, double, double));

#endif //CHEBYSHEVINTERPOLATION_CHEBYSHEVINTERPOLATION_H
