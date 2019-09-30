#pragma once

#include <string>
#include <memory>
#include <vector>
#include "bitmap_image.hpp" // From https://github.com/ArashPartow/bitmap/blob/master/bitmap_image.hpp
#include "Magnification.h"
#include "Mandelbrot.h"

namespace fractal {
    class Fractal {
    private:
        int m_width;
        int m_height;
        bitmap_image m_bitmap;
        Magnification m_magnification;
    public:
        Fractal(int width, int height) :
                m_width(width),
                m_height(height),
                m_bitmap(m_width, m_height),
                m_magnification(m_width, m_height) {
            std::cout << "Initializing Fractal Creator..." << std::endl;
            m_bitmap.clear();
            m_magnification.magnify(m_width / 2, m_height / 2, 4.0 / m_width);
        }

        void magnify(int x, int y, double scale) {
            std::cout << "Applying Magnification..." << std::endl;
            m_magnification.magnify(x, y, scale);
        }

        void drawFractal(const std::string &name, const rgb_t colormap[1000]) {
            std::cout << "Calculating Iterations..." << std::endl;
            for (int y = 0; y < m_height; y++) {
                for (int x = 0; x < m_width; x++) {
                    std::pair<double, double> coordinates = m_magnification.getCoordinates(x, y);
                    int iterations = Mandelbrot::getIterations(coordinates.first, coordinates.second);
                    m_bitmap.set_pixel(x, y, colormap[iterations]);
                }
            }
            std::cout << "Writing Bitmap..." << std::endl;
            m_bitmap.save_image(name);
            std::cout << "Finished." << std::endl;
        }
    };
}



