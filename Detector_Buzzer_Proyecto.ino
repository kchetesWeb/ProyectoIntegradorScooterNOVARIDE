#define TRIG 9
#define ECHO 8
#define BUZZER 11

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  float distancia = duracion * 0.0343 / 2;

  if (distancia <= 25) {
    tone(BUZZER, 1000, 100);
    delay(150);
  }
  else if (distancia <= 50) {
    tone(BUZZER, 800, 150);
    delay(300);
  }
  else if (distancia <= 75) {
    tone(BUZZER, 600, 200);
    delay(500);
  }
  else if (distancia <= 80) {
    tone(BUZZER, 400, 150);
    delay(800);
  }
  else {
    noTone(BUZZER);
    delay(500);
  }
}
