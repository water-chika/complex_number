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

    auto real(const r_t_complex_number<auto>& c) {
        return c.radius() * cos(c.angle());
    }
    auto image(const r_t_complex_number<auto>& c) {
        return c.radius() * sin(c.angle());
    }
    auto radius(const r_t_complex_number<auto>& c) {
        return c.radius();
    }
    auto angle(const r_t_complex_number<auto>& c) {
        return c.angle();
    }

    auto operator+(const r_t_complex_number<auto>& lhs, const r_t_complex_number<auto>& rhs) {
        auto r = real(lhs) + real(rhs);
        auto i = image(lhs) + image(rhs);
        return r_t_complex_number<typeof(r)>::from_real_image(r, i);
    }
    auto operator-(const r_t_complex_number<auto>& lhs, const r_t_complex_number<auto>& rhs) {
        auto r= real(lhs) - real(rhs);
        auto i= image(lhs) - image(rhs);
        return r_t_complex_number<typeof(r)>::from_real_image(r, i);
    }
    auto operator*(const r_t_complex_number<auto>& lhs, const r_t_complex_number<auto>& rhs) {
        auto r= radius(lhs)*radius(rhs);
        auto a= angle(lhs) + angle(rhs);
        return r_t_complex_number<typeof(r)>::from_radius_angle(r, a);
    }
    auto operator/(const r_t_complex_number<auto>& lhs, const r_t_complex_number<auto>& rhs) {
        auto r= radius(lhs) * radius(rhs);
        auto a= angle(lhs) - angle(rhs);
        return r_t_complex_number<typeof(r)>::from_radius_angle(r, a);
    }

    auto& operator<<(std::ostream& out, const r_t_complex_number<auto>& c) {
        return out << radius(c) << "(e^" << angle(c) << "i)";
    }
}
