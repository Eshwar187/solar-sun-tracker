# Solar Panel Sun Tracker using Arduino (Wokwi Simulation)

## 1. Introduction

Solar energy is one of the most important renewable energy sources. However, traditional solar panels remain fixed and do not always receive maximum sunlight. To improve efficiency, a solar tracking system is used. This project simulates a solar panel sun tracker using Arduino and light sensors (LDRs) in Wokwi.

---

## 2. Objective

The objective of this project is to design a system that automatically adjusts the position of a solar panel to face the direction of maximum sunlight using sensors and a servo motor.

---

## 3. Components Used

* Arduino Uno
* Servo Motor (SG90)
* 2 × LDR Sensor Modules
* Breadboard
* Connecting Wires
* Wokwi Simulator

---

## 4. Working Principle

The system uses two LDR sensors placed on either side of the solar panel. These sensors measure light intensity. The Arduino reads analog values from both sensors and compares them.

* If left sensor detects more light → servo rotates left
* If right sensor detects more light → servo rotates right

This ensures the panel always faces the brightest light source.

---

## 5. Circuit Description

* LDR modules are connected to analog pins A0 and A1
* Servo motor signal is connected to digital pin 9
* All components share common power (5V) and ground

---

## 6. Algorithm

1. Start system
2. Read values from both LDR sensors
3. Compare light intensity
4. Rotate servo toward higher intensity
5. Repeat continuously

---

## 7. Code

```cpp
#include <Servo.h>

Servo myServo;

int leftLDR = A0;
int rightLDR = A1;

int pos = 90;

void setup() {
  myServo.attach(9);
  myServo.write(pos);
}

void loop() {
  int leftValue = analogRead(leftLDR);
  int rightValue = analogRead(rightLDR);

  if (leftValue > rightValue + 50) {
    pos--;
  } 
  else if (rightValue > leftValue + 50) {
    pos++;
  }

  pos = constrain(pos, 0, 180);
  myServo.write(pos);

  delay(50);
}
```

---

## 8. Advantages

* Increases solar panel efficiency
* Fully automatic system
* Low cost and simple design

---

## 9. Applications

* Solar power plants
* Smart energy systems
* IoT-based automation projects

---

## 10. Conclusion

This project successfully demonstrates an automated solar tracking system using Arduino. It improves energy efficiency by aligning the panel with the direction of maximum sunlight.

---

## 11. Future Scope

* Dual-axis tracking system
* IoT integration for remote monitoring
* Battery storage system integration

## Simulation Link
https://wokwi.com/projects/460760466853740545

<img width="895" height="740" alt="image" src="https://github.com/user-attachments/assets/b1600735-e02a-482b-8171-5b90cb597299" />
