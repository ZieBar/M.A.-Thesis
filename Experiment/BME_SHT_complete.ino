
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include "Adafruit_SHT31.h"
#include <Adafruit_SHT4x.h>
//#include "SHT85.h"
#include "TCA9548A.h"
#include "DHT.h"
#include <SD.h>
#include <SPI.h>



// defining the PINS and the Type of DHT22s
#define DHTPIN_1 26
#define DHTPIN_2 27
#define DHTPIN_3 28

#define DHTTYPE DHT22

// This array stores the number of the pins to activate the secondary I2C-adress (adress-pins).
// Positions 0-2 are for BME680, 3-5 for SHT31.
int sensors[] = {2,3,4,5,6,7};

int pinCS = 53;

// these arrays are used to store the sensor data from one reading session, which can be saved or be send to the server-µCU.
float tempData[12];
float humData[12];

//For every single sensor an object is created.

File myFile;

DHT dht_1(DHTPIN_1,DHTTYPE);
DHT dht_2(DHTPIN_2,DHTTYPE);
DHT dht_3(DHTPIN_3,DHTTYPE);

Adafruit_BME680 bme680_1;
Adafruit_BME680 bme680_2;
Adafruit_BME680 bme680_3;

Adafruit_SHT31 sht31_1 = Adafruit_SHT31();
Adafruit_SHT31 sht31_2 = Adafruit_SHT31();
Adafruit_SHT31 sht31_3 = Adafruit_SHT31();

// The SHT85 has been removed from this experiment as it didn't work in this configuration. Using only the 6 sensors on the TCA they g
//#define SHT85_ADDRESS         0x44

//SHT85 sht85_1;
//SHT85 sht85_2;
//SHT85 sht85_3;

TCA9548A I2CMux;                  // Multiplexer

Adafruit_SHT4x sht41_1 = Adafruit_SHT4x();
Adafruit_SHT4x sht41_2 = Adafruit_SHT4x();
Adafruit_SHT4x sht41_3 = Adafruit_SHT4x();

void setup() 
{
  Serial.begin(115200);

  //Initializing the SD-Card
  pinMode(pinCS, OUTPUT);

  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }

  
  for (int i = 1; i <= 12; i++){
    myFile = SD.open("BME_SHT.txt", FILE_WRITE);

    if (myFile) {
      
      Serial.println("Creating headers...");
      // Write to file
      myFile.print("Sensor ");
      myFile.print(i);
      myFile.print(" - T in °C, ");
      myFile.print("Sensor ");
      myFile.print(i);
      if (i<=11)  {
        myFile.print(" - rH in %, ");      
      }
      else  {
        myFile.println(" - rH in %");
      }
    }
    else {
      Serial.println("error opening .txt");
    }
    myFile.close(); // close the file
  }
  

  Serial.println("Done.");
  
 /*The following code uses a for-loop to iterate through the sensor-Array. In every iteration one adress-pin get's turned on and the sensor initiated by the .begin()-command.
 The secondary adress is given for each sensor. Then the pin is set to low and the for loop starts anew. 
 As everey single sensor is represented by an inidividual object (for example bme680_1 or bme680_2), an switch-case-statement is used to match the pin with the object. 
 This might not be the most clean way to do this. But it works*/

  for (int i = 0; i<=5;i++){ //PIN-mode has to set and all Pins have to be set to low before hand. If not some sensors might already activate the secondary I2C-adress
  
    pinMode(sensors[i], OUTPUT);
    digitalWrite(sensors[i], LOW);
  }

  for (int i = 0; i<=5;i++){
  
 
    digitalWrite(sensors[i], HIGH);
  
    switch (i){  
  
      case 0:
      if (! bme680_1.begin(0x77)) 
      {   
        Serial.print("Check circuit. BME680 Nr. ");
        Serial.print(i+1);
        Serial.println(" not found!");
        while (1) delay(1);
      }
      else {
        Serial.print ("Sensor ");
        Serial.print(i);
        Serial.println(" found");
      }
      digitalWrite(sensors[i], LOW);
      break;
  
      case 1:
      if (! bme680_2.begin(0x77))  {   
        Serial.print("Check circuit. BME680 Nr. ");
        Serial.print(i+1);
        Serial.println(" not found!");
        while (1) delay(1);
      }
      else {
        Serial.print ("Sensor ");
        Serial.print(i);
        Serial.println(" found");
      }
      digitalWrite(sensors[i], LOW);
      break;
  
  
      case 2:
      if (! bme680_3.begin(0x77)) 
        {   
        Serial.print("Check circuit. BME680 Nr. ");
        Serial.print(i+1);
        Serial.println(" not found!");
        while (1) delay(1);
      }
      else {
        Serial.print ("Sensor ");
        Serial.print(i);
        Serial.println(" found");
      }

      digitalWrite(sensors[i], LOW);
      break;

      case 3:
      if (! sht31_1.begin(0x45)) {

        Serial.print("Check circuit. SHT31 Nr. ");
        Serial.print(i);
        Serial.println(" not found!");
        while (1) delay(1);
      }
      else {
        Serial.print ("Sensor ");
        Serial.print(i);
        Serial.println(" found");
      }
      digitalWrite(sensors[i], LOW);
      delay(10);
      break;
  
      case 4:
      if (! sht31_2.begin(0x45)) {   
       Serial.print("Check circuit. SHT31 Nr. ");
        Serial.print(i-2);
        Serial.println(" not found!");
        while (1) delay(1);
      }
      else {
        Serial.print ("Sensor ");
        Serial.print(i);
        Serial.println(" found");
      }

      digitalWrite(sensors[i], LOW);
      break;
  
      case 5:
      if (! sht31_3.begin(0x45))  {   
        Serial.print("Check circuit. SHT31 Nr. ");
        Serial.print(i-2);
        Serial.println(" not found!");
        while (1) delay(1);
      }
      else {
        Serial.print ("Sensor ");
        Serial.print(i);
        Serial.println(" found");
      }
  
      digitalWrite(sensors[i], LOW);
     break;
    }
  }

  // Multiplexer is inititated
  I2CMux.begin(Wire);             // Wire instance is passed to the library
  Wire.setClock(100000);
  I2CMux.closeAll();              // Set a base state which we know (also the default state on power on)

  for (int i = 3; i <= 5; i++){ // activates the secondary I2C-adress of all SHT31-Sensors, so they dont conflict with the sensors on the multipexer with the same I2C-adress.
    digitalWrite(i,HIGH);
  }
 // Initiate SHT40 No 1
  I2CMux.openChannel(0);
  if (!sht41_1.begin()) {
    Serial.print("Check circuit. SHT40 Nr. ");

    Serial.println(" not found!");
    while (1) delay(1);
 }
  sht41_1.setPrecision(SHT4X_HIGH_PRECISION); //There are 3 precision levels. The highest takes the longest (max. 8.3ms).
  sht41_1.setHeater(SHT4X_NO_HEATER); //For high humidity or other environments with risk of condensation an integrated heater can be set to 6 diiferent settings.

  I2CMux.closeChannel(0);

  //Initiate SHT40 No 2
  I2CMux.openChannel(1);
  if (!sht41_2.begin()) {
    Serial.print("Check circuit. SHT40 Nr. ");
    Serial.println(" not found!");
    while (1) delay(1);
 }
  sht41_2.setPrecision(SHT4X_HIGH_PRECISION); //There are 3 precision levels. The highest takes the longest (max. 8.3ms).
  sht41_2.setHeater(SHT4X_NO_HEATER); //For high humidity or other environments with risk of condensation an integrated heater can be set to 6 diiferent settings.

  I2CMux.closeChannel(1);

  // Initiate SHT40 No 3
  I2CMux.openChannel(2);
  if (!sht41_3.begin()) {
    Serial.print("Check circuit. SHT40 Nr. ");

    Serial.println(" not found!");
    while (1) delay(1);
  }
  sht41_3.setPrecision(SHT4X_HIGH_PRECISION); //There are 3 precision levels. The highest takes the longest (max. 8.3ms).
  sht41_3.setHeater(SHT4X_NO_HEATER); //For high humidity or other environments with risk of condensation an integrated heater can be set to 6 diiferent settings.

  I2CMux.closeChannel(2);

  /*//Initiate SHT85 No 1
  I2CMux.openChannel(3);
  sht85_1.begin(SHT85_ADDRESS);
  sht85_1.heatOff();
  I2CMux.closeChannel(3);

  //Initiate SHT85 No 2
  I2CMux.openChannel(4);
  sht85_2.begin(SHT85_ADDRESS);
  sht85_2.heatOff();
  I2CMux.closeChannel(4);

  //Initiate SHT85 No 3
  I2CMux.openChannel(5);
  sht85_3.begin(SHT85_ADDRESS);
  sht85_3.heatOff();
  I2CMux.closeChannel(5);*/
 
 for (int i = 3; i <= 5; i++){ // deactivates the secondary I2C-adress of all SHT31-sensors.
    digitalWrite(i,LOW);
  }

  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
}


void loop() 
{
  //The reading and saving of temperature and humidity is done the same way as the initialisation of th sensors.
  //In this sketch the data is printed in to the serial monitor to check that the code works. In the final version the data in the arrays is send to a server-µCU.
  
  uint32_t timestamp = millis();
  
 for (int i = 0; i<=5;i++){
 
   digitalWrite(sensors[i], HIGH);
   
   switch (i){
     
     case 3:
     tempData[i] = sht31_1.readTemperature();
     Serial.print("Temperature SHT31 No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(tempData[i]);
     Serial.println(" °C");
     
     humData[i] = sht31_1.readHumidity();
     Serial.print("Humidity SHT31 No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(humData[i]);
     Serial.println(" %");
     digitalWrite(sensors[i], LOW);
     break;
     
     case 4:
     tempData[i] = sht31_2.readTemperature();
     Serial.print("Temperature SHT31 No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(tempData[i]);
     Serial.println(" °C");
     
     humData[i] = sht31_2.readHumidity();
     Serial.print("Humiditiy SHT31 No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(humData[i]);
     Serial.println(" %");
     digitalWrite(sensors[i], LOW);
     break;
     
     case 5:
     tempData[i] = sht31_3.readTemperature();
     Serial.print("Temperature SHT31 No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(tempData[i]);
     Serial.println(" °C");
     
     humData[i] = sht31_3.readHumidity();
     Serial.print("Humidity SHT31 No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(humData[i]);
     Serial.println(" %");
     digitalWrite(sensors[i], LOW);
     break;
     
     case 0:

     tempData[i] = bme680_1.readTemperature();
     Serial.print("Temperature BME No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(tempData[i]);
     Serial.println(" °C");
     
     humData[i] = bme680_1.readHumidity();
     Serial.print("Humidity BME No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(humData[i]);
     Serial.println(" %");
     digitalWrite(sensors[i], LOW);
     break;
     
     case 1:
     tempData[i] = bme680_2.readTemperature();
     Serial.print("Temperature BME No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(tempData[i]);
     Serial.println(" °C");
     
     humData[i] = bme680_2.readHumidity();
     Serial.print("Humidity BME No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(humData[i]);
     Serial.println(" %");
     digitalWrite(sensors[i], LOW);
     break;
     
     case 2:    
     tempData[i] = bme680_3.readTemperature();
     Serial.print("Temperature BME No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(tempData[i]);
     Serial.println(" °C");
     
     humData[i] = bme680_3.readHumidity();
     Serial.print("Humidity BME No. ");
     Serial.print(i);
     Serial.print(": ");
     Serial.print(humData[i]);
     Serial.println(" %");
     digitalWrite(sensors[i], LOW);
     break;
    }   
  }


  //Reading the sensors on the multiplexer

  for (int i = 3; i <= 5; i++){ // activates the secondary I2C-adress of all SHT31-Sensors, so they dont conflict with the sensors on the multipexer with the same I2C-adress.
    digitalWrite(i,HIGH);
  }

    I2CMux.openChannel(0);
   
 //Adafruit_SHT4X-library requires the creation of two objects to store humidity and temperature Data. See for reference: https://learn.adafruit.com/adafruit-sht40-temperature-humidity-sensor/arduino 
  sensors_event_t hum, temp;

 //read 1st Sensor
  sht41_1.getEvent(&hum, &temp); // populate temp and humidity objects with fresh data
  tempData[6] = temp.temperature;
  Serial.print("Temperature SHT41 No. 1");
  
  Serial.print(": ");
  Serial.print(tempData[6]);
  Serial.println(" °C");
    
  humData[6] = hum.relative_humidity;
  Serial.print("Humidity SHT41 No. 1");

  Serial.print(": ");
  Serial.print(humData[6]);
  Serial.println(" %");
  I2CMux.closeChannel(0);

  I2CMux.openChannel(1);


//read 2nd Sensor
  sht41_2.getEvent(&hum, &temp); 
  tempData[7] = temp.temperature;
  Serial.print("Temperature SHT41 No. 2");
  
  Serial.print(": ");
  Serial.print(tempData[7]);
  Serial.println(" °C");
    
  humData[7] = hum.relative_humidity;
  Serial.print("Humidity SHT41 No. 2");

  Serial.print(": ");
  Serial.print(humData[7]);
  Serial.println(" %");
  I2CMux.closeChannel(1);


 //read 3rd Sensor
  I2CMux.openChannel(2);
   
  sht41_3.getEvent(&hum, &temp); 
  tempData[8] = temp.temperature;
  Serial.print("Temperature SHT41 No. 3");
  
  Serial.print(": ");
  Serial.print(tempData[8]);
  Serial.println(" °C");
    
  humData[8] = hum.relative_humidity;
  Serial.print("Humidity SHT41 No. 3");

  Serial.print(": ");
  Serial.print(humData[8]);
  Serial.println(" %");

  I2CMux.closeChannel(2);


  //read 4th Sensor
  /*I2CMux.openChannel(3);
   
  sht85_1.read(false);

  tempData[9] = sht85_1.getTemperature();
  Serial.print("Temperature SHT85 No. 1");

  Serial.print(": ");
  Serial.print(tempData[9]);
  Serial.println(" °C");
  
  humData[9] = sht85_1.getHumidity();
  Serial.print("Humidity SHT85 No. 1");

  Serial.print(": ");
  Serial.print(humData[9]);
  Serial.println(" %");
  I2CMux.closeChannel(3);

//read 5th Sensor
  I2CMux.openChannel(4);
   
  sht85_2.read(false);

  tempData[10] = sht85_2.getTemperature();
  Serial.print("Temperature SHT85 No. 2");

  Serial.print(": ");
  Serial.print(tempData[10]);
  Serial.println(" °C");
  
  humData[10] = sht85_2.getHumidity();
  Serial.print("Humidity SHT85 No. 2");

  Serial.print(": ");
  Serial.print(humData[10]);
  Serial.println(" %");
  I2CMux.closeChannel(4);

  //read 6th Sensor
  I2CMux.openChannel(5);
   
  sht85_3.read(false);

  tempData[11] = sht85_3.getTemperature();
  Serial.print("Temperature SHT85 No. 3");

  Serial.print(": ");
  Serial.print(tempData[11]);
  Serial.println(" °C");
  
  humData[11] = sht85_3.getHumidity();
  Serial.print("Humidity SHT85 No. 3");

  Serial.print(": ");
  Serial.print(humData[11]);
  Serial.println(" %");
  I2CMux.closeChannel(5);*/



  I2CMux.closeAll(); //This is just in case....

  for (int i = 3; i <= 5; i++){ // deactivates the secondary I2C-adress of all SHT31-sensors.
    digitalWrite(i,LOW);
  }

  humData[9] = dht_1.readHumidity(); 
  tempData[9] = dht_1.readTemperature();
  
  delay(2000); // The measurement needs to be repeated as DHT gives first the value in storage and than measures and stores the new values.
  
  humData[9] = dht_1.readHumidity();
  tempData[9] = dht_1.readTemperature();
  
  Serial.print("Temperature DHT No 1: "); //Im seriellen Monitor den Text und 
  Serial.print(tempData[9]); //die Dazugehörigen Werte anzeigen
  Serial.println(" °C");
  Serial.print("Humidity DHT No 1: ");
  Serial.print(humData[9]);
  Serial.println(" %");

  humData[10] = dht_2.readHumidity(); 
  tempData[10] = dht_2.readTemperature();
  
  delay(2000); // The measurement needs to be repeated as DHT gives first the value in storage and than measures and stores the new values.
  
  humData[10] = dht_2.readHumidity();
  tempData[10] = dht_2.readTemperature();
  
  Serial.print("Temperature DHT No 2: "); //Im seriellen Monitor den Text und 
  Serial.print(tempData[10]); //die Dazugehörigen Werte anzeigen
  Serial.println(" °C");
  Serial.print("Humidity DHT No 2: ");
  Serial.print(humData[10]);
  Serial.println(" %");

  humData[11] = dht_3.readHumidity(); 
  tempData[11] = dht_3.readTemperature();
  
  delay(2000); // The measurement needs to be repeated as DHT gives first the value in storage and than measures and stores the new values.
  
  humData[11] = dht_3.readHumidity();
  tempData[11] = dht_3.readTemperature();
  
  Serial.print("Temperature DHT No 3: "); //Im seriellen Monitor den Text und 
  Serial.print(tempData[11]); //die Dazugehörigen Werte anzeigen
  Serial.println(" °C");
  Serial.print("Humidity DHT No 3: ");
  Serial.print(humData[11]);
  Serial.println(" %");

  Serial.println();
  Serial.println();
  Serial.println("Writing data to SD-card.............................");

  for (int i = 0; i <= 11; i++){
    myFile = SD.open("BME_SHT.txt", FILE_WRITE);

    if (myFile) {
      // Write to file
      myFile.print(tempData[i]);
      myFile.print(",");
      myFile.print(humData[i]);
      if (i<=10)  {
        myFile.print(", ");      
      }
      else  {
        myFile.println();
      }
      myFile.close(); // close the file
    }

    else {
      Serial.println("error opening .txt");
    }
    myFile.close(); // close the file
  }
  
  Serial.println("Done.");

  Serial.println();
  Serial.println();

  timestamp = millis() - timestamp;
  delay(10000 - timestamp); //delay-time of 10 min minus the required time for the measurment = measurment intervall of 10 min

 
}
