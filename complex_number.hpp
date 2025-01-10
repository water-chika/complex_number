#pragma once

#include <complex>

namespace complex_number {
    template<class T>
    constexpr bool is_complex = false;
    template<class T>
    concept complex = is_complex<T>;
    template<class T>
    constexpr bool is_complex<std::complex<T>> = true;
}
