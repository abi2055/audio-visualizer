#include <iostream>
#include <vector>

// this code is not runnable, only for example purposes
int main() {
    const int N = 1024;

    // calculating the window to then be applied to the samples
    std::vector<double> hann(N);
    double hannSum = 0;
    for (int n = 0; n < N; n++) {
        hann[n] = 0.5 * (1 - std::cos(2 * M_PI * n / (N - 1)));
        hannSum += hann[n];
    }

    // pretend this is the main app loop
    while (appIsOpen) {

        // applying that window to the freshly generated samples when its running
        for (int n = 0; n < N; n++)
            in[n] = samples[n] * hann[n];
    }
}