# Temperature Monitor with 16x2 LCD & Serial Logging

## 📝 Project Overview
This project reads real-time temperature data from a sensor and displays the current values on an I2C 16x2 LCD screen. It also logs the temperature data continuously over the Serial Monitor. This project was developed as part of my internship at Internspark.

* **Simulation Tool Used:** Wokwi

---

## 🛠️ Components Used
* **Microcontroller:** Arduino UNO
* **Temperature Sensor:** DS18B20 (or LM35)
* **Display:** 16x2 LCD with I2C module
* **Connecting Wires & Breadboard**

---

## 🔌 Circuit Connection details

### 1. I2C LCD to Arduino UNO
* **GND** ➡️ GND
* **VCC** ➡️ 5V
* **SDA** ➡️ A4
* **SCL** ➡️ A5

### 2. Temperature Sensor to Arduino UNO
* **VCC** ➡️ 5V
* **GND** ➡️ GND
* **Data Pin** ➡️ Digital Pin 2

---

##  How to Run the Project
1. Open the `sketch.ino` file in the Arduino IDE.
2. Install the following libraries via the Library Manager:
   * `LiquidCrystal_I2C`
   * `DallasTemperature` & `OneWire` (if using DS18B20)
3. Upload the code to your Arduino UNO.
4. Open the **Serial Monitor** at **9600 baud rate** to view live temperature logs.

---

## 👤 Developer
* **Name:** Sayyad Nadeem
* **Internship:** Internspark IoT/Embedded Systems Intern
