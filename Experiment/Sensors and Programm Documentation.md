Documentation of the Sensors and Programs for the experiment
===
# Sensors chosen and properties

For the scope of this project it was important to choose sensors, whos operating range is within the standard museum environment and the more challenging condition of monuments without heating or airconditioning, as these could be the potential scenarios in which they could be deployed.

||BME280|BME680|SHT40|SHT31|SHT85|DHT22|
|---|---|---|---|---|---|---|
|Comunication|I2C, SPI|I2C, SPI|I2C, SPI|I2C, SPI|I2C, SPI|One-Wire|
|primary I2C-Adress|0x76|0x76|0x44|0x44|0x44|---|
|secondary I2C-Adress|0x77|0x77|---|0x45|---|---|
|temperature range|-40 to 85 °C|-40 to 85 °C|-40 to 125 °C|-40 to 125 °C|-40 to 125 °C|-40 - 80°C|
|relative Humidity range|0 to 100 %|10 to 95 %|0 to 100 %|0 to 100 %|0 to 100 %|0 - 99,9 %|
|Repeatability|||0,08 - 0,25 %|0,2 - 0,01 %|0,21 - 0,01 %|± 0,3|
|Humidity accuracy|± 3 % (incl. hysteresis)|± 3 % (incl. hysteresis)|typ. ± 1,8 % (30-70 % rH); max. 3,5% (10-90 % rH)|± 2 %|± 1,5 % (-80 % rH)|± 2 %|
|Hysteresis|± 1 %|± 1,5 %|± 0,8 %|± 0,8 %|± 0,8 %|n.g.|
|Drift|0,5 % p.a.|0,5 % p.a.|< 0,2 % p.a.|< 0,25 % p.a.|< 0,25 % p.a.|< 0,5 % p.a.|
|Relative humdidity resolution|0,008 %|0,008 %|0,01 %|0,01 %|0,01 %|0,1 %|
| Response Time to complete 63% of Step|1 s (Airflow in direction to the vent hole)|8 s (Airflow in direction to the vent hole at 1 m/s)|4 s (airflow 1 m/s)|8 s (airflow 1 m/s)|8s (airflow 1 m/s)| 5 s|
|Temperature acurracy|± 0,5 °C (0-65 °C); ± 1,25 °C (-20-0 °C)|1 °C (0-65 °C)|± 0,2 °C (0-65°C)|± 0,3 °C (19 - 55 °C)|± 0,1 °C| 0,5 - 1°C|
Temperature resolution|0,01 °C|0,01 °C|0,01 °C|0,015 °C|0,01 °C|0,1 °C|
EN 16242:2012 Compliance| ✓|✓|✓|✓|✓|✓|

Information given in the datasheets

All Sensors included in this project are compatible with the requirements put up by the EN 16242:2012 Standard. Though the standard does not clearly state if hysteresis is included in their definition of measurement uncertainty, all sensors stay within the margins stated by it (when operating in normal museum and archive environments).
