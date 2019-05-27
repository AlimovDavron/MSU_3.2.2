//
// Created by davron on 27/05/19.
//
#include <iostream>
#include <cstdio>

#ifdef WIN32
    #define GNUPLOT_NAME "pgnuplot -persist"
#else
    #define GNUPLOT_NAME "gnuplot -persist"
#endif

int draw(int n, int k, double a, double b, double (*Pf)(int n, double a, double b, double x)){
#ifdef WIN32
    FILE *pipe = _popen(GNUPLOT_NAME, "w");
#else
    FILE *pipe = popen(GNUPLOT_NAME, "w");
#endif

    double step = (b - a)/k, left = a, right = b;
    if (pipe != NULL)
    {
        fprintf(pipe, "plot '-' with linespoints\n");
        for(; left < right; left += step)
            fprintf(pipe, "%lf %lf\n", left, Pf(n, a, b, left));


        fprintf(pipe, "%s\n", "e");
        fflush(pipe);

        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cin.get();

#ifdef WIN32
        _pclose(pipe);
#else
        pclose(pipe);
#endif
    }
    else
        std::cout << "Could not open pipe" << std::endl;
}

