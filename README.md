#  Arduino Single-Phase Inverter with SPWM Control

A comprehensive design and simulation of a solar-powered single-phase inverter capable of converting 18V DC to 220V AC to supply domestic loads. The system utilizes an Arduino Uno to generate precise Pulse Width Modulation (PWM) signals to drive an H-Bridge of MOSFETs, featuring advanced Sinusoidal Pulse Width Modulation (SPWM) for high-quality AC output.

![Arduino](https://img.shields.io/badge/Hardware-Arduino_UNO-00979D)
![C++](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Power Electronics](https://img.shields.io/badge/Domain-Power_Electronics-orange)
![Simulation](https://img.shields.io/badge/Tool-Proteus_ISIS-green)

##  About the Project
This project was developed as a Final Year Project (PFE) for the DUT in Electrical Engineering. The primary objective is to design an autonomous off-grid inverter powered by an 18V solar battery pack, capable of delivering 220V AC at 50Hz to power a 100W resistive load. 

The project covers the full engineering cycle: theoretical study of power switches (MOSFETs, IGBTs), functional analysis of the H-Bridge topology, mathematical dimensioning of components, and simulation of three distinct control strategies.

##  System Specifications
- **Input Voltage:** 18V DC (Solar Battery Pack)
- **Output Voltage:** 220V AC (via step-up transformer)
- **Output Frequency:** 50 Hz
- **Load Capacity:** 100W (Resistive)
- **Power Stage:** Full H-Bridge using IRFP460 MOSFETs driven by IR2110 Gate Drivers.

##  Control Strategies Implemented
The project explores and compares three digital control methods generated via Arduino:

1. **Symmetrical PWM:** Basic square wave generation with a 50% duty cycle. Simple but produces high harmonic distortion.
2. **Phase-Shifted PWM (with Dead-Time):** Introduces a critical safety delay (dead-time) between the switching of complementary MOSFETs in the same H-bridge leg to prevent shoot-through short circuits.
3. **Sinusoidal PWM (SPWM):** The most advanced method. Modulates the pulse width according to a sinusoidal reference table. When filtered, this produces a near-perfect 50Hz sine wave, minimizing Total Harmonic Distortion (THD).

##  Mathematical Dimensioning
- **Input Current:** $I_{in} = P_{out} / (\eta \times V_{in}) = 100W / (0.85 \times 18V) \approx 6.56A$
- **Transformer Ratio:** $N = 220V / 18V \approx 12.2$
- **Battery Sizing:** For 2 hours of autonomy at 6.56A $\rightarrow$ Minimum 14Ah capacity.

##  Project Structure
Arduino-Single-Phase-Inverter-SPWM/
│
├── Inverter_Control.ino           
├── commande MLI.png               
└── README.md

## Future Improvements
Hardware Implementation: Build physical PCB prototype with proper heat sinking
MPPT Integration: Implement Maximum Power Point Tracking for solar optimization
High-Frequency SPWM: Use Arduino Timer1 registers to increase PWM carrier frequency from ~490Hz to 20kHz for smaller, cheaper LC filters
LCD Display: Add real-time monitoring of voltage, current, and frequency
Protection Circuits: Over-current, over-voltage, and thermal protection

## Authors
Khadija Stitou & Aymane Taleb Ali
DUT Electrical Engineering (Electrotechnics) – EST Meknès, 2025
Engineering Students in Intelligent Embedded Systems & Telecommunications – FST Errachidia
Khadija's LinkedIn: (https://www.linkedin.com/in/khadija-stitou-b42792293)
