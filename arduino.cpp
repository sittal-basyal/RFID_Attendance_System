#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX = D2, TX = D3

// Motor driver pins
#define ENA 5   // Left motor speed (PWM)
#define ENB 6   // Right motor speed (PWM)
#define IN1 8   // Left motor
#define IN2 9
#define IN3 10  // Right motor
#define IN4 11

char cmd; // stores command from Bluetooth

void setup() {
  BT.begin(9600);     // Bluetooth default baud rate
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set motor speed (0–255)
  analogWrite(ENA, 200); 
  analogWrite(ENB, 200);
}

void loop() {
  if (BT.available()) {
    cmd = BT.read();

    switch (cmd) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopCar(); break;
    }
  }
}

// ---- Movement functions ----
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}