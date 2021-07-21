#include <LiquidCrystal.h>

/* LCD Display */
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

/* MQ3 Sensor */
#define MQ3_INPUT A5
#define DRUNK_LVL 0.8

/* Piezo buzzer */
#define P_BUZZER 8

/* LED INDICATOR */
#define LED 3

void setup() {
  Serial.begin(9600);

  //MQ3 Sensor Setup
  pinMode(MQ3_INPUT, INPUT);
  pinMode(P_BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  //setup LCD
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
  lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner
  lcd.print("MQ3 Warming up!");
  delay(20000); // allow the MQ3 to warm up
  lcd.clear();
}

void loop() {
  //read sensor
  const float bacLvl = readMq3Sensor();

  displaySensorReadingOnLcd(bacLvl);

  //take decision
  if (bacLvl > DRUNK_LVL) {
    //inform the user
    displayDecisionTextOnLcd(true);
    buzzUser();
  }
  else {
    //inform the user
    displayDecisionTextOnLcd(false);
  }

  delay(2000); // wait 2s for next reading
}

float readMq3Sensor() {
  float sensorReading = analogRead(MQ3_INPUT);

  //print the sensor reading for debugging
  Serial.print("SENSOR READING - ");
  Serial.print(sensorReading);
  Serial.println("");
  delay(100);

  float v = sensorReading * (5.0 / 1024.0);
  float mgL = 0.67 * v;
  return mgL;
}

void displayDecisionTextOnLcd(bool isDrunk) {
  if (isDrunk) {
    lcd.setCursor(0, 1);
    lcd.print("LVL : Drunk");
  }

  else {
    lcd.setCursor(0, 1);
    lcd.print("LVL : Normal");
  }
}

void displaySensorReadingOnLcd(float adcValue) {
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("BAC : ");
  lcd.print(adcValue);
  lcd.print(" %");
}

void buzzUser() {
  digitalWrite(P_BUZZER, HIGH);
  digitalWrite(LED, HIGH);
  delay(1500);
  digitalWrite(LED, LOW);
  digitalWrite(P_BUZZER, LOW);
}
