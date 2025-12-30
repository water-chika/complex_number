#pragma once

#include <complex>
#include <format>

namespace complex_number {
    template<class T>
    constexpr bool is_complex = false;
    template<class T>
    concept complex = is_complex<T>;
    template<class T>
    constexpr bool is_complex<std::complex<T>> = true;

    template<class T>
    concept complex_type =
        requires (T t) {
            real(t);
            imag(t);
        };

    auto norm(const complex_type auto& c) {
        return real(c) * real(c) + imag(c) * imag(c);
    }

    auto length_square(const std::integral auto& n) {
        return n*n;
    }
    auto length_square(const std::floating_point auto& f) {
        return f*f;
    }
    auto length_square(const complex_type auto& c) {
        return norm(c);
    }

    template<typename T>
    struct to_complex_struct {
        using type = T;
    };
    template<typename T>
    using to_complex_t = typename to_complex_struct<T>::type;
    template<std::integral T>
    struct to_complex_struct<T> {
        using type = std::complex<T>;
    };
    template<std::floating_point T>
    struct to_complex_struct<T> {
        using type = std::complex<T>;
    };
    template<complex_type T>
    struct to_complex_struct<T> {
        using type = T;
    };
}

template<class T>
concept scalar = std::integral<T> || std::floating_point<T> || complex_number::complex_type<T>;

template<complex_number::complex_type C>
struct std::formatter<C, char> {
    constexpr auto parse(auto& ctx) {
        return ctx.end();
    }

    constexpr auto format(const C& c, auto& ctx) {
        return ctx.out().out;
    }
};


