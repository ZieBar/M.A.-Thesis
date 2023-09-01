Requirements by Standard for Museums and Archives
===

This file contains notes on different standards, position papers and templates for best practices that on the enviornment (especcially on relative Humidity) of museums and archives.
The differtent documents are analized regarding the humidity values that should be maintained and the requirements on the monitoring systems.


# 1    Deutscher Museums Bund - Empfehlung zur Energieeinsparung durch die Einführung eines erweiterten Klimakorridors bei der Museumsklimatisierung
> Recommendation <br>
> written in September 2022 in view of the energy crisis due to the attack of Russia on Ukrain

||max.|min.|maximum fluctuation|
|---|---|---|---|
|Temperature|18 °C (15 °C for storage)|26 °C|2 °K|
|relative Humidity|40 %|60 %|5 %|

No specification of the monitoring system.

# 2    DIN 15757 - Erhaltung kulturellen Erbes - Festlegungen für Temperatur und relative Luftfeuchte zur Begrenzung klimabedingter mechanischer beschädigungen an organischen hygroskopischen Materialien - September 2010

> Standard

# 3    EN 16242:2012 Conservation of cultural heritage - Procedures and instruments for measuring humidity in the air and moisture exchanges between air and cultural property (german translation)

> Standard

## Minimum requirement for measureing equipment
||dew point mirror|electronic psychrometer|capacitive hygrometer| impedance-hygrometer|hair-hygrometer|
|---|---|---|---|---|---|
|degree of accuracy|very high|high|medium|medium|low|
|measuring range| -20 °C to 50°C | 5 % to 95 % <br> 10 °C to 50°C|5 % to 95 % <br> -10 °C to 50°C|5 % to 95 % <br> -10 °C to 50°C|35 % to 95 % <br> -10 °C to 50°C|
|Uncertainty|0.5 °C|2 %|3 %|3 %|10 %|
|Reproducability|0,2 °C|1 %|2 %|2 %|5 %|
|Resolution|0,1 °C|1 %|1 %|1 %|2,5 %|
|Response time to complete 63% of step (no ventilation)|n.A.|required ≤ 2 min <br> desireble ≤ 1 |required ≤ 5 min <br> desireble ≤ 2 |required ≤ 5 min <br> desireble ≤ 2 |10min|
|Stability (max. drift)|≤ 0,2 °C p.a.| ≤ 2% p.a.|≤ 2% p.a.|≤ 2% p.a.|≤ 5% p.m.
|inspection intervalls|6 months| device: 1 year <br> textile: daily or before use| 1 year| 1 year| 3 months|
|use cases| calibration, Labroratory| 1. inspection of other sensors <br> 2. occasional *in situ* measuremnts| occasional *in situ* measuremnents or regular monitoring|occasional *in situ* measuremnents or regular monitoring|only in  acceptional ases for vissual inspection|

## On the calibration of equipment:
- regular calibration required to ensure a high degree of measurement precision
- one of two needs to be fullfilled
    - all devices need a certificate by a laboratory accredetied according to EN ISO/IEC 17025
    - at least one reference device needs to be calibrated by a laboratory EN ISO/IEC 17025
- referece needs to be more precise than regular devieces
- regular inspection of devices
- if a device shows values different from the manufacturers specification a calibration is needed
- inspection can be done by verifying a measurement by comparison of the values of *in situ* measurement with a calibrated device 

## Personal notes
- Calibration is not defined in the scope of this standard
- The notion that a calibration is neccessary **after** a deviation is registered, shows that maybe calibration and adjustment have been interchanged here. A calibration is the process that shows the deviation of a measured value to a reference regarding also the uncertainty of the measurement, **not** adjusting the measured value to the "true" value.<br>

To register a deviation of a value from maufactures specification is the whole scope of a calibration!
- hysterisis of capacitive sensors is not mentioned
    - unclear if icluded in measurment uncertainty
- How do reproducability and uncertainty interact? should reproducability be added to the uncertainty?
- Reproducability and measurment uncertainty are defined in a way that could be misinterpreted

Reproduzierbarkeit: Fähigkeit eines Messgeräts, bei aufeinanderfolgenden Messungen derselben Messgröße unter gleichen Bedingungen innerhalb gewisser Grenzen den gleichen Messwert erneut zu erzielen
Messunsicherheit: die Messunsicherheit ist eine nicht-negative Größe, welche die Streuung von Werten beschreibt, die einer bestimmten Messgröße zugeschrieben wird. 

# 4    ASHRAE 2019 Chapter 24

## Requirements on environment
- 6 Categories:

|Category|Longterm outer limits                  |seasonal adjustment          |short-Term fluctutations|
|--------|---------------------------------------|-----------------------------|------------------------|
|AA      |>= 35 % rH, <=65 % rH, >= 10°C, <= 25°C|no change in rH +/- 5 K      |+/- 5 % rH, +/- 2 K     |
|A1      |>= 35 % rH, <=65 % rH, >= 10°C, <= 25°C|+/- 10 % rH, + 5 K, -10 K    |+/- 5 % rH, +/- 2 K     |
|A2      |>= 35 % rH, <=65 % rH, >= 10°C, <= 25°C|no change in rH, + 5 K, -10 K|+/- 10 % rH, +/- 2 K    |
|B       |>= 30 % rH, <=70 % rH, <= 30°C         |+/- 10 % rH, + 10 K, -20 K   |+/- 10 % rH, +/- 5 K    |
|C       |>= 25 % rH, <=75 % rH, <= 40°C         |            ---              |not continually over 65% rH and rarly over30°C|
|D       | <=75 % rH                             |                             |not continually over 65% rH|

## Requirements on Monitoring-System
- Sensor accuracy +/- 0.2 K, +/- 2 % rH or better
- ideally dew-point sensors
- Placement: in collection spaces
- standalone Dataloggers to evaluate performance
- Calibration: "Institutional staff should be provided with guidance for eventual replacment or recalibration to provide continued accuracy in operation" (p. 24.33)
- factory recalibration or replacment better than field calibration


# Deutscher Museums Bund - Facility Report
> Template
Chapter 7.3 is concerned with the environment of the exhibition and its monitoring. 
- no specific values given
- asks if environmental conditions (relative humidity and temperature) are monitored
    - more specific questions on calibration of the monitoring system, as well as its specifications are posed
