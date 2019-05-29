//
// Created by davron on 27/05/19.
//
#include <iostream>
#include <cstdio>
#include "ChebyshevInterpolation.h"

#ifdef WIN32
    #define GNUPLOT_NAME "pgnuplot -persist"
#else
    #define GNUPLOT_NAME "gnuplot -persist"
#endif

void PlotHelper::draw(int k, double a, double b, double* coefficients, double (*Pf)(double a, double b, double x, double*)){
    count++;
    double step = (b - a)/k, left = a, right = b;
    for(; left < right; left += step)
        fprintf(pipe, "%lf %lf\n", left, Pf(a, b, left, coefficients));


    fprintf(pipe, "%s\n", "e");
    fflush(pipe);

    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    if(count == 2){
        close();
    }
}

