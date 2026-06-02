
# Bluetooth Controlled Car using Arduino

This project implements a Bluetooth-controlled robot car using an Arduino board, HC-05/HC-06 Bluetooth module, and an L298N motor driver. The car can be controlled wirelessly via a smartphone app to move forward, backward, left, right, and stop.

## Features

- **Wireless Control**: Control the car via Bluetooth using any serial terminal app or custom remote control app
- **5 Basic Movements**: Forward, backward, left, right, and stop
- **Simple Command Interface**: Uses single-character commands ('F', 'B', 'L', 'R', 'S')
- **Adjustable Speed**: PWM-based motor speed control (preset to 200/255)

## Hardware Requirements

- Arduino Board (Uno, Nano, Mega, etc.)
- HC-05 or HC-06 Bluetooth Module
- L298N Motor Driver Module
- DC Motors x2 with wheels
- Robot Chassis
- Battery Pack (7.2V - 12V)
- Connecting Wires

## Pin Connections

### Bluetooth Module (SoftwareSerial)
| Bluetooth | Arduino |
|-----------|---------|
| TX | D2 |
| RX | D3 |
| VCC | 5V |
| GND | GND |

### L298N Motor Driver
| L298N | Arduino | Function |
|-------|---------|----------|
| ENA | D5 | Left motor speed (PWM) |
| IN1 | D8 | Left motor control 1 |
| IN2 | D9 | Left motor control 2 |
| IN3 | D10 | Right motor control 1 |
| IN4 | D11 | Right motor control 2 |
| ENB | D6 | Right motor speed (PWM) |
| +12V | Battery + | Motor power |
| GND | Battery - & Arduino GND | Common ground |

## Installation

1. **Install Arduino IDE** from [arduino.cc](https://www.arduino.cc/en/software)

2. **Upload the Code**:
   - Connect your Arduino to your computer
   - Select the correct Board and Port in Arduino IDE
   - Copy and paste the code
   - Click Upload (→)

3. **Bluetooth Setup**:
   - Pair your phone with the HC-05/HC-06 module
   - Default PIN is usually `1234` or `0000`
   - Install a Bluetooth terminal app (e.g., "Arduino Bluetooth Controller" or "Serial Bluetooth Terminal")

## Usage

1. Power on your Arduino and Bluetooth module
2. Connect your phone to the Bluetooth module
3. Open the Bluetooth terminal app
4. Send these commands to control the car:

| Command | Action |
|---------|--------|
| `F` | Move Forward |
| `B` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `S` | Stop |

## Code Customization

### Adjust Motor Speed
Change the PWM values in `setup()` function (0-255):
```cpp
analogWrite(ENA, 200);  // Left motor speed
analogWrite(ENB, 200);  // Right motor speed
```

### Change Bluetooth Baud Rate
Modify the baud rate in `setup()`:
```cpp
BT.begin(9600);  // Change to match your module
```

### Add Custom Commands
Extend the switch-case in `loop()`:
```cpp
case 'X': customFunction(); break;
```

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Car doesn't move | Check battery connections and power LED on L298N |
| Bluetooth not connecting | Verify baud rate matches (default 9600) |
| Motors running opposite direction | Swap IN1/IN2 or IN3/IN4 connections |
| Car moves but erratic | Check common ground between Arduino and L298N |
| Bluetooth not visible | Ensure module is powered (blinking LED) |

## Circuit Diagram

```
                    Arduino Uno
                 +--------------+
                 |              |
            D5 --|ENA           |
            D6 --|ENB           |
            D8 --|IN1           |
            D9 --|IN2           |
            D10--|IN3           |
            D11--|IN4           |
                 |              |
            D2 --|RX (BT TX)    |
            D3 --|TX (BT RX)    |
                 |              |
                 +--------------+
```

## Dependencies

- **SoftwareSerial.h** (built-in with Arduino IDE)
- No additional libraries required