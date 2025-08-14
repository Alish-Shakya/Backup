// Motor Pins (Connect to L298N)
#define ENA 9   // Enable pin for Motor A
#define IN1 8   // Input 1 for Motor A
#define IN2 7   // Input 2 for Motor A
#define ENB 10  // Enable pin for Motor B
#define IN3 6   // Input 3 for Motor B
#define IN4 5   // Input 4 for Motor B

// IR Sensor Pins
#define IR_LEFT A0   // Left IR sensor
#define IR_RIGHT A1  // Right IR sensor

// Speed and Threshold Settings
#define BASE_SPEED 48  // Base speed for motors (0-255) 
#define TURN_SPEED 200  // Speed for turning
#define THRESHOLD 500

// Debugging
#define DEBUG true  // Set to false to disable serial output

// Helper function to set motor states
void setMotors(bool in1, bool in2, bool in3, bool in4, int speedA, int speedB) {
    digitalWrite(IN1, in1);
    digitalWrite(IN2, in2);
    digitalWrite(IN3, in3);
    digitalWrite(IN4, in4);
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
}

void setup() {
    if (DEBUG) Serial.begin(9600);

    // Motor Pins as Output
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // IR Sensor Pins as Input
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_RIGHT, INPUT);

    // Stop Motors initially
    stopMotors();
}

void loop() {
    int leftSensor = analogRead(IR_LEFT);
    int rightSensor = analogRead(IR_RIGHT);

    if (DEBUG) {
        Serial.print("Left Sensor: ");
        Serial.print(leftSensor);
        Serial.print(" | Right Sensor: ");
        Serial.println(rightSensor);
    }

    if (leftSensor < THRESHOLD && rightSensor < THRESHOLD) {
        moveForward();
        
    } else if (leftSensor >= THRESHOLD && rightSensor < THRESHOLD) {
        while (leftSensor >= THRESHOLD) { // Corrected condition
            turnLeft();
            leftSensor = analogRead(IR_LEFT); // Update sensor value inside loop
        }

    } else if (leftSensor < THRESHOLD && rightSensor >= THRESHOLD) {
        while (rightSensor >= THRESHOLD) { // Corrected condition
            turnRight();
            rightSensor = analogRead(IR_RIGHT); // Update sensor value inside loop
        }

    } else if (leftSensor >= THRESHOLD && rightSensor >= THRESHOLD) { // Corrected condition
        moveForward();
        delay(10); // Delay can be adjusted or removed based on your needs
        turnLeft();
        delay(10); 
        turnRight();
        delay(10); 
        moveForward();
        delay(10); 
    }
}

void moveForward() {
    setMotors(HIGH, LOW, HIGH, LOW, BASE_SPEED, BASE_SPEED);
}

void turnLeft() {
    setMotors(LOW, HIGH, HIGH, LOW, TURN_SPEED, TURN_SPEED);
}

void turnRight() {
    setMotors(HIGH, LOW, LOW, HIGH, TURN_SPEED, TURN_SPEED);
}

void stopMotors() {
    setMotors(LOW, LOW, LOW, LOW, 0, 0);
}
