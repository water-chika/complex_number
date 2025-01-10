#include <complex_number.hpp>
#include <r_t_complex_number_impl.hpp>
#include <complex>
#include <iostream>

using complex_number::r_t_complex_number;

int main() {
    std::cout << complex_number::is_complex<std::complex<float>> << std::endl;
    std::cout << complex_number::is_complex<float> << std::endl;
    auto a = r_t_complex_number<float>::from_real_image(1,1);
    auto b = r_t_complex_number<float>::from_real_image(0.2,0.3);
    auto c = a + b;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a+b = " << a+b << std::endl;
    std::cout << "a-b = " << a-b << std::endl;
    std::cout << "a*b = " << a*b << std::endl;
    std::cout << "a/b = " << a/b << std::endl;
    return 0;
}
