const int sensorPin = A0;

const int blueLED = 3;
const int greenLED = 4;
const int redLED = 5;

const float coldBarrier = 20.0;
const float hotBarrier = 30.0;

int sensorVal = 0;
float voltage = 0.0;
float degree = 0.0;


void setup() {

    // Open serial port (9600 baud for Arduino)
    Serial.begin(9600);

    // Initialize all pins
    for (int pinNumber = 3; pinNumber <= 5; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
    }

    // Let every LED blink at least once to see if they are working
    for (int pinNumber = 3; pinNumber <= 5; pinNumber++) {
        digitalWrite(pinNumber, HIGH);
        delay(250);
        digitalWrite(pinNumber, LOW);
    }
}

void loop() {

    readDegree();
    printDegree();
    writeDegree();

    delay(200);
}

void readDegree() {
    sensorVal = analogRead(sensorPin);
    voltage = (sensorVal / 1024.0) * 5.0;
    degree = (voltage - 0.5) * 100.0;
}

void printDegree() {
    Serial.print("Sensor value: ");
    Serial.print(sensorVal);
    Serial.print(" Volt: ");
    Serial.print(voltage);
    Serial.print(" Degrees in C: ");
    Serial.println(degree);
}

void writeDegree() {
    if (degree < coldBarrier) {
        digitalWrite(blueLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, LOW);
    } else if ((degree >= coldBarrier) && (degree < hotBarrier)) {
        digitalWrite(blueLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
    } else if (degree >= hotBarrier) {
        digitalWrite(blueLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
    }
}
