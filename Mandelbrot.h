#pragma once

#include <complex>

namespace fractal {
    struct Mandelbrot {
        static const int MAX_ITERATIONS = 1000;

        static int getIterations(double x, double y) {
            std::complex<double> z = 0;
            std::complex<double> c(x, y);

            for (int i = 0; i < MAX_ITERATIONS; i++) {
                z = pow(z, 2) + c;
//                z = pow(std::conj(z), d) + c;    // Multibrot set (d = 3, 4, 5, etc.)
//                z = pow(std::conj(z), 2) + c;    // Tricorn set

                if (abs(z) > 2) {
                    auto index = (unsigned int) (MAX_ITERATIONS * log2(1.75 + i - log2(log2(std::abs(z)))) /
                                                 log2(MAX_ITERATIONS));
                    return index;
                }
            }

            return MAX_ITERATIONS;
        }
    };
}
