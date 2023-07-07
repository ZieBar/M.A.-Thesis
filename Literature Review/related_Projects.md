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

**Overall Open-o-Meter Score: 0/8**

### Remarks
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

**Overall Open-o-Meter Score: 0.5/8**
> Even though the Open-o-Meter doesn't allow for half points, the effort made in the article to show the components used and the working of the program is better than in other publications. Though the article is not open access...

### Remarks
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
- Arduino UNO R3 
- DHT22
- LM35
- XBee-Shield
- RTC-Module
- HC-06 (Bluetooth-modem)
- SD-Card module
- ATX Powersupply and solarpanel

### Technologies
- MATLAB for Data analisys and processing

### Other interesting information regarding this research
none
### Open-o-Meter
|License|Availability of files|Bill of materials|Assembly instructions|Editability|Version control system|Guidance on collaboration|Issue tracking system|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|

**Overall Open-o-Meter Score: 0/8**
>Though explicitly states to develope an open source solution!

### Remarks
For the title and the statements in the text a dissapointingly low score! The system though **using** OSH is in and of itself **not** open source!
All in all the article is still worth reading as it contains a lot of infomation on technologies, their advantages an limitations, espacially regarding wireless communication. These statments where confirmed in conversation with other experts in the field of electronics and wireless communications.[^2]

# Citations
[^1] **Bonvoisin et al. 2018:** Jérémy Bonvoisin, Robert Mies, Measuring Openness in Open Source Hardware with the Open-o-Meter, in: Envisaging the future manufacturing, design, technologies and systems in innovation era, 6th CIRP Global Web Conference, no date, 2018.
[^2] Thanks to from IoT-plan GmbH for sharing their knowledge and experience.
