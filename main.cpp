#include "ChebyshevInterpolation.h"
#include <iostream>
using namespace std;
int validateFile(char* filename)
{
    FILE *f = fopen(filename, "rb");
    return f != NULL;
}

int readInputData(char *inputFile, int *p, double** X, double** FX, int *n, double *a, double *b, int *k)
{
    int i, checkInput;
    FILE *in = fopen(inputFile, "r");

    checkInput = fscanf(in, "%d", p);
    if(checkInput == EOF)
        return 5;
    if(checkInput == 0)
        return 6;

    checkInput = fscanf(in, "%d", n);
    if(checkInput == EOF)
        return 5;
    if(checkInput == 0)
        return 6;

    if(*n <= 0)
        return 6;

    *X = static_cast<double *>(malloc((*n) * sizeof(double)));
    *FX = static_cast<double *>(malloc((*n) * sizeof(double)));

    for(i = 0; i < (*n); i++) {
        checkInput = fscanf(in, "%lf", (*X + i));
        if (checkInput == EOF)
            return 7;
        if(checkInput == 0)
            return 8;

        checkInput = fscanf(in, "%lf", (*FX+i));
        if (checkInput == EOF)
            return 9;
        if(checkInput == 0)
            return 10;
    }

    checkInput = fscanf(in, "%lf", a);
    if(checkInput == EOF)
        return 5;
    if(checkInput == 0)
        return 6;

    checkInput = fscanf(in, "%lf", b);
    if(checkInput == EOF)
        return 5;
    if(checkInput == 0)
        return 6;

    checkInput = fscanf(in, "%d", k);
    if(checkInput == EOF)
        return 5;
    if(checkInput == 0)
        return 6;

    return 0;
}

int main(int argc, char* argv[]) {
    int n, k, p;
    double *X, *FX, *tmp, a, b, *result;
    char* inputFile = "input.txt";
    char* outputFile = "output.txt";
    if(argc > 1){
        inputFile = argv[1];
        if(argc > 2) {
            outputFile = argv[2];
        }
    }

    if (!validateFile(inputFile)) {
        printf("ValidationError: There is no such file.\n");
        return 3;
    }

    switch (readInputData(inputFile, &p, &X, &FX, &n, &a, &b, &k))
    {
        default:
            break;
    }
    cout << n << endl;
    for(int i = 0; i < n; i++){
        cout << X[i] << " " << FX[i] << endl;
    }
    tmp = static_cast<double *>(malloc(memsize(n)));
    Chebyshev_interpolation(n, X, FX, tmp, k, a, b);
    draw(n, k, a, b, Pf);


    return 0;
}