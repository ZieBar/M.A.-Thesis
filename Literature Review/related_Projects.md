Related Projects
===
This file containes small excerpts of other projects developing open source monitoring systems for cultural heritage sites, museums and archives.
Every excerpt gives information the research goals and results, the technologies and a list of components used for the project and interesting information given by the text. Lastly the project is rated using the Open-o-Meter developed by Bonvoisin et al. 2018.
# The Open-o-Meter
The Open-o-Meter is a framework developed by Bonvoisin et al. 2018 to rate the openness of a project. As  the term open source hardware (OSH) is interpretet quite diffriently in practice and can lead to "openwashing" of products and projects, this framework helps to understand how close a project comes to fullfill the 4 freedoms associated with the open source movement.[^1]
The Open-o-Meter uses 8 criteria valuating  product (first five) and process (last three) openess. Each criteria gets either one point if fullfilled or non if the criteria is not met. A fully compliant open source project thus would get 8 points, while a conventional proprietary product would get zero points. 
Using the Open-o-Meter one can not only rate a project but also establish factors that need to worked on in order to improove the openness of a given project.
Following criteria were defined by Bonvoisin et al.
1. Open source compatible license
2. Design files of all product components designed by originator are made publicly available
3. A bill of materials is available
4. Assembly instructions are available
5. All files are released in their original (editable) format
6. All files are maintained in a version control system
7. Guidance on colaboration is provided
8. An issue tracking or equivalent system allows tracing tasks and improvemtn propositions

<br>
<br>

# Literature Review
The following projects and articles where researched using Google Scholar and the BICN-Database. The following Keywords where used: "open source", "cultural heritage", "monitoring" and "environment". In total 13 artcles where found, published between 2016 and 2022. A research on the Open Science Framwork (osf.io) resulted in a 14th project currently underway.
<br>
<br>

## 1 Monitoring Heritage Buildings with Open Source Hardware Sensors: A Case Study of the Mosque-Cathedral of Córdoba
>Mesas-Carrascosa, F.J.; Verdú Santano, D.; Meroño de Larriva, J.E.; Ortíz Cordero, R.; Hidalgo Fernández, R.E.; García-Ferrer, A. Monitoring Heritage Buildings with Open Source Hardware Sensors: A Case Study of the Mosque-Cathedral of Córdoba. Sensors 2016, 16, 1620. https://doi.org/10.3390/s16101620 


>### **Case study**

>Open Acess



### Research goals
- show the practicality of OSH Dataloggers for humidity and temperature. (p. 2)
- casestudy
### Results
- micorclimate monitoring system was developed **using** OSH
- System has been able to quantify the effects of exterior conditions on interior environment providing useful uinformation for conservation
- according to authors: "OSH characteristics, such as low acquisition costs and easy costumization, can eliminate obstacles associated with proprietary systems." (p. 12)

### List of components
- Arduino UNO R3 
- DHT22
- RTC-Module DS1307
- SD-Card module
- external Powersupply and Battery

### Technologies
- MATLAB for Data analisys and processing

### Other interesting information regarding this research
none
### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0/8

### Notes
The project explicitly states the **use** of OSH instead of the development of a monitoring system. Thus the low score is not in and of itself a defact. 
Neither in the article nor via google search was it possibile to find any further information (github repository or similar).

<br>
<br>


## 2 Open-Source Digital Technologies for Low-Cost Monitoring of Hisotrical Constructions

>Camilo Basto, Luca Pelà, Rolando Chacón,
Open-source digital technologies for low-cost monitoring of historical constructions, 
Journal of Cultural Heritage,
Volume 25,
2017,
Pages 31-40,
ISSN 1296-2074,
https://doi.org/10.1016/j.culher.2016.12.003.
(https://www.sciencedirect.com/science/article/pii/S1296207416304290)

>### **Case study** (mainly)

> **Not** Open Acess (though available on Research Gate)

### Research goals
- "...possibility of building and testing a novel reproducible DIY system for structural health monitoring of historical structures" (p. 2)

### Results
- "...preliminary good results indicate possibile paths of improvement, as well as the possibility to extend the methodology..." (p. 14)
- "Open-source DMF [Digital Modeling and Fabrication] technologies and DIY [Do-It-Yourself] deployments will be continously enhanced, used and afforded by many more perople." (p. 16)
- lower costs lead to "massive digitalization", "open-source initiatives sharing digital data on monitored historical  structures might provide a higher understanding and dissemination of knowledge" (p. 15)
### List of components
- Arduino UNO R3 
- DHT22
- LM35
- XBee-Shield
- RTC-Module
- HC-06 (Bluetooth-modem)
- SD-Card module
- ATX Powersupply and solarpanel

### Technologies
- Bluetooth
### Other interesting information regarding this research
none
### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0.5|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0.5/8
> Even though the Open-o-Meter doesn't allow for half points, the effort made in the article to show the components used and the working of the program is better than in other publications. Though the article is not open access...

### Notes
Even though the project explicitly promotes the use of OSH and the open sharing of data, no information on a repository could be found. Additionally the fact that the article was pubblished in a non open access journal makes it difficult to get the information and promote the concept.

## 3 An Open-Source, Internet of Things Approach for Remote Sensing in Museums

> Pablo Londero, Theresa Fairbanks-Harris & Paul M. Whitmore (2016) An Open-Source, Internet-of-Things Approach for Remote Sensing in Museums, Journal of the American Institute for Conservation, 55:3, 166-175, DOI: 10.1080/01971360.2016.1217671 

>### **Conception and Case study** 

> **Not** Open Acess (though available on Research Gate)

### Research goals
- "...demonstate one open-source approach to WSNs [wireless environmental monitoring], with the goal of balancing the various trade-offs to enable more widespread use in cultural heritage" (p. 2)

### Results
- "...results demonstrate an ability to realize some of the potential advantages of an open-source WSN measurement architecture. " (p. 173)
- "sensor was visually  unobstrusive, inexpencive, and capable of transmitting data in real time." (p. 173)
- multiple useres were able to monitor the data
- "We have successfully tested a WSN architecture that is entirely open-source..." (p. 174)
- "We find this open-source WSN architecture to potentially be quite useful for a variety of measurement problems in cultural heritage." (p. 174)
- "It is costumizable while requiring hobbyist-level proficiency in programming and electronics..." (p. 174)

### List of components
- MSP430 (µCU) 
- Vishay TEMD6010FX01 (photodiode)

### Technologies
- SWAP transmission protocoll for direct transmission between WSN (Wireless Sensor Node) and Gateway (below 868 MHz)
    - allowes for up to 256 nodes (p.170)
- Largato as Opensource Webserver
- NodeRed to interact with data


### Other interesting information regarding this research
- high frequency waves provide faster data transmission (p. 169)
- lower frequencies are better in longdistance and penetration (p. 169)
- it is important to look up allowed frequencies fot the purpose which depend on the region (p. 168)
### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

> #### Overall Open-o-Meter Score: 0/8
>Though explicitly states to develope an open source solution!

### Notes
For the title and the statements in the text a surprinsingly low score! The system though **using** OSH is in and of itself **not** open source!
All in all the article is still worth reading as it contains a lot of infomation on technologies, their advantages an limitations, espacially regarding wireless communication. These statments where confirmed in conversation with other experts in the field of electronics and wireless communications.[^2]

## 4 Low cost monitoring approach for the conservation of frescos: The crypt of St. Francesco d’Assisi in Irsina (Basilicata, Southern Italy)

> Maria Sileo, Fabrizio Terenzio Gizzi, Nicola Masini,
Low cost monitoring approach for the conservation of frescoes: The crypt of St. Francesco d’Assisi in Irsina (Basilicata, Southern Italy),
Journal of Cultural Heritage,
Volume 23, Supplement,
2017,
Pages 89-99,
ISSN 1296-2074,
https://doi.org/10.1016/j.culher.2016.11.011.
(https://www.sciencedirect.com/science/article/pii/S1296207416304009) 

>### **Case study** 

> **Not** Open Acess (though available on Research Gate)

### Research goals
- "Comparative analysis of the two systems", "low cost aparatus [...] based open source hardware and software" and "standard commercial system". "The basic idea is to try to reduce significantly the purchase and maintanence costs, so as to encourage the use of low cost monitoring systems on a large scale." (p. 1)

### Results
- "...the comparison of the data collected from the two different systems does not seem to highlight substantial differences between the LC and the CS systems, highlighting the potential of low cost systems for extensive monitoring of cultural heritage." (p. 10 f.)

### List of components
- no information provided other than "based on Arduino" (p. 1)

### Technologies
n.A.

### Other interesting information regarding this research
none

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

**Overall Open-o-Meter Score: 0/8**

### Notes
An overall unremarkable article for the scope of this research. Methodology for comparison is not suited and no information provided for replication of the experiment.

## 5 Wireless Sensor Platform for Cultural Heritage Monitoring and Modeling System

> Klein, L.J.; Bermudez, S.A.; Schrott, A.G.; Tsukada, M.; Dionisi-Vici, P.; Kargere, L.; Marianno, F.; Hamann, H.F.; López, V.; Leona, M. Wireless Sensor Platform for Cultural Heritage Monitoring and Modeling System. Sensors 2017, 17, 1998. https://doi.org/10.3390/s17091998 

>### **Case study** 

> Open Acess

### Research goals
- assesing the environment of a museum using wireless sensor nodes (focus is on the assesment of the environment not on the sensor nodes)

### Results
- datalogging is good

### List of components
- SHT3x
- STM32L4x based on ARM Cortex-M (µCU) => "...due to it's wide adoption." (p.573)
- CC1101EMK868-915 (radio module)
- MultiConnect Conduit MTCDT-210A by Multitech (Gateway)

### Technologies
- modeling of environment

### Other interesting information regarding this research
- ICOM-CIDOC provides good practices on museum documentation based on ISO 21124:2014 (p. 576)

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

> #### Overall Open-o-Meter Score: 0/8

### Notes
- not an open source project
- term doesn't appear in text
- still interesting to argue for the deployment of more dataloggers

## 6 An energy-efficient internet of things (IoT) architecture for preventive conservation of cultural heritage

> Angel Perles, Eva Pérez-Marín, Ricardo Mercado, J. Damian Segrelles, Ignacio Blanquer, Manuel Zarzo, Fernando J. Garcia-Diego,
An energy-efficient internet of things (IoT) architecture for preventive conservation of cultural heritage,
Future Generation Computer Systems,
Volume 81,
2018,
Pages 566-581,
ISSN 0167-739X,
https://doi.org/10.1016/j.future.2017.06.030.
(https://www.sciencedirect.com/science/article/pii/S0167739X17313663)

>### **Conception and Case study** 

> Open Acess

### Research goals
- "...asses the performance of our proposal" => LoRa or Sigfox based Sensor Nodes (p. 567)

### Results
- "The standard defacto LoRa and Sigfox in the ISM [Industrial, Scientific and Medical - Band of frequencies]of 868 MHz were found to be suitable for monitoring artworks" (p. 579)
- "The elected wireless technology copes with the need of reaching relative long distances and pass through thick walls that are typical scenarios in artwork containersor open archaeological sites." (p- 579)
- "We propose using Infrastructure Manager and EC3 combined with cloud technologies to make the architecture open and reproducible so that anyone could deploy an equivalent virtual infrastructure on a public or on-premise cloud."

### List of components
- SHT3x
- STM32L4x based on ARM Cortex-M (µCU) => "...due to it's wide adoption." (p.573)
- CC1101EMK868-915 (radio module)
- MultiConnect Conduit MTCDT-210A by Multitech (Gateway)

### Technologies
- LoRa and Sigfox
- Mongo DB as cloud-service

### Other interesting information regarding this research
- ICOM-CIDOC provides good practices on museum documentation based on ISO 21124:2014 (p. 576)

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

> #### Overall Open-o-Meter Score: 0/8

### Notes
Does not use the term OSH

## 7 The smARTs_Museum_V1: an open hardware device for monitoring of Cultural Heritage indoor environments

> Mainardo Gaudenzi Asinelli, Moisès Serra Serra, Judit Molera Marimòn, Jordi Serra Espaulella,
The smARTS_Museum_V1: An open hardware device for remote monitoring of Cultural Heritage indoor environments,
HardwareX,
Volume 4,
2018,
e00028,
ISSN 2468-0672,
https://doi.org/10.1016/j.ohx.2018.e00028.
(https://www.sciencedirect.com/science/article/pii/S2468067217300834)

>### **Conception and Case study** 

> Open Acess

### Research goals
- "desinign, prototyping and experimenting low cost, easy to use and to customize, free and open source software and hradware device for remote monitoring of typical indoor Cultural Heritage  environments..."(p. 2)

### Results
- " The initial aim was to assemble a device being low cost, free and open software and hardware, having MCU and sensors easy to assemble and to replace, easy to program and to use, and showing Wi-Fi capacity for remote data acquisition. These objectives have been all accomplished satisfactorily." (p. 17)
- "The project will remain free and open so to potentially constitute a solid base for implementations by other subjects;"
- "The smARTS_Museum_V1 prototype has been successfully tested by starting the monitoring of the microenvironment of an exhibition case..."
- "...the IoT platform ‘ThingSpeak’ was evaluated positively, but its intrinsic constraints suggested that different solutions for data storing and visualization should be adopted."
- con: "...the Wi-Fi capability does not automatically ensure data acquisition: main constraints are the robustness of the wireless connection – often reduced by architectural and logistic complexity, or simply by a limited Wi-Fi range of the Wi-Fi station; and the fact that the Wi-Fi station should be always on." (p. 16)
- pro: "conceiving each data logger as a standalone device" 
- Radio frequencies => additional costs for gateway an server

    -  Low cost: 70–90% cost reduction if compared to proprietary devices (see Section 4) 
    - Customizable: easy replacement of components; easy to expand by adding additional sensors using free pins and I2C bus; easy to change and adapt the case shape and color to reduce visual impact in typical exhibition spaces 
    - Durability and low maintenance: low power consumption allows long-term functioning, so limiting maintenance 
    - Wi-Fi: remote data collection, and real-time visualization and management


### List of components
- DH22
- ESP8266 - 01
- voltage regulator LDO MCP1700-3302E/TO
- Battery Lithium TR 18650, 02600mAh 3.7 V
- costum designed case to be printed on 3D-printer

### Technologies
- Wifi connection
- ThingsSpeak platform

### Other interesting information regarding this research
- PLA-filament more eco friendly than PVC (p. 6)

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|1|1|1|0|0.5|1|0|1|

>#### Overall Open-o-Meter Score: 5.5/8

some of the files are available in en editable format

### Notes
#### Article
- does not list OHS as Keyword on title page
- building instructions of some sort provided in article (describes important modifications)
    - potential users probably not very well versed in programming and electronics => clear, easy to unserstand step by step instructions needed! => 0 points
- methodology to verify imployability of DHT22 (in situ testing with testo 175 H2) is not suitable => reference not very precise, not tested in a controlled environment
- wrong article cited about testing DHT 22 (its reference No. 31 not 30) + methodolgy in article not well described thus not reproducable
- mention of development of open source-cloud server for cultural heritage monitoring is mentioned, cited  reference is a workshop, thus gives no further information
- problems, which are mentioned in the text but not in the conclusion, i.e. time shift of measurements (at end of measurement period reached approximatly 4 minutes between P2 and P3 thus data needed to be processed manually (p. 10)) + loss of data due to platform, battery faliure (both mentioned in conclusion) => doesn't seem ready for deployment in longterm realworld applications

#### Data available on OSF
- Code needs to be updated => DHT 22 is read only once per cycle thus giving out only the data of the last reading (see data sheet)[^3]
- timeshift could maybe be eliminated using the millis()-function, which measures the time since the stard of the program, thus eliminating wake-up, connection and measurement times
- only few files in an editable format
- no indication on how to colaborate or if colaboration is welcomed

## 8 Preservation of Cuultural Heritage Sites using IoT

> M. Maksimović and M. Ćosović, "Preservation of Cultural Heritage Sites using IoT, 2019 18th International Symposium INFOTEH-JAHORINA (INFOTEH), East Sarajevo, Bosnia and Herzegovina, 2019, pp. 1-4, doi: 10.1109/INFOTEH.2019.8717658.

>### **Conception and Case study** 

> Open Acess

### Research goals
- "...proposes an effective and affordable solution for the monitoring of preservation conditions of the Church based on the utilization of modern Information and Communication Technologies (ICT) and services." (p. 1)
- "... first step towards the realization."

### Results
- "...general structure and main design principles using the three-layer IoT architecture" (p. 4)


### List of components
n.A.
### Technologies
n.A.
### Other interesting information regarding this research
- framwork of 3 layer IoT architecture (p. 2f.)
    - Perception layer (Sensor Nodes)
    - Network layer (transmission protocol for sending data)
    - Application layer (data storage, processing and analysis)

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0/8

Not planed as open source project.

### Notes
- does not explicitly state the intent of using or developing OSH
- cites article No. 1 as related work (only mention of OSH)
- interesting insites on the general architecture

## 9 An Internet-of-Things End-User Development Approach to Environmental Monitoring of Cultural Heritage Archives

>Maceli, M.G. (2019). An Internet-of-Things End-User Development Approach to Environmental Monitoring of Cultural Heritage Archives. In: Malizia, A., Valtolina, S., Morch, A., Serrano, A., Stratton, A. (eds) End-User Development. IS-EUD 2019. Lecture Notes in Computer Science(), vol 11553. Springer, Cham. https://doi.org/10.1007/978-3-030-24781-2_10

>### **User Survey + development of prototype** 

> Open Acess

### Research goals
- What end-user development behaviors might archivists want to engage in?
- How well are these supported by current open-source Internet-of-Things technologies? (p. 2)
- a final prototype is constructed, and the implications for the study and practice of end-user development are considered

### Results
- "...design and development of an open-source system prototype, giving an opportunity to reflect upon the challenges and opportunities of the intersection of Internet-of-Things technologies and end-user development behaviors" (p. 156)
- Systems need to allow:
    - modifying data reports to suit various stakeholders (p. 154)
    - physically customizing the devices to change parts or integrate unobtrusively into the space
- System features:
    - data visualization interface with charts, export options, value ranges and exceeded alerts
    - web and mobile access
    - real-time data, and a date range selector

- unmet needs discussed had been compensated for by performing additional manual work outside of the existing system, or by incurring greater cost to the organization
- These findings were employed in building a prototype system allowing for future end-user modification in use, with an emphasis on using open source and open hardware inasmuch as possible, to potentially facilitate deep customization (p. 152)

### List of components
n.A.
### Technologies
- Grafana for creating a dashboard
### Other interesting information regarding this research
- in general a lot of interesting articles on this topic by the author, which are interesting to have a look at

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0/8

Not planed as open source project in and of it self.

### Notes
- it would have been nice to have a documentation etc. on gitHub or similar

## 10 Internet of things in the archives: novel tools for environmental monitoring of archival collections

> Maceli, M. (2020), "Internet of things in the archives: novel tools for environmental monitoring of archival collections", Records Management Journal, Vol. 30 No. 2, pp. 201-220. https://doi.org/10.1108/RMJ-08-2019-0046 

>### **User Survey + development of prototype** 

> Open Acess

### Research goals
- "..research work was to assess the feasibility of do-it-yourself (DIY) and open source tools for archival environmental monitoring, the assumption was that systems chosen must use robust security measures, without the need for extensive coding or security expertise to deploy." (p. 6)

Q1. Can currently popular general-purpose IoT devices, standards and technologies effectively support the environmental monitoring needs of archivists? (p. 3)

Q2. What barriers to use and/or potential challenges exist?

### Results
- "The constructed system met archivists’ needs well and was generally noted to be easy-to-use, effective, and an improvement on existing systems. This suggests that an IoT approach can support archivists’ needs in this realm." (p. 18)
- "Future work will explore longitudinal case studies of the system within archival organizations, as well as the development of additional features suggested by archivist usability study participants."

### List of components
- Si7021 (rH and T-Sensor)
- Feather M0 RFM95 (µCU) => quite expensive (34,95 $US on Adafruit, 20230708)
-Particle Mesh Xenon (µCU) => discontinued (20230708)
### Technologies
- Grafana for creating a dashboard
- LoRaWAN
### Other interesting information regarding this research
- LoRaWAN as a suitable technology
- good depictions of architectures and general working principles

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0/8

### Notes
- documentation etc. on gitHub or similar would be important

## 11 IoT-MHECHA: A new IoT architecture for Monitoring Health and Environmental parameters in Cultural Heritage and Archaeological sites

> Giuseppe Campobello, Alessio Altadonna, Fabio Todesco, Nicola Donat, "IoT-MHECHA: A new IoT architecture for Monitoring Health and Environmental parameters in Cultural Heritage and Archaeological sites", 2020 IMEKO TC-4 International Conference on Metrology for Archaeology and Cultural Heritage Trento, Italy, October 22-24, 2020

>### **development of system and case study** 

> Open Acess

### Research goals
- "we exploit WSN and IoT technologies in order to define a new architecture for health and environmental monitoring of cultural heritage sites. In particular, the proposed architecture can be profitably used for both indoor and outdoor environments, e.g. museums and archaeological sites" (p. 287)

- it supports a broad range of sensors, from simple temperature and humidity sensors to gas and sound sensors. This large number of available sensors enables a broad range of applications. 
- it integrates several wireless technologies, i.e. ZigBee, Bluetooth, WiFi and LoRa. In particular, the LoRa protocol enables long-range communications (up to tens of kilometers) which is an essential feature for monitoring archaeological sites. 
- the software used to implement the architecture is open source and readily available. Therefore the architecture can be easily replicated and extended.

### Results
- "onitoring of cultural heritage sites named IoT-MHECHA. The architecture supports a wide range of sensors and communication protocols and thus can be profitably used in several applications, considering both indoor and outdoor scenarios" (p. 291)
- "Future work will explore longitudinal case studies of the system within archival organizations, as well as the development of additional features suggested by archivist usability study participants."

### List of components
- Si7021 (rH and T-Sensor)
- Feather M0 RFM95 (µCU) => quite expensive (34,95 $US on Adafruit, 20230708)
-Particle Mesh Xenon (µCU) => discontinued (20230708)
### Technologies
- Octopus for desining NM-GUI
    - Octopus is able to show sensor network topology and enable remote configuration of sensor node parameters, such as sampling period and duty-cycle of the radio interface (p. 289)

### Other interesting information regarding this research
none

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0/8
"Starting from open source software we developed..." (p. 291)

### Notes
- no documentation thus resulting in a non open source product
- also more OSS than OSH

## 12 Development of an IoT Structural Monitoring System Applied to a Hypogeal Site

> De Angelis A, Santoni F, Carbone P, Cecconi M, Vecchietti A, Di Lorenzo F. Development of an IoT Structural Monitoring System Applied to a Hypogeal Site. Sensors (Basel). 2020 Nov 26;20(23):6769. doi: 10.3390/s20236769. PMID: 33256201; PMCID: PMC7730998.

>### **development of system and case study** 

> Open Acess

### Research goals
- "we exploit WSN and IoT technologies in order to define a new architecture for health and environmental monitoring of cultural heritage sites. In particular, the proposed architecture can be profitably used for both indoor and outdoor environments, e.g. museums and archaeological sites" (p. 287)

- it supports a broad range of sensors, from simple temperature and humidity sensors to gas and sound sensors. This large number of available sensors enables a broad range of applications. 
- it integrates several wireless technologies, i.e. ZigBee, Bluetooth, WiFi and LoRa. In particular, the LoRa protocol enables long-range communications (up to tens of kilometers) which is an essential feature for monitoring archaeological sites. 
- the software used to implement the architecture is open source and readily available. Therefore the architecture can be easily replicated and extended.

### Results
- "onitoring of cultural heritage sites named IoT-MHECHA. The architecture supports a wide range of sensors and communication protocols and thus can be profitably used in several applications, considering both indoor and outdoor scenarios" (p. 291)
- "Future work will explore longitudinal case studies of the system within archival organizations, as well as the development of additional features suggested by archivist usability study participants."

### List of components
- Si7021 (rH and T-Sensor)
- Feather M0 RFM95 (µCU) => quite expensive (34,95 $US on Adafruit, 20230708)
-Particle Mesh Xenon (µCU) => discontinued (20230708)
### Technologies
- Octopus for desining NM-GUI
    - Octopus is able to show sensor network topology and enable remote configuration of sensor node parameters, such as sampling period and duty-cycle of the radio interface (p. 289)

### Other interesting information regarding this research
none

### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

>#### Overall Open-o-Meter Score: 0/8
"Starting from open source software we developed..." (p. 291)

### Notes
- no documentation thus resulting in a non open source product
- also more OSS than OSH





# Citations
[^1] **Bonvoisin et al. 2018:** Jérémy Bonvoisin, Robert Mies, Measuring Openness in Open Source Hardware with the Open-o-Meter, in: Envisaging the future manufacturing, design, technologies and systems in innovation era, 6th CIRP Global Web Conference, no date, 2018.
[^2] Thanks to Christian Rudolf and Simon Rietschel from IoT-plan GmbH for sharing their knowledge and experience.
[^3] See also the website of Robert J. Smith for reference https://www.kandrsmith.org/RJS/Misc/hygrometers.html (20230708)
