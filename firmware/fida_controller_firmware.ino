// --------------------------------------------------------------
// IX-Proshchalnyy-Dar : FIDA Control Firmware
// Governs UV kill timing, CryoCore monitoring, PFAS detection,
// ambient energy toggling, and fractal beam array gating
// --------------------------------------------------------------

#define UV_RELAY_PIN        4
#define CRYOCORE_SENSOR_PIN A0
#define PFAS_SENSOR_PIN     A1
#define AMBIENT_MODULE_PIN  5
#define BEAM_GATE_PIN       6
#define STATUS_LED_PIN      13

unsigned long uv_pulse_duration = 10000; // 10 sec UV burst
unsigned long last_uv_time = 0;
int cryo_threshold = 45; // max coil temp °C
bool beam_enabled = false;

void setup() {
  pinMode(UV_RELAY_PIN, OUTPUT);
  pinMode(AMBIENT_MODULE_PIN, OUTPUT);
  pinMode(BEAM_GATE_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(UV_RELAY_PIN, LOW);
  digitalWrite(AMBIENT_MODULE_PIN, HIGH); // always ON
  digitalWrite(BEAM_GATE_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  int cryo_temp = analogRead(CRYOCORE_SENSOR_PIN); // simulated value
  int pf_detect = analogRead(PFAS_SENSOR_PIN);     // simulated value

  // Map analog to temp (placeholder scale: 0-1023 = 0-100°C)
  float cryo_temp_c = map(cryo_temp, 0, 1023, 0, 100);
  float pf_level = map(pf_detect, 0, 1023, 0, 10); // ppm

  // Log status
  Serial.print("Cryo Temp: ");
  Serial.print(cryo_temp_c);
  Serial.print(" °C | PFAS Level: ");
  Serial.print(pf_level);
  Serial.println(" ppm");

  // Cryo overheat protection
  if (cryo_temp_c > cryo_threshold) {
    digitalWrite(UV_RELAY_PIN, LOW);
    digitalWrite(BEAM_GATE_PIN, LOW);
    digitalWrite(STATUS_LED_PIN, HIGH); // Alert
    return;
  } else {
    digitalWrite(STATUS_LED_PIN, LOW);
  }

  // PFAS Detected → Trigger UV cycle
  if (pf_level > 3.0 && millis() - last_uv_time > 30000) {
    digitalWrite(UV_RELAY_PIN, HIGH);
    delay(uv_pulse_duration);
    digitalWrite(UV_RELAY_PIN, LOW);
    last_uv_time = millis();
  }

  // Enable fractal beam gate if PFAS > threshold
  if (pf_level > 6.0) {
    digitalWrite(BEAM_GATE_PIN, HIGH);
    beam_enabled = true;
  } else {
    digitalWrite(BEAM_GATE_PIN, LOW);
    beam_enabled = false;
  }

  delay(1000); // polling interval
}
