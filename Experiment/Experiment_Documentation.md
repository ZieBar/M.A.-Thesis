Dokumentation of the Experiment using Saturated Salt Solutions
===
<br/><br/>
> __+++ important note: when dealing with  chemicals and tools read the datasheet and take neccessary precautions for personal and environmental protection +++__

<br/><br/>

# 1 Scope of the Experiment
This Experiment is designd to test low-cost Sensors for Open-Source environment monitoring in a precise but costeffective way.
According to german calibration-standards it is not suitable for a proper and precise calibration of scientific equipment that needs the highest possibile accuracy. It is however suitable for testing sensors to establish if a proper calibration is needed.
This Experiment should, if properly executed, be able to show the precision  and accuracy of a sensor in  a given environment. Hysteresis-effects can not be demonstrated.

## 1.2 Sensors tested in this experiment
In this Experimetn the following Sensors are tested.

<br/><br/>
|Sensors |	DHT22	| BME280	| BME680	| SHT31	| SHT41	| SHT85 |
|---------|---------|-----------|-----------|-------|-------|-------|
|Communication-protocol |	One-Wire	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C |

![Abbildung der 6 Sensortypen](https://github.com/ZieBar/M.A.-Thesis/blob/e8368e8d98c811b5c88421134cfb4076032809b6/Experiment/Abbildungen/_DSC3556.jpg)
Pictture of the tested Sensors
<br/><br/>



# 2 Materials and Tools

## 2.1 Tools

|Quantity|Tool|Type/Brand|Dimensions|
|:---:|---|---|---|
|1 pcs.|Digital Hygrothermometer|testo 175H1|---|
|3 pcs.|Polypropylen Boxes |IKEA 365+|320x210x120 mm|
|3 pcs.|Polypropylen Lids with ruber sealing|IKEA 365+|320x210x15 mm|
|1 pcs.|3D-Printer|Prusa i3 MK3 S+|---|
|3 pcs.|Breadboards|BerryBase|165 x55 mm, 830 contacts, 2,54 mm grid|
|20 pcs.|20 F-F Jumperwires|BerryBase|100 mm|
|20 pcs.|20 F-M Jumperwires|BerryBase|100 mm|
|20 pcs.|20 M-M Jumperwires|BerryBase|100 mm|
|3 pcs.|ESP8266|ESP8266 - D1 Mini, BerryBase|---|

## 2.2 Chemicals and Materials

|Quantity|Material/Substance|Type/Brand|
|:---:|---|---|
|1 kg|sodium chloride||
|1 kg|magnesium chloride hexa hydrate|Dr. Lohmann Diaclean GmbH|
|1 kg|potassium carboante|WHC GmbH|
|3 pcs.|polyethylenfiber membrane|Tyvek 1623E|
|200 g|PLA (poliacitic acid)|Prusa Filament|
|10 l|destilled Water|dm-Drogeriemarkt GmbH + Co KG.|


# 3 Establishing the Stabilization Time

According to the experience of Lukas Schäfer from Long Life for Art the stabilization times for drier humidites takes usually the longest.[^1] Thus the 1st Experiment is done with magnesium cloride which should generate a relative Humidity (rH) of 33.1 % at 21°C.[^2] according to the DKD-R 5-8 standard stabilization is reached 30 min. after beeing within  +-2% rH and +-0,2°K Temperature to the goal values.

The goal temperature is 20°C and goal Humidity 33.1%. These values are chosen because of the current room temperature, as the experiment design does not include a cooling or a heating element. Thus the experiment is placed inside an insulating styrofoam box to shield it from temperature fluctuations. If the temperatures result to be too unstable heatingmat for reptiles could be used to temperate the environment. In this case a temperature above the room temperature (i.e. at 25°C resulting in 32,8% rH) should be used.

## 3.1 Measuring room temperature
The roomtemperature is measured unsing the calibrated testo 175 H1 (last calibration in April 2023).
> Make sure the Datalogger you use has been calibrated before using it as a reference! Once a year is the recommendet calibration intervall.

Interestingly the room temperature of the Thermometer positioned open in the middel of the room showed a temperature of 20.9°C while inside the PP-box inside the styrofoam box it showed a temperature of 19.9°C. 
As the box was open before it was thought to have the same temperature as the surrounding air.
This could be due to different factors: 
- The box was placed on the ground: there could be temperature gradients because of the hight difference between the bench and the box.
- The box is made out of white styrofoam emmitting less radiation as the dark green cutting matt the Datalogger was placed before.

This already shows the problems when calibrating a sensor. As small differences in the environment can have a noticable effect on the measurement.

Repeating the measurement with the box on top of a rolling cart created measuremnts of 20,4°C outside and 20,8°C inside the box.


## 3.2 Cleaning the Experiment Hardware

A box and lid are cleaned using a small amount of detergent and then rinsed thoroughly with tap water. Afterwards they are rinsed again with destilled Water to remove other minerals (this step might be overkill).

The Feet, with the PE-fiber-membrane where cleaned with a vaccuum.

## 3.3 Configuring the Datalogger
The datalogger was configured using the proprietary but free software testo Comfort 5. Temperature and rH are logged every 10 min. The start and the end of the sequence are given manually.
The experiment was started on June 9th 2023 at 14:17.

## 3.4 Preparation of the salt-solution

300g of magnesium chloride where poured on the bottom of the box, roughly 3mm deep. Then destilled Water was added.
As the Magnesium chloride desolves rather quickly a smaller quantity of water would have been sufficient. 50 g of salt where added afterwards to avoid that all salt cristals desolve. 
The right way to create salt solutions is difficult to establish. MostraLog asks for the salt only to be wetted, while Robert Smith says it's enough to have undesolved cristals in the solution.


[^1]: telefon call on May 31st 2023
[^2]: MostraLog calibration boxes manual
