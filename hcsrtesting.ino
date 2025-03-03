#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration;
    float distance;

    // Kirim sinyal ultrasonik
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Terima sinyal pantulan
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * 0.0343) / 2; // Konversi ke cm

    // Tampilkan hasil ke Serial Monitor
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500); // Tunggu sebelum membaca lagi
}
