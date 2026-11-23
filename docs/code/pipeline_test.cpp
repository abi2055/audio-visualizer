#include <iostream>
#include <vector>
#include <cmath>

int main() {
    const int N = 1024; 
    // the buffer size
    const double fs = 48000.0;
    // sample rate
    const double freq = 1000.0;
    // fake test tone

    // building the hann window is the first step
    std::vector<double> hann(N);
    double hannSum = 0;
    for (int i = 0; i < N; i++) {
        hann[i] = 0.5 * (1 - std::cos(2 * M_PI * i / (N - 1)));
        hannSum += hann[i];
        // fade in fade out logic 
    }

    std::vector<double> samples(N);
    // the raw samples

    std::vector<double> in(N); 
    // this is the windowed sound

    const int frames = 5;
    // for this examples, we're running for 5 frames

    for (int frame = 0; frame < frames; frame++) {
        
    }

    return 0;
}