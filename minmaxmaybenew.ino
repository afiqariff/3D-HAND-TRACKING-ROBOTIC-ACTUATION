#include <Servo.h>

// Create servo objects for 5 fingers and wrist
Servo thumbServo, indexServo, middleServo, ringServo, pinkyServo, wristServo;

// Neutral positions
const int NEUTRAL_THUMB = 20;
const int NEUTRAL_INDEX = 20;
const int NEUTRAL_MIDDLE = 20;
const int NEUTRAL_RING = 20;
const int NEUTRAL_PINKY = 20;
const int NEUTRAL_WRIST = 90;

void setup() {
  Serial.begin(9600);

  // Attach servos to their respective pins
  thumbServo.attach(3);
  indexServo.attach(4);
  middleServo.attach(5);
  ringServo.attach(6);
  pinkyServo.attach(7);
  wristServo.attach(8);

  // Move servos to their neutral positions at startup
  moveToNeutral();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read until newline
    parseAndMoveServos(input);
  }
}

void moveToNeutral() {
  thumbServo.write(NEUTRAL_THUMB);
  indexServo.write(NEUTRAL_INDEX);
  middleServo.write(NEUTRAL_MIDDLE);
  ringServo.write(NEUTRAL_RING);
  pinkyServo.write(NEUTRAL_PINKY);
  wristServo.write(NEUTRAL_WRIST);
}

void parseAndMoveServos(String data) {
  // Extract angles for each servo
  int thumbAngle = extractAngle(data, "Thumb");
  int indexAngle = extractAngle(data, "Index");
  int middleAngle = extractAngle(data, "Middle");
  int ringAngle = extractAngle(data, "Ring");
  int pinkyAngle = extractAngle(data, "Pinky");
  int wristAngle = extractAngle(data, "Wrist");

  // If no hand detected (empty string or invalid data), return to neutral
  if (thumbAngle == -1 && indexAngle == -1 && middleAngle == -1 &&
      ringAngle == -1 && pinkyAngle == -1 && wristAngle == -1) {
    moveToNeutral();
    return;
  }

  // Move servos to extracted angles
  if (thumbAngle != -1) thumbServo.write(thumbAngle);
  if (indexAngle != -1) indexServo.write(indexAngle);
  if (middleAngle != -1) middleServo.write(middleAngle);
  if (ringAngle != -1) ringServo.write(ringAngle);
  if (pinkyAngle != -1) pinkyServo.write(pinkyAngle);
  if (wristAngle != -1) wristServo.write(wristAngle);
}

int extractAngle(String data, String key) {
  int keyIndex = data.indexOf(key + ":");
  if (keyIndex == -1) return -1; // Return -1 if key not found

  int valueStart = keyIndex + key.length() + 1; // Start after "Key:"
  int valueEnd = data.indexOf(',', valueStart);
  if (valueEnd == -1) valueEnd = data.length(); // Handle last value

  return data.substring(valueStart, valueEnd).toInt();
}

