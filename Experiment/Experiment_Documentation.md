Documentation of the experiment using saturated salt solutions
===
<br/><br/>
> __+++ important note: when dealing with chemicals and tools read the datasheet and take neccessary precautions for personal and environmental protection +++__

<br/><br/>

# 1 Scope of the Experiment
This experiment is designed to test low-cost sensors for Open-Source environment monitoring in a precise but cost-effective way. According to German calibration-standards, this method is not suitable for a proper and precise calibration of scientific equipment that needs the highest possibile accuracy. It is however suitable for testing sensors to establish if a proper calibration is needed.
This experiment should, if properly executed, be able to show the precision  and accuracy of a sensor in  a given environment. Hysteresis-effects can not be demonstrated.

## 1.2 Sensors tested in this experiment
In this experiment the following sensors are tested.

<br/><br/>
|Sensors |	DHT22	| BME280	| BME680	| SHT31	| SHT41	| SHT85 |
|---------|---------|-----------|-----------|-------|-------|-------|
|Communication-protocol |	One-Wire	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C |

![Abbildung der 6 Sensortypen](https://github.com/ZieBar/M.A.-Thesis/blob/e8368e8d98c811b5c88421134cfb4076032809b6/Experiment/Abbildungen/_DSC3556.jpg)
Picture of the tested sensors
<br/><br/>



# 2 Materials and tools

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

## 2.2 Chemicals and materials

|Quantity|Material/Substance|Type/Brand|
|:---:|---|---|
|1 kg|sodium chloride||
|1 kg|magnesium chloride hexa hydrate|Dr. Lohmann Diaclean GmbH|
|1 kg|potassium carboante|WHC GmbH|
|3 pcs.|polyethylenfiber membrane|Tyvek 1623E|
|200 g|PLA (poliacitic acid)|Prusa Filament|
|10 l|destilled Water|dm-Drogeriemarkt GmbH + Co KG.|


# 3 Establishing the stabilization time

According to the experience of Lukas Schäfer from Long Life for Art, the stabilization times for drier humidites takes usually the longest.[^1] Thus the first experiment is done with magnesium cloride which should generate a relative humidity (rH) of 33.1 % at 21°C.[^2] according to the DKD-R 5-8 standard stabilization is reached 30 min. after beeing within  +-2% rH and +-0,2°K temperature to the goal values.

The goal temperature is 20°C and goal humidity 33.1%. These values are chosen because of the current room temperature, as the experiment design does not include a cooling or a heating element. Thus the experiment is placed inside an insulating styrofoam box to shield it from temperature fluctuations. If the temperatures result to be too unstable, heating-mat for reptiles could be used to maintain a constant temperature ovf the environment. In this case should be used a temperature above the room temperature (i.e. at 25°C resulting in 32,8% rH).

## 3.1 Measuring room temperature
The room temperature is measured unsing the calibrated test 175 H1 (last calibration in April 2023).
> Make sure the data-logger you use has been calibrated before using it as a reference! Once a year is the recommended calibration intervall.

Interestingly the room temperature of the thermometer positioned open in the middle of the room showed a temperature of 20.9°C, while inside the PP-box inside the styrofoam box it showed a temperature of 19.9°C. 
As the box was open before, it should have had the same temperature as the surrounding air.
This could be due to different factors: 
- The box was placed on the ground: there could be temperature gradients because of the height difference between the bench and the box;
- The box is made out of white styrofoam, emmitting less radiation as the dark green cutting mat on which the data-logger was placed before.

This already shows the problems when calibrating a sensor: small differences in the environment can have a noticeable effect on the measurement.

Repeating the measurement with the box on top of a rolling cart showed a temperature of 20,4°C outside and 20,8°C inside the box.


## 3.2 Cleaning the experiment hardware

A box and lid are cleaned using a small amount of detergent and then rinsed thoroughly with tap water. Afterwards they are rinsed again with destilled water to remove other minerals (optional).
The stands with the PE-fiber-membrane were cleaned with a vacuum.

## 3.3 Configuring the data-logger
The data-logger was configured using the proprietary but free software Testo Comfort 5. Temperature and rH are logged every 10 min. The start and the end of the sequence are given manually.
The experiment was started on June 9th 2023 at 14:17.

## 3.4 Preparation of the salt-solution

300g of magnesium chloride where poured on the bottom of the box, roughly 3mm deep. Then destilled water was added.
As the magnesium chloride dissolves rather quickly, a smaller quantity of water would have been sufficient. 50 g of salt where added afterwards to avoid that all salt crystals dissolve. 
The right way to create salt solutions is difficult to establish. MostraLog asks for the salt only to be wetted, while Robert Smith says it's enough to have undissolved crystals in the solution.

## 3.5 Starting the measuring procedure

After the salt solution was prepared, the three stands where assembled and placed inside the box. The reference-data-logger was placed with the sensor in the middle of the box. To mimic the actual experiment conditions, the three breadboards with the sensors and microcontrollers where put inside the box as well. 
The closed box was placed inside the isolating polystyrol box and the lid closed.

### Friday, June 9th 2023, 14:17

Measuring started
On monday June 12th the box can be opend and the environment can be controlled using the dataloggers display. If a relative Humidity of 33.1% at 21°C was achieved, the experiment will be stoped.

#### Monday, June 12th 2023, 9:31

relative Humidity: 33,9 %
Temperature 20,6 °C

I will extend the time frame for another 24 hours to check if it will arrive at 33.2%.





[^1]: telefon call on May 31st 2023
[^2]: MostraLog calibration boxes manual
