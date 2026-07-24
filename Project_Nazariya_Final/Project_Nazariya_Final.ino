#include <DFMiniMp3.h>

// ----------------------
// Ultrasonic Sensor Pins
// ----------------------

const byte FRONT_TRIG = A0;
const byte FRONT_ECHO = A1;

const byte LEFT_TRIG = A2;
const byte LEFT_ECHO = A3;

const byte RIGHT_TRIG = A4;
const byte RIGHT_ECHO = A5;

// Obstacle detection range (cm)
const int MIN_DISTANCE = 10;
const int MAX_DISTANCE = 50;

// Distance measurements
long duration;
long distance;
long frontDistance;
long leftDistance;
long rightDistance;

// ----------------------
// DFPlayer Notifications
// ----------------------

class Mp3Notify
{
public:
    static void OnError(uint16_t errorCode)
    {
        Serial.print("DFPlayer Error: ");
        Serial.println(errorCode);
    }

    static void OnPlayFinished(uint16_t track)
    {
        Serial.print("Finished Track ");
        Serial.println(track);
    }

    static void OnCardOnline(uint16_t)
    {
        Serial.println("SD Card Online");
    }

    static void OnCardInserted(uint16_t)
    {
        Serial.println("SD Card Inserted");
    }

    static void OnCardRemoved(uint16_t)
    {
        Serial.println("SD Card Removed");
    }
};

// DFPlayer uses the Arduino's hardware UART
DFMiniMp3<HardwareSerial, Mp3Notify> mp3(Serial);

void setup()
{
    Serial.begin(115200);

    pinMode(FRONT_TRIG, OUTPUT);
    pinMode(FRONT_ECHO, INPUT);

    pinMode(LEFT_TRIG, OUTPUT);
    pinMode(LEFT_ECHO, INPUT);

    pinMode(RIGHT_TRIG, OUTPUT);
    pinMode(RIGHT_ECHO, INPUT);

    mp3.begin();
    mp3.setVolume(28);
}

void loop()
{
    frontDistance = readDistance(FRONT_TRIG, FRONT_ECHO);
    leftDistance = readDistance(LEFT_TRIG, LEFT_ECHO);
    rightDistance = readDistance(RIGHT_TRIG, RIGHT_ECHO);

    Serial.print("Front: ");
    Serial.println(frontDistance);

    Serial.print("Left: ");
    Serial.println(leftDistance);

    Serial.print("Right: ");
    Serial.println(rightDistance);

    if (frontDistance >= MIN_DISTANCE && frontDistance <= MAX_DISTANCE)
    {
        mp3.playMp3FolderTrack(1);
        delay(100);
    }

    if (leftDistance >= MIN_DISTANCE && leftDistance <= MAX_DISTANCE)
    {
        mp3.playMp3FolderTrack(2);
        delay(100);
    }

    if (rightDistance >= MIN_DISTANCE && rightDistance <= MAX_DISTANCE)
    {
        mp3.playMp3FolderTrack(3);
        delay(100);
    }
}

long readDistance(byte trigPin, byte echoPin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    return (duration / 2) / 29.1;
}