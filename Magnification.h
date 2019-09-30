#pragma once

#include <vector>
#include <utility>

namespace fractal {
    struct Zoom {
        int x{0};
        int y{0};
        double scale{0.0};

        Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};
    };

    class Magnification {
    private:
        double m_xCenter{0};
        double m_yCenter{0};
        double m_scale{1.0};
        int m_width{0};
        int m_height{0};
        std::vector<Zoom> m_magnifications;
    public:
        Magnification(int width, int height) : m_width(width), m_height(height) {}

        void magnify(int x, int y, double scale) {
            Zoom zoom(x, y, scale);
            m_magnifications.push_back(zoom);

            m_xCenter += (zoom.x - m_width / 2.0) * m_scale;
            m_yCenter += -(zoom.y - m_height / 2.0) * m_scale;
            m_scale *= zoom.scale;
        }

        std::pair<double, double> getCoordinates(int x, int y) {
            double xFractal = (x - m_width / 2.0) * m_scale + m_xCenter;
            double yFractal = (y - m_height / 2.0) * m_scale + m_yCenter;

            return std::pair<double, double>(xFractal, yFractal);
        }
    };
}
