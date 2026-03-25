# Automatic-Hand-Sanitizer-Dispenser
# 🤲 Contactless Automatic Hand Sanitizer Dispenser
### 🔧 Using Arduino Nano & HC-SR04 Ultrasonic Sensor

> 🚫🖐️ No Touch. No Germs. Just Clean Hands!

---

## 📋 Table of Contents
- [About the Project](#-about-the-project)
- [Components Required](#-components-required)
- [Pin Connections](#-pin-connections)
- [Wiring Diagram](#-wiring-diagram)
- [How It Works](#-how-it-works)
- [Code Settings](#-adjustable-settings)
- [Upload Instructions](#-upload-instructions)
- [Serial Monitor](#-serial-monitor)

---

## 💡 About the Project

This project automatically dispenses sanitizer when a hand is detected within **10 cm** of the ultrasonic sensor. The pump runs for **2 seconds** and then turns OFF — no touching required! Built using an **Arduino Nano** and **HC-SR04** ultrasonic sensor.

---

## 🛒 Components Required

| # | Component              | Quantity |
|---|------------------------|----------|
| 1 | 🖥️ Arduino Nano         | 1        |
| 2 | 📡 HC-SR04 Ultrasonic  | 1        |
| 3 | ⚡ 5V Relay Module      | 1        |
| 4 | 💧 Mini Water Pump      | 1        |
| 5 | 🔌 5V Power Supply      | 1        |
| 6 | 🔗 Jumper Wires         | Several  |

---

## 🔌 Pin Connections

### 📡 HC-SR04 Ultrasonic Sensor → 🖥️ Arduino Nano

| HC-SR04 Pin | Arduino Nano Pin | Wire Color (Suggested) |
|-------------|-----------------|------------------------|
| VCC         | 5V              | 🔴 Red                 |
| GND         | GND             | ⚫ Black               |
| TRIG        | D9              | 🟡 Yellow              |
| ECHO        | D10             | 🟢 Green               |

---

### ⚡ Relay Module → 🖥️ Arduino Nano

| Relay Pin | Arduino Nano Pin | Wire Color (Suggested) |
|-----------|-----------------|------------------------|
| VCC       | 5V              | 🔴 Red                 |
| GND       | GND             | ⚫ Black               |
| IN        | D7              | 🔵 Blue                |

---

### 💧 Pump → ⚡ Relay Module

| Relay Terminal | Connect To              |
|----------------|-------------------------|
| COM            | ➕ Positive of Pump      |
| NO             | ➕ Positive of 5V Supply |
| —              | ➖ Pump GND → Supply GND |

> ⚠️ **Note:** Use **NO (Normally Open)** terminal on the relay so the pump stays OFF by default.

---

## 🗺️ Wiring Diagram

```
                      ┌─────────────────────┐
                      │    Arduino Nano      │
                      │                      │
    HC-SR04           │  D9  ────── TRIG     │
   ┌────────┐         │  D10 ────── ECHO     │
   │  VCC ──┼─────────┤  5V                  │
   │  GND ──┼─────────┤  GND                 │
   │  TRIG──┼─────────┤  D9                  │
   │  ECHO──┼─────────┤  D10                 │
   └────────┘         │                      │
                      │  D7  ──────────────► Relay IN
    Relay Module      │  5V  ──────────────► Relay VCC
   ┌────────────┐     │  GND ──────────────► Relay GND
   │ IN  ◄──────┼─────┤  D7                  │
   │ VCC ◄──────┼─────┤  5V                  │
   │ GND ◄──────┼─────┤  GND                 └──────────────────────┘
   │ COM ───────┼──────────────────────► Pump (+)
   │ NO  ───────┼──────────────────────► 5V Supply (+)
   └────────────┘         Pump GND ──► 5V Supply (-)
```

---

## ⚙️ How It Works

```
👋 Hand placed under sensor
        ↓
📡 Ultrasonic measures distance
        ↓
📏 Distance ≤ 10 cm?
        ↓ YES
⚡ Relay triggers → 💧 Pump ON
        ↓
⏱️ Pump runs for 2 seconds
        ↓
🔴 Pump OFF automatically
        ↓
⏳ 2 second cooldown
        ↓
✅ Ready for next detection!
```

---

## 🎛️ Adjustable Settings

Open the `.ino` file and change these values at the top:

```cpp
const int  DETECT_DISTANCE_CM = 10;    // 📏 Hand detection range (cm)
const long PUMP_ON_TIME_MS    = 2000;  // ⏱️ How long pump runs (ms)
const long COOLDOWN_MS        = 2000;  // ⏳ Wait before next trigger (ms)
```

---

## 🚀 Upload Instructions

1. 🖥️ Open **Arduino IDE**
2. 📂 Go to `File → Open` → select `AutoSanitizerDispenser.ino`
3. 🔧 Select Board: `Tools → Board → Arduino Nano`
4. ⚙️ Select Processor: `Tools → Processor → ATmega328P (Old Bootloader)`
   > *(If upload fails, try switching to Old Bootloader — most Nano clones need this)*
5. 🔌 Select Port: `Tools → Port → COMx` *(your Nano's port)*
6. ▶️ Click **Upload** and wait for *"Done uploading"*

---

## 📟 Serial Monitor

Open Serial Monitor at **9600 baud** to see live output:

```
=== Auto Sanitizer Dispenser Ready ===
Distance: 45 cm
Distance: 43 cm
Distance: 8 cm
>> Hand Detected! Dispensing...
>> Done. Cooling down...
Distance: 9 cm
Distance: 42 cm
```

---

## ⚠️ Safety Notes

- 🔴 **Never connect pump directly to Arduino** — always use a relay
- 💧 Keep water/sanitizer away from electronics
- 🔌 Use a proper 5V power supply — not just USB for the pump
- ⚡ Double-check relay wiring before powering on

---

## 👨‍💻 Project Info

| Field       | Detail                                      |
|-------------|---------------------------------------------|
| 🖥️ Board    | Arduino Nano (ATmega328P)                   |
| 📡 Sensor   | HC-SR04 Ultrasonic                          |
| ⚡ Output    | 5V Relay Module → Mini Pump                 |
| 📏 Range    | 0 – 10 cm (adjustable)                      |
| ⏱️ Pump Time | 2 seconds (adjustable)                     |
| 💻 IDE      | Arduino IDE 1.8+ / 2.x                      |

---

> 🌟 *Stay safe, stay clean!* 🧴✨
