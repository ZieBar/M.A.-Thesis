Documentation of the Sensors and Programs for the experiment
===
# Sensors chosen and properties

For the scope of this project it was important to choose sensors, whos operating range is within the standard museum environment and the more challenging condition of monuments without heating or airconditioning, as these could be the potential scenarios in which they could be deployed.

||BME280|BME680|DHT22|SHT31|SHT41|SHT85|
|---|---|---|---|---|---|---|
|Comunication|I2C, SPI|I2C, SPI|One-Wire|I2C, SPI|I2C, SPI|I2C, SPI|
|primary I2C-Adress|0x76|0x76|---|0x44|0x44|0x44|
|secondary I2C-Adress|0x77|0x77|---|0x45|---|---|
|temperature range|-40 to 85 °C|-40 to 85 °C|-40 to 80 °C|-40 to 125 °C|-40 to 125 °C|n.g.|
|relative Humidity range|0 to 100 %|10 to 95 %|0 to 99,9 %|0 to 100 %|0 to 100 %|0 to 100 %|
|Humidity accuracy|||||||
|Hysteresis|||||||
|Drift||||||||
|Temperature acurracy|||||||
Information given in the Datasheets
