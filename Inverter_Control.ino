#define HIN 9  // High-side MOSFET
#define LIN 10 // Low-side MOSFET (Complementary)

const int pwmResolution = 255; // 8-bit PWM resolution (0-255)
const float freqSin = 50.0;    // Target output frequency (50Hz)
const int samples = 100;       // Number of samples per sine wave cycle

int pwmValues[samples]; // Lookup table for sine wave

void setup() {
  pinMode(HIN, OUTPUT);
  pinMode(LIN, OUTPUT);
  
  // Pre-calculate the sine wave lookup table
  for (int i = 0; i < samples; i++) {
    float angle = 2.0 * PI * i / samples;
    // Shift sine wave to be strictly positive (0 to 255)
    pwmValues[i] = int((sin(angle) + 1.0) * (pwmResolution / 2.0)); 
  }
}

void loop() {
  for (int i = 0; i < samples; i++) {
    // Apply SPWM to HIN
    analogWrite(HIN, pwmValues[i]);
    
    // Apply complementary SPWM to LIN (Inverted)
    analogWrite(LIN, pwmResolution - pwmValues[i]);
    
    // Delay to maintain the 50Hz output frequency
    // Time per sample = 1 / (freqSin * samples)
    delayMicroseconds(int(1e6 / (freqSin * samples)));
  }
}