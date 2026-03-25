# Automatic-Hand-Sanitizer-Dispenser
# Automatic Sanitizer Dispenser
### Arduino Nano + HC-SR04 Ultrasonic Sensor

---

## Components Required

| Component          | Quantity |
|--------------------|----------|
| Arduino Nano       | 1        |
| HC-SR04 Ultrasonic | 1        |
| 5V Relay Module    | 1        |
| Mini Water Pump    | 1        |
| 5V Power Supply    | 1        |
| Jumper Wires       | Several  |

---

## Pin Connections

### HC-SR04 Ultrasonic Sensor → Arduino Nano
```
HC-SR04 VCC   →  Arduino 5V
HC-SR04 GND   →  Arduino GND
HC-SR04 TRIG  →  Arduino D9
HC-SR04 ECHO  →  Arduino D10
```

### Relay Module → Arduino Nano
```
Relay VCC  →  Arduino 5V
Relay GND  →  Arduino GND
Relay IN   →  Arduino D7
```

### Pump → Relay
```
Relay COM  →  Positive wire of Pump
Relay NO   →  Positive of Power Supply
Pump GND   →  Negative of Power Supply
```

---

## Wiring Diagram (Text)

```
  [5V Supply]────────────────────────────────┐
       │                                     │
  [Arduino Nano]                        [Relay NO]
  5V ──┬── HC-SR04 VCC                       │
  GND ─┼── HC-SR04 GND               [Relay COM]──[PUMP +]
  D9 ──┼── HC-SR04 TRIG                      │
  D10 ─┼── HC-SR04 ECHO              [PUMP GND]──[GND Supply]
  5V ──┼── Relay VCC
  GND ─┼── Relay GND
  D7 ──┴── Relay IN
```

---

## How It Works

1. Ultrasonic sensor continuously measures distance.
2. If a hand is detected **within 10 cm**, the relay triggers.
3. The pump runs for **2 seconds** and then turns OFF automatically.
4. A **2 second cooldown** prevents immediate re-triggering.
5. Ready for the next detection after cooldown.

---

## Adjustable Settings (in the .ino file)

```cpp
const int  DETECT_DISTANCE_CM = 10;   // Change detection range
const long PUMP_ON_TIME_MS     = 2000; // Change pump run time (ms)
const long COOLDOWN_MS         = 2000; // Change cooldown time (ms)
```

---

## Upload Instructions

1. Open **Arduino IDE**
2. Go to `File → Open` and select `AutoSanitizerDispenser.ino`
3. Select Board: `Tools → Board → Arduino Nano`
4. Select Processor: `Tools → Processor → ATmega328P (Old Bootloader)` *(if upload fails, try this)*
5. Select the correct COM Port under `Tools → Port`
6. Click **Upload**

---

## Serial Monitor

Open Serial Monitor at **9600 baud** to see distance readings and status messages in real time.

---

*Project: Automatic Sanitizer Dispenser | Arduino Nano*
