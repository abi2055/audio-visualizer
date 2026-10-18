#include <iostream>
#include <complex>

int main() {

    std::complex<float> z(3.0f, 4.0f);
    // how complex numbers are used
    float magnitude = std::abs(z);
    float phase = std::arg(z);

    std::cout << "Magnitude: " << magnitude << std::endl;
    std::cout << "Phase: " << phase << std::endl;

    return 0;
}