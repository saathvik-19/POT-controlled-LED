# POT-controlled-LED
# Arduino Uno project that smoothly changes an LED’s brightness with a potentiometer, using PWM.


**Author:** M M Saathvik  
**Reg No:** 26BVD0145  
**Course:** VLSI Design & Technology  

---

## 📌 Project Overview
This project demonstrates dynamic brightness control of an LED using an analog potentiometer connected to an Arduino Uno. By leveraging Pulse Width Modulation (PWM), the system scales a 10-bit analog voltage input into an 8-bit signal to vary power delivery to the LED seamlessly.

---

## 📑 Aim
The aim of this project was to make a control system that could control the brightness of an LED using a potentiometer and Arduino Uno.


---

## 🛠️ Components Required
| Component | Quantity | Description / Specification |
| :--- | :---: | :--- |
| **Arduino Uno** | 1 | Microcontroller board based on ATmega328P |
| **Potentiometer** | 1 | 10kΩ Rotary Variable Resistor |
| **LED** | 1 | 5mm Blue LED |
| **Resistor** | 1 | 220 Ω Current-Limiting Resistor |
| **Breadboard** | 1 | Standard Solderless Breadboard |
| **Jumper Wires**| Assorted | Male-to-Male jumper cables |

---

## ⚙️ Circuit Connections

| Component Pin | Arduino Pin | Purpose / Function |
| :--- | :--- | :--- |
| **Potentiometer Left Terminal** | `GND` | Ground Reference |
| **Potentiometer Middle Wiper** | `A0` | Analog Input Signal (0–5V) |
| **Potentiometer Right Terminal**| `5V` | 5V Power Reference |
| **LED Anode (+)** | `D9` (via 220Ω Resistor) | PWM Output Signal |
| **LED Cathode (-)** | `GND` | Ground Return |

---

## 🔬 How It Works

1. **Analog Sensing:** The potentiometer forms a voltage divider across $5\text{V}$ and $\text{GND}$. Rotating the knob changes the wiper voltage between $0\text{V}$ and $5\text{V}$.
2. **Analog-to-Digital Conversion (ADC):** Pin `A0` reads this variable analog voltage using the Arduino's 10-bit ADC, returning an integer value from `0` ($0\text{V}$) to `1023` ($5\text{V}$).
3. **Signal Mapping:** The code scales the ADC range `0–1023` to an 8-bit PWM range `0–255` using the `map()` function:
   $$\text{brightness} = \text{map}(\text{potValue}, 0, 1023, 0, 255)$$
4. **PWM Duty Cycle Output:** Pin `D9` outputs a PWM signal where the duty cycle corresponds to the mapped value. Varying the high-state duty cycle adjusts the average output power delivered to the LED, producing a smooth dimming effect.

---

## 💻 Source Code

The primary sketch file is [`pot_led_dimmer.ino`](arduino_code_file.cpp).

```cpp
int potPin = A0;      
int ledPin = 9;      
int potValue = 0;     
int brightness = 0;   

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);  
  brightness = map(potValue, 0, 1023, 0, 255);  
  analogWrite(ledPin, brightness);  
  
  Serial.print("Potentiometer Value: "); 
  Serial.print(potValue);  
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);  
  
  delay(100);  
}
```

---

## 📊 Experimental Results

### Serial Monitor Output at Key Knob Positions:

* **0% Rotation (Min):** `Potentiometer Value: 0 | LED Brightness: 0` (LED Off)
* **50% Rotation (Mid):** `Potentiometer Value: 511 | LED Brightness: 127` (Medium Brightness)
* **100% Rotation (Max):** `Potentiometer Value: 1023 | LED Brightness: 255` (Full Brightness)

---

## 🔗 Project Links & Documentation

* **Tinkercad Simulation:** (https://www.tinkercad.com/things/evwdHRRH919-pot-led-dimmer))
* **Project Documentation:** ([https://docs.google.com/document/d/1M03HIuds0BqCFm87-axYqyBpWJdrF8xmSoTS4mWNbrI/edit?usp=sharing]).

---

## 💡 Conclusion
The system successfully provides continuous, analog-like control over LED brightness using a digital PWM output on pin 9, proving the effective utilization of ADC reading and signal transformation in microcontrollers.
