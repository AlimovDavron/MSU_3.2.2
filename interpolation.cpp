//
// Created by davron on 27/05/19.
//
#include "ChebyshevInterpolation.h"

double *A;

size_t memsize(int n){
    return n* sizeof(double);
}

double T(int n, double x){
    return cos(n*acos(x));
}

double Tab(int n, double x, double a, double b){
    return T(n, (2.*x -(b+a))/(b-a));
}

double Pf(int n, double a, double b, double x){
    int i = 0;
    double result = 0;
    for(i = 0; i < n; i++)
        result += A[i]*Tab(i, x, a, b);
    return result;
}

void Chebyshev_interpolation(int n, double *X, double *FX, double *tmp, int k, double a, double b){
    int i = 0, j = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            tmp[i] += Tab(i, X[j], a, b)*FX[j];
        tmp[i] /= n;
        if(i != 0)
            tmp[i] *= 2.;
    }
    A = tmp;
}


int solve(int n, double *X, double *FX, double *tmp, int k, double a, double b){
    // TODO: implement linear interpolation and getting points from that interpolation
    Chebyshev_interpolation(n, X, FX, tmp, k, a, b);
    return 0;
}