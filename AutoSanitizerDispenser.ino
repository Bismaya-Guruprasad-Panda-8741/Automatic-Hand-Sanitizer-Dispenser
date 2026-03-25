/*
  ============================================
   Automatic Sanitizer Dispenser
   Hardware: Arduino Nano
   Sensor  : HC-SR04 Ultrasonic
   Output  : Relay (Active LOW) → Pump
  ============================================
  Pin Connections:
    HC-SR04 VCC  → 5V
    HC-SR04 GND  → GND
    HC-SR04 TRIG → D9
    HC-SR04 ECHO → D10
    Relay IN     → D7
    Relay VCC    → 5V
    Relay GND    → GND
    Pump         → Relay NO/COM
*/

#define TRIG_PIN   9
#define ECHO_PIN   10
#define RELAY_PIN  7

// Settings
const int  DETECT_DISTANCE_CM = 10;   // Hand detection range (cm)
const long PUMP_ON_TIME_MS     = 2000; // Pump runs for 2 seconds
const long COOLDOWN_MS         = 2000; // Wait before next detection

long duration;
int  distance;

// ── Measure distance using HC-SR04 ──────────────────────────────
int measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long dur = pulseIn(ECHO_PIN, HIGH, 30000); // 30 ms timeout
  if (dur == 0) return 999;                  // No echo → out of range
  return (int)(dur * 0.034 / 2);
}

void setup() {
  pinMode(TRIG_PIN,  OUTPUT);
  pinMode(ECHO_PIN,  INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF (Active LOW module)

  Serial.begin(9600);
  Serial.println("=== Auto Sanitizer Dispenser Ready ===");
}

void loop() {
  int dist = measureDistance();

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  // Hand detected within range?
  if (dist > 0 && dist <= DETECT_DISTANCE_CM) {
    Serial.println(">> Hand Detected! Dispensing...");

    digitalWrite(RELAY_PIN, LOW);        // Turn pump ON
    delay(PUMP_ON_TIME_MS);              // Run for 2 seconds
    digitalWrite(RELAY_PIN, HIGH);       // Turn pump OFF

    Serial.println(">> Done. Cooling down...");
    delay(COOLDOWN_MS);                  // Prevent re-trigger immediately
  }

  delay(100); // Polling interval
}
