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

        // the fake mic
        for (int n = 0; n < N; n++) {
            int t = frame * N + n;
            // this is the sample number since the start 
            samples[n] = std::sin(2 * M_PI * freq * t / fs);
        }

        // the windowing
        for (int n = 0; n < N; n++) {
            in[n] = samples[n] * hann[n];
        }

        std::printf("frame %d:\n", frame);
        std::printf("samples[500] = %6.3f\n", samples[500]);
        std::printf("in[500] = %6.3f\n", in[500]);
        std::printf("samples[5] = %6.3f\n", samples[5]);
        std::printf("in[5] = %6.3f\n", in[5]);
        std::printf("_____________________________\n");

    }

    std::printf("hannSum = %.1f\n", hannSum);
    return 0;
}