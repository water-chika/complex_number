#pragma once
#include <iostream>

namespace complex_number {
    template<class T>
    class r_t_complex_number {
    public:
        r_t_complex_number(T r, T t) : m_r{r}, m_t{t} {}
        static r_t_complex_number from_real_image(T real, T image) {
            return r_t_complex_number{
                sqrt(real*real+image*image),
                atan2(image, real)
            };
        }
        static r_t_complex_number from_radius_angle(T radius, T angle) {
            return r_t_complex_number{
                radius,
                angle
            };
        }
        auto radius() const {
            return m_r;
        }
        auto angle() const {
            return m_t;
        }
    private:
        T m_r; // radius
        T m_t; // angle
    };
    template<class T>
    constexpr bool is_complex<r_t_complex_number<T>> = true;

    template<typename T>
    auto real(const r_t_complex_number<T>& c) {
        return c.radius() * cos(c.angle());
    }
    template<typename T>
    auto image(const r_t_complex_number<T>& c) {
        return c.radius() * sin(c.angle());
    }
    template<typename T>
    auto radius(const r_t_complex_number<T>& c) {
        return c.radius();
    }
    template<typename T>
    auto angle(const r_t_complex_number<T>& c) {
        return c.angle();
    }

    template<typename T>
    auto operator+(const r_t_complex_number<T>& lhs, const r_t_complex_number<T>& rhs) {
        auto r = real(lhs) + real(rhs);
        auto i = image(lhs) + image(rhs);
        return r_t_complex_number<decltype(r)>::from_real_image(r, i);
    }
    template<typename T>
    auto operator-(const r_t_complex_number<T>& lhs, const r_t_complex_number<T>& rhs) {
        auto r= real(lhs) - real(rhs);
        auto i= image(lhs) - image(rhs);
        return r_t_complex_number<decltype(r)>::from_real_image(r, i);
    }
    template<typename T>
    auto operator*(const r_t_complex_number<T>& lhs, const r_t_complex_number<T>& rhs) {
        auto r= radius(lhs)*radius(rhs);
        auto a= angle(lhs) + angle(rhs);
        return r_t_complex_number<decltype(r)>::from_radius_angle(r, a);
    }
    template<typename T>
    auto operator/(const r_t_complex_number<T>& lhs, const r_t_complex_number<T>& rhs) {
        auto r= radius(lhs) * radius(rhs);
        auto a= angle(lhs) - angle(rhs);
        return r_t_complex_number<decltype(r)>::from_radius_angle(r, a);
    }

    template<typename T>
    auto& operator<<(std::ostream& out, const r_t_complex_number<T>& c) {
        return out << radius(c) << "(e^" << angle(c) << "i)";
    }
}
