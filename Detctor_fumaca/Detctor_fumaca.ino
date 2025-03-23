#define MQ2_PIN 4
#define GAS_THRESHOLD 600
void setup() {
  Serial.begin(9600);
  analogReadResolution(10);
  Serial.println("MQ-2 Sensor Initialized!");
  pinMode(MQ2_PIN, INPUT);
}

void loop() {
  Serial.print("Gas Value: ");
  Serial.println(analogRead(MQ2_PIN));
   if (MQ2_PIN > GAS_THRESHOLD) {
    Serial.println("Warning! High gas or smoke levels detected!");
   }
   delay(500);
}
