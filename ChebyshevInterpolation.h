//
// Created by davron on 27/05/19.
//

#ifndef CHEBYSHEVINTERPOLATION_CHEBYSHEVINTERPOLATION_H
#define CHEBYSHEVINTERPOLATION_CHEBYSHEVINTERPOLATION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

#ifdef WIN32
    #define GNUPLOT_NAME "pgnuplot -persist"
#else
    #define GNUPLOT_NAME "gnuplot -persist"
#endif

size_t ChebyshevInterpolationCoefficientsMemSize(int);
size_t LinearInterpolationCoefficientsMemSize(int);
size_t tempMemSize(int);

int buildInterpolation(int n, double *X, double *FX, double *ChebyshevInterpolationCoefficients, double *linearInterpolationCoefficients, double*);
double Pf(double, double, double, double*);
double LIf(double, double, double, double *);

class PlotHelper{
private:
#ifdef WIN32
    FILE *pipe = _popen(GNUPLOT_NAME, "w");
#else
    FILE *pipe = popen(GNUPLOT_NAME, "w");
#endif
    int count = 0;
public:
    PlotHelper(){
        fprintf(pipe, "plot '-' with linespoints pointtype 0 title 'Pf(x)'"
                      " , '-' with linespoints pointtype 0  title 'f(x)' \n");
    }
    void draw(int k, double a, double b, double* coefficients, double (*Pf)(double a, double b, double x, double*));
    void close(){
#ifdef WIN32
        _pclose(pipe);
#else
        pclose(pipe);
#endif
    }
};

#endif //CHEBYSHEVINTERPOLATION_CHEBYSHEVINTERPOLATION_H
