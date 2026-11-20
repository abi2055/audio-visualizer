# Design Architecture and Flow 
1) get samples
2) Hann window it (the squishing)
3) FFT
4) get amplitude heights
5) get the ratios, the db
6) log bands 
7) smoothing 
8) display 

# Folder structure 
audio-visualizer/
├── CMakeLists.txt          
├── README.md
├── design.md           -> design knowledge
├── docs/                   
├── src/
│   ├── main.cpp           
│   ├── Config.h           -> this would contain hard coded values
│   ├── audio/
│   │   ├── AudioCapture.h/.cpp    
│   │   └── RingBuffer.h           
│   ├── dsp/
│   │   ├── DspMath.h/.cpp         
│   │   └── SpectrumAnalyzer.h/.cpp 
│   └── render/
│       └── Renderer.h/.cpp        
├── tests/
│   └── test_dsp.cpp        
└── third_party/            