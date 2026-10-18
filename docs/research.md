## Fourier Transform Intuition 
The Fourier transform is a tool for decomposing a complex wave/signal into simples sinusoids in the form you probably learned in highschool: A·cos(2πft + φ). These deconstructed "simpler" waves can be added together to make the original wave. This works because any reasonable signal can be expressed as different waves of different amplitudes, frequencies and phases. In actual practice, signals need to satisfy certain conditions for the fourier transform to be effective, but thats's out of scope for now. 

## Sampling and Aliasing 
sound is air pressure. In order for a microphone to capture that sound it represents it as a voltage, a computer cant record a continous wave and instead records small instants over time.

### Sample: 
one measurement, a float to represent the sound at that instance

### sample rate (fs): 
how many measurements per second. A rate of 48000 Hz is one reading every 1/48000s = 0.02ms 

### sample index / time : 
t = n / fs (the same calculation above)

### Turning a sine wave into samples: 
a continous sine wave or tone in the form x(t) = sin(2πft) -> x[n] = sin(2πfn/fs)

### One Rule: Nyquist
To capture a frequency, you need at least 2 samples per cycle which makes logical sense since how do you even describe the sound with only 1. You need a sample roughly at the peak and trough. So that means the highest frequency you can represent is f_max = fs / 2

### Aliasing
Aliasing is the phenomena when the frequency goes above that max (fs/2). That sound doesnt dissapear. This is not wanted needless to say, makes the sound sci fi. The samples line up with a lower fake frequency instead:

f_alias = |f - fs * round(f / fs)| 

### relation to audio viz: Port Audio
PortAudio gives you *buffers*. I won't get samples one at a time, I'll get it in chunks of N samples per call: duration = N / fs

Example: N = 1024 samples, 48 Khz gives use 1024 / 48 = 21ms -> 47s, you would get 47 samples per chunk per second 

## Complex Numbers (Review)
A simple number can describe how big something is. When the FFT (fourier transform) looks at a frequency in the audio, it needs two things: how strong that frequency is as well as where it is in the cycle (the phase). A complex number is just an easy way to connect those two packing into one number. 

### How it looks
A *complex number* is written as: z = a + b*i 
- a is the real part and b is the imaginary part
- i is defined as i^2 = -1

Imagine a and b as a coordinate. As an arrow on a 2D plane, from the origin to the point (a,b). The horizontal (x or a) axis is real, and the (y or b) is imaginary. 

*magnitude of the arrow*: |z| = sqrt(a^2 + b^2)

for example - 3 + 4i is 9 + 15 = sqrt(25) = 5

*phase (angle) - which way the arrow points*: θ = a*tan2(b, a) = 53 degrees (for the above example)

### Euler's formula: arrows as angles
An arrow of length 1 at angle θ can be wrriten as: e^(iθ) = cos(θ) + i*sin(θ)

and z = r * e^(iθ)

### connecting to sound 
Let θ grow with time: e^(i·2π·f·t) - This represents an arrow spinning in a circle, f times per second

If you only take that arrows horizontal position. That shadow traces out cos(2πft), a sine wave. So a sine wave is pretty much just a spinning arrow. That's why fft speaks in complex numbers. 

### Math Hint
when you multiple two complex numbers
- the magnitudes multiple 
- the angles add up
- (r₁·e^(iθ₁)) · (r₂·e^(iθ₂)) = (r₁·r₂) · e^(i(θ₁+θ₂))

This is the big trick inside the DFT: to test whether your signal contains frequency f, multiply it by an arrow spinning backwards at f, then add it up.
- if f is in the signal, they cancel out. The arrows combine providing a bigger magnitude
- if f is not in the signal, the magnitude ends up being near 0

## DIscrete Fourier Transform (DFT)