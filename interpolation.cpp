//
// Created by davron on 27/05/19.
//
#include "ChebyshevInterpolation.h"



#include <iostream>
using namespace std;

size_t ChebyshevInterpolationCoefficientsMemSize(int n){
    return (n+1)*sizeof(double);
}

size_t LinearInterpolationCoefficientsMemSize(int n){
    return (2*n+1)*sizeof(double);
}

size_t tempMemSize(int n){
    return (2*n)*sizeof(double);
}

double T(int n, double x){
    return cos(n*acos(x));
}

double Tab(int n, double x, double a, double b){
    return T(n, (2.*x -(b+a))/(b-a));
}

double Pf(double a, double b, double x, double *ChebyshevInterpolationCoefficients){
    int i = 0, n;
    int *intPtr = (int*)ChebyshevInterpolationCoefficients;
    n = *intPtr;
    double result = 0;
    for(i = 0; i < n; i++)
        result += ChebyshevInterpolationCoefficients[i+1]*Tab(i, x, a, b);
    return result;
}

double LIf(double a, double b, double x, double *linearInterpolationCoefficients) {
    int i = 0, n;
    int *intPtr = (int *) linearInterpolationCoefficients;
    n = *intPtr;

    if(x < linearInterpolationCoefficients[1])
        return linearInterpolationCoefficients[n+1];
    if(x > linearInterpolationCoefficients[n])
        return linearInterpolationCoefficients[2*n];
    for (i = 0; i < n - 1; i++) {
        if (linearInterpolationCoefficients[i + 1] <= x && x <= linearInterpolationCoefficients[i + 2]) {
            double x1 = linearInterpolationCoefficients[i+1], x2 = linearInterpolationCoefficients[i+2];
            double y1 = linearInterpolationCoefficients[i+1+n], y2 = linearInterpolationCoefficients[i+2+n];
            return (y2-y1)/(x2-x1)*(x-x2) + y2;
        }
    }
}

void Chebyshev_interpolation(int n, double *X, double *FX, double *ChebyshevInterpolationCoefficients){
    int i = 0, j = 0;
    int *intPtr = (int*)ChebyshevInterpolationCoefficients;
    *intPtr = n;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            ChebyshevInterpolationCoefficients[i+1] += Tab(i, X[j], -1, 1)*FX[j];
        ChebyshevInterpolationCoefficients[i+1] /= n;
        if(i != 0)
            ChebyshevInterpolationCoefficients[i+1] *= 2.;
    }
}

void linearInterpolation(int n, const double *X, const double *FX, double *linearInterpolationCoefficients){
    int i = 0, j = 0;
    int *intPtr = (int*)linearInterpolationCoefficients;
    *intPtr = n;
    for(i = 0; i < n; i++)
        linearInterpolationCoefficients[i+1] = X[i];
    for(i = 0; i < n; i++)
        linearInterpolationCoefficients[i+n+1] = FX[i];
}

int buildInterpolation(int n, double *X, double *FX, double *ChebyshevInterpolationCoefficients, double *linearInterpolationCoefficients, double *tmp){
    double a = -1, b = 1;
    int i;

    linearInterpolation(n, X, FX, linearInterpolationCoefficients);

    for(i = 0; i < n; i++){
        tmp[i] = (a+b)/2. + (b-a)*cos(M_PI*(2.*i-1)/2./n)/2.;
        tmp[i+n] = LIf(a, b, tmp[i], linearInterpolationCoefficients);
        double kek = tmp[i+n], kok = tmp[i];
        double keek;
        keek = 10;
    }

    Chebyshev_interpolation(n, tmp, tmp+n, ChebyshevInterpolationCoefficients);

    return 0;
}