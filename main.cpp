#include "Fractal.h"

using namespace fractal;

int main() {
    Fractal fractalCreator(800, 600);

    fractalCreator.magnify(300, 300, 0.65);

    fractalCreator.drawFractal("test.bmp", gray_colormap);
}
