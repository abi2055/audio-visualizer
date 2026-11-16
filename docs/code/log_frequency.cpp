// This code is non compilable 
// STARTUP (once)
const int B = 30;
const double fMin = 40.0, fMax = 20000.0;
std::vector<int> startBin(B), endBin(B);

for (int i = 0; i < B; i++) {
    double fLo = fMin * std::pow(fMax / fMin, (double)i / B);       
    // bar's low edge (Hz)
    double fHi = fMin * std::pow(fMax / fMin, (double)(i + 1) / B); 
    // bar's high edge (Hz)
    startBin[i] = (int)std::ceil(fLo * N / fs);       
    // first bin inside the bar
    endBin[i]   = (int)std::ceil(fHi * N / fs) - 1;   
    // last bin inside the bar
    if (endBin[i] < startBin[i])                      
    // no bins inside?
        endBin[i] = startBin[i];                      
        // borrow the nearest one
}

// MAIN LOOP (every frame): one height per bar
for (int i = 0; i < B; i++) {
    double peak = 0.0;
    for (int k = startBin[i]; k <= endBin[i]; k++)
        peak = std::max(peak, amp[k]);    // biggest bin in this bar
    barHeight[i] = toHeight(peak);        // this function comes from the last lesson, for decibal clamping
}
// for each bar we're finding its loudest bin, then converting that to a height so how tlal that bar should be 