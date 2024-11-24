#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// PZEM Pins
#define RX_PIN D7
#define TX_PIN D8

// Initialize PZEM Serial
SoftwareSerial pzemSerial(RX_PIN, TX_PIN);

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// WiFi credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// ThingSpeak credentials
const char* server = "api.thingspeak.com";
WiFiClient client;
unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";

// Variables to hold PZEM data
float voltage, current, power, energy;

void setup() {
  // Serial for debugging
  Serial.begin(9600);
  
  // Start PZEM Serial
  pzemSerial.begin(9600);
  
  // Start LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Initializing...");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    lcd.clear();
    lcd.print("Connecting WiFi");
    Serial.println("Connecting to WiFi...");
  }
  lcd.clear();
  lcd.print("WiFi Connected!");
  delay(1000);
  lcd.clear();

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read data from PZEM
  voltage = readPZEMData(0xB0);
  current = readPZEMData(0xB1);
  power = readPZEMData(0xB2);
  energy = readPZEMData(0xB3);

  // Print to Serial Monitor
  Serial.print("Voltage: "); Serial.println(voltage);
  Serial.print("Current: "); Serial.println(current);
  Serial.print("Power: "); Serial.println(power);
  Serial.print("Energy: "); Serial.println(energy);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("V:"); lcd.print(voltage); lcd.print("V ");
  lcd.print("I:"); lcd.print(current); lcd.print("A");
  lcd.setCursor(0, 1);
  lcd.print("P:"); lcd.print(power); lcd.print("W ");
  lcd.print("E:"); lcd.print(energy); lcd.print("kWh");

  // Send data to ThingSpeak
  ThingSpeak.setField(1, voltage);
  ThingSpeak.setField(2, current);
  ThingSpeak.setField(3, power);
  ThingSpeak.setField(4, energy);
  
  int status = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (status == 200) {
    Serial.println("Update successful");
  } else {
    Serial.println("Update failed, error: " + String(status));
  }

  delay(15000); // Wait for 15 seconds before the next update
}

// Function to read data from PZEM
float readPZEMData(uint8_t command) {
  pzemSerial.write(command);
  delay(100);
  if (pzemSerial.available()) {
    return pzemSerial.parseFloat();
  }
  return 0.0; // Return 0 if no data is available
}
