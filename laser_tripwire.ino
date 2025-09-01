// ESP32 Laser Tripwire Alarm with Controlled Laser

#define LASER_PIN 23     // GPIO to control laser module SIGNAL pin
#define LDR_PIN 34       // Analog pin connected to LDR voltage divider
#define BUZZER_PIN 25    // Buzzer pin

int threshold = 1500;    // Adjust based on your LDR readings (0-4095)

void setup() {
  Serial.begin(115200);

  // Set pin modes
  pinMode(LASER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Turn laser ON initially
  digitalWrite(LASER_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Laser Tripwire Alarm Starting...");
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // Read LDR analog value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < threshold) {          // Beam interrupted
    digitalWrite(BUZZER_PIN, HIGH);    // Sound alarm
    Serial.println("🚨 ALERT! Laser beam interrupted!");
  } else {                             // Beam intact
    digitalWrite(BUZZER_PIN, LOW);     // No alarm
  }

  delay(100);  // Small delay for stability
}
