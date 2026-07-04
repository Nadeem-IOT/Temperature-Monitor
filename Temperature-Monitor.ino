#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Start serial communication for logging
  Serial.begin(9600);
  Serial.println("--- Wokwi Temp Logger Initialized ---");

  // Start up the DS18B20 library
  sensors.begin();

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Print a brief splash screen
  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Request temperature from the sensor
  sensors.requestTemperatures(); 
  
  // Fetch temperature in Celsius
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading is valid
  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Could not read temperature data");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error    ");
  } else {
    // 1. Log to Serial Monitor
    Serial.print("Current Temp: ");
    Serial.print(tempC);
    Serial.println(" C");

    // 2. Display on 16x2 LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC, 1);   // Prints with 1 decimal place
    lcd.print((char)223); // Degree symbol code for LCD
    lcd.print("C   ");    // Spaces clear old text residues

    lcd.setCursor(0, 1);
    lcd.print("Status: Simulating");
  }

  // Wait 1 second before the next reading
  delay(1000);
}