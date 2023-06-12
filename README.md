
The contents of this repository are licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
CC BY-SA 4.0

M.A.-Thesis on open-source dataloggers for museums and archives
===
This repository is used to exchange information and data with thesis supervisors and others
This Reopository contains Informations, Models and Code created for my M.A. thesis at the HTW-Berlin from May to September 2023 

# Topic of the thesis
The thesis is looking in to the possibilities and limitations of open-source dataloggers. 
As collections grow and funding for institutions like museums decline, the people in charge of the preservation of collections are faced with a dilemma. Preventive conservation tries to develop tools, like risk management, that can help to minimise the risk for damage and thus the need of frequent, laborintensive, and thus costly, conservation treatments.[^1] One important factor is the control of relative humidity and temperature as both can be the reason for biological, mechanical or chemical damage.[^2]
Control of relative humidity and temperature has been a topic of conservation sience as early as the early 20th century and conservators opted for a as stable as possibile environement.[^3] Today, in face of climate change and high energy prices, the museum environment is again topic of discussion.

The acqusion of data, through scientific lab experiments and monitoring of collections is a key component for decision making. Commercial dataloggers, once setup, offer an easy way to measuring museum environments either by periodically downloading the data to a PC or even remotly via radio communication. The downside are the high acquisition costs and the dependency on the continuation of support by the manufacutrers.
Free and opensource software (FOSS) and free opensource hardware (FOSH) could be alternatives to proprietary commercial products, offering less costly and more flexible, repairable and extandable solutions, that can be adapted to the needs of the user.

# Related projects and scope of the thesis
This is not the first research looking in to this topic. While most projects try to create a whole data-logging-system or concentrat on the arcitecture for data acquisition and storage, this project concnetrates on the sensors that could be used for such projects. This has two reasons: 

## Methodology
Projects like the smArts_Museum_V1[^4] use the comparison between a calibrated and precise commercial sensor (testo 175 H1) and the smArts_Museum_V1 (using a DHT22 or AM2302 Sensor) in an in situ application. This procedure is not optimal to gauge the precision and accuracy of a sensor. Also effects like hysterisis can not be shown this way.
Thus I want propose two different methodologies that should be able to approximate a proper calibration procedure for these sensors.

## Empowering people to create diy-solutions
I want to saperate the single senor-modules from the products. Meaning: the precision of a product like the smArts_Museum_V1 does not depend on the datalogger in and of it self, but largly on the sensor used and vice versa: if I want to use a sensor like the DHT22 I don't need to neccessarily use the smArts_Museum_V1. By focusing on the sensors I want to give people, developiong projects or experiments, an overview of possibile components and their limitations, so they can choose the appropriate one.



[^1]: Waller, R. Conservation risk assessment: A strategy for managing resources for preventive conservation. Studies in Conservation 39, 12–16, 1994.

[^2]: Maekawa, S., Beltran, V.L., Henry, Environmental Management for Collections. Alternative Preservation Strategies for Hot and Humid Climates, Los Angeles, 2015.

[^3]: Staniforth, S. (Ed.) Historical Perspectives on Preventive Conservation, Readings in Conservation. Getty Conservation Institute, Los Angeles,, 2013.

[^4]: Gaudenzi Asinelli, M., Serra Serra, M., Molera Marimòn, J., Serra Espaulella, J., The smARTS_Museum_V1: An open hardware device for remote monitoring of Cultural Heritage indoor environments | Elsevier Enhanced Reader. Hardware X 4, 2018, 2–18. https://doi.org/10.1016/j.ohx.2018.e00028
OSF Repositorium of the project: https://osf.io/w963q/#!

