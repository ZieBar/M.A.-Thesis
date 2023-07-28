Experiment-Beschreibung
===

# 1 Einleitung
Für Open-Source-Datenlogger gibt es eine Reihe möglicher Sensoren. In den meisten Projekten, kommt jedoch nur ein einziger zum Einsatz. Größtenteils ist die Methode zur Untersuchung der Genauigkeit und Verlässlichkeit der Sensoren problematisch. Die Kalibrierung (die Bestimmung der Messungenauigkeiten einer Messeinrichtung) ist ein komplexer Vorgang. Die Richtlinie DKD-R 5-8 des Deutsche Kalibrierdienst (DKD) beschäftigt sich mit dem Kalibrieren von Hygrometern zur direkten Erfassung der relativen Feuchte. Zwei Methoden wären im Rahmen dieser Masterarbeit mit den zur Verfügung stehenden Ressourcen durchführbar:
-	Kalibrierung im Klimaschrank nach Ablauf A1 (Siehe DKD-R 5-8, Kapitel 9.3.2) [^1]
-	Salzlösungen (explizit angegeben als nicht zur Kalibrierung geeignet, aber für Kontrollen ausreichend) [^2]
	
Eine Norm-gerechte Kalibrierung der Sensoren scheint im Rahmen dieser Masterarbeit nicht bzw. nicht in Eigenleistung möglich zu sein. Die beiden Methoden können jedoch genutzt werden um einen annähernden Eindruck der Qualität der Sensoren zu bekommen

---

# 2 Messaufbau

Die Verkabelung und das Messprinzip bleibt bei beiden Möglichkeiten gleich und wird daher hier nur einmal zusammengefasst.
Insgesamt wurden 6 Sensortypen ausgewählt. Von jedem Typ wurden jeweils 3 Exemplare beschafft. Insgesamt müssen also die Daten von 18 Sensoren erfasst und ausgewertet werden.
<br/><br/>

|Sensoren |	DHT22	| BME280	| BME680	| SHT31	| SHT41	| SHT85 |
|---------|---------|-----------|-----------|-------|-------|-------|
|Kommunikation |	One-Wire	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C |

![Abbildung der 6 Sensortypen](https://github.com/ZieBar/M.A.-Thesis/blob/e8368e8d98c811b5c88421134cfb4076032809b6/Experiment/Abbildungen/_DSC3556.jpg)


<br/><br/>

Als Microcontroller-Unit (µCU) wurde der ESP8266 gewählt. Dieser hat den Vorteil, dass er mit WiFi ausgestattet ist und so verschiedene Wege der Kommunikation ermöglicht.
Die Menge der vorhandenen und benötigten Pins bei den µCUs und den Sensoren ermöglicht jedoch nur eine Verbindung zu maximal 6 Sensoren pro µCU. Daher müssen mehrere µCUs eingesetzt werden. Diese könnten die Daten einen zentralen µCU senden, welcher die Daten auf einer SD-Karte speichert, wie auf der folgenden Abbildung gezeigt.
<br/><br/>

![Schematische Darstellung des Messaparats](https://github.com/ZieBar/M.A.-Thesis/blob/fba20ee6c8bb07e88017035b0c5d358485c20e88/Experiment/Abbildungen/Kommunikation.jpg)


Außer dem SHT41 und dem SHT85 haben alle Sensoren mit I2C eine sekundäre I2C-Adresse, diese kann über den ADDR- (STH) bzw. SDO- (BME) Pin aktiviert werden. Da mehr als zwei Sensoren ausgelesen werden müssen, wird im Programm nur die sekundäre Adresse abgefragt. Diese wird sukzessive bei den einzelnen Sensoren Aktiviert. 
<br/><br/>

![Verkabelung der Sensoren SHT31 und BME 280](https://github.com/ZieBar/M.A.-Thesis/blob/main/Experiment/Abbildungen/SHT31%2BBME280_D1Mini_Steckplatine_1.jpg)

<br/><br/>

Die Sensoren BME280 und SHT31 haben sekundäre i2C-Adressen, welche durch die Verbindung des SOD bzw. ADDR aktiviert werden können. Dies geschieht hier durch die violett dargestellten Kabel, welche jeweils mit einem digitalen Pin Verbunden sind. Diese können sukzessive ein oder ausgeschaltet werden.
<br/><br/>

![Verkabeluing der Sensoren BME680 und DHT22](https://github.com/ZieBar/M.A.-Thesis/blob/main/Experiment/Abbildungen/BME680%2BDHT22-D1Mini_Steckplatine.jpg)



Der DHT22 kann durch das One-Wire Protokoll problemlos durch den jeweiligen Digitalen pin ausgelesen werden.

<br/><br/>
![Verkabelung der Sensoren SHt41 und SHT85](https://github.com/ZieBar/M.A.-Thesis/blob/abd98be384f757850d7b44b677a4a5f327b662ce/Experiment/Abbildungen/SHT41%2BExpander_Steckplatine.jpg)

Im Falle des SHT41 und ST85 muss ein Multiplexer für das Auslesen dazwischengeschaltet werden.

<br/><br/>

---
# 3 Prüfung mit gesättigten Salzlösungen 

Eine Bedingung für Open-Source-Hardware ist die breite Verfügbarkeit von Ressourcen zur Herstellung der Geräte.[^3] Die Kalibrierung oder zumindest Prüfung der Sensoren ist in diesem Fall ein wichtiger Teil der Herstellung. Salze wie Natriumchlorid (NaCl) Magnesium Chlorid Hexahydrat (MgCl2 · H2O) und Kaliumcarbonat K2CO3 sind einfach verfügbar und generieren eine Luftfeuchtigkeit, welche relativ stabil bei Temperaturänderungen sind. Jedoch ist diese Methode nach den vorgaben des Deutschen Kalibrierdienstes nicht für Kalibrierungen geeignet.[^4] Bei adequater Nutzung sind sie jedoch für die Überprüfung von Sensoren ausreichend.

<br/><br/>

## 3.1 Material
|Menge|Material|Dimensionen|
|-----|--------|-----------|
|3 Stk.|Box mit Deckel und Dichtungsring (Polypropylen)|5,2 l|
|3 Stk.|Dämmplatte (Polystyrol)|500x1000x20 mm|
|1 kg|Natriumchlorid|-|
|1 kg|Magnesiumchlorid Hexahydrat|-|
|1 kg|Kaliumcarbonat|
|5l|Destilliertes Wasser|-|
|200 g|PLA (Polyacitid-Gemisch) für 3D-Drucker|-|
|9 Stk.|Tyvek 16XXX|88 x 174 mm|

<br/><br/>

## 3.2 Geräte
|Menge|Gerät|Typ|
|-----|-----|---|
|1 Stk.|Thermohygrometer|Testo 175H1|
|1 Stk.|3D-Drucker|Prusa i3 MK3S+|

<br/><br/>

## 3.3 Aufbau

### 3.3.1 Dämmung
Aus den Dämmplatten wird eine Kiste gebaut. Darin werden die drei PP-Boxen positioniert. Die äußere Kiste dient zur thermischen Stabilisierung des Versuchsaufbaus. Ggf. kann diese durch das Auffüllen der Leerräume noch erhöht werden. 

<br/><br/>

### 3.3.2 Ansetzen der Lösungen
Die drei PP-Boxen werden zunächst abgewaschen, mit destilliertem Wasser ausgespült und anschließend mit einem faserfreiem Tuch getrocknet. Anschließend wird in jeweils eine der Boxen ein Salz eingefüllt bis der Boden bedeckt ist welches dann mit destilliertem Wasser benetzt wird, bis eine trüber Mischung entsteht. 
Eine Übersättigung muss vermieden werden. 

<br/><br/>

### 3.3.3 Herstellung der Standfüße

Pro Box werden drei Standfüße (175 x 88 x 45 mm) eingesetzt, sodass die Sensoren und das Referenzgerät oberhalb der Salzlösungen liegen. Diese werden mit dem 3D-Drucker hergestellt und zusammengebaut. 
Das herausnehmbare Gitter soll dazu dienen, eine wasserdampfdurchläßige Membran aus Tyvek® zum Schutz der Sensoren einzulegen.


![gedruckter Standfuss](https://github.com/ZieBar/M.A.-Thesis/blob/e8368e8d98c811b5c88421134cfb4076032809b6/Experiment/Abbildungen/_DSC3610.jpg)

<br/><br/>

### 3.3.4 Positionierung der Sensoren
Da nur ein Referenzgerät zur Verfügung steht, musste der ursprüngliche Messaufbau abgewandelt werden. Nun sollen alle Sensoren gelichzeitig und zusammen mit dem Messgerät in jeweils einer Box positioniert werden. Das Referenzmessgerät wird in der Mitte aufgestellt, während die Breadboards an die Seiten kommen
Die Sensoren können dann mit Verlängerungskabeln ebenfalls in der Mitte positioniert werden, wodurch ein Raum von ca. 175x90x60mm in der Mitte der Box zum eigentlichen Kalibriervolumen wird.

![Positionierung der Sensoren](https://github.com/ZieBar/M.A.-Thesis/blob/9bfccf15ac7a891084de5ca83df9ba364f1dc509/Experiment/Abbildungen/_IGP9685.jpg)

<br/><br/>

## 3.4 Ablauf
### 3.4.1 Berechnen der Angeleichzeit und Messzeitraum
Als erstes muss die Angleichszeit bestimmt werden, in der das Feuchtigkeitsgleichgewicht in der Box hergestellt wird. Diese ist abhängig vom Volumen und der Dichtigkeit der Box, sowie dem Luftstrom und der zu erreichenden Zielfeuchte.  
Hierfür wird die Salzlösung angesetzt, die Füße eingesetzt und der Testo H175 mittig platziert. Visuell kann über das Display des Referenzgerätes das Erreichen der Zielfeuchte kontrolliert und die Daten anschließend ausgewertet werden.
Der Vorgang wird in jeder Box wiederholt. Ggf. kann der Versuch mit und ohne Membran wiederholt werden.

Nach DKD-R 5-8 wird die angleich und Messzeitraum wiefolgt bestimmt:[^5]

![Angleichszeit und Messzeitraum nach DKD-R 5-8](https://github.com/ZieBar/M.A.-Thesis/blob/9bfccf15ac7a891084de5ca83df9ba364f1dc509/Experiment/Abbildungen/Angleichzeit_DKD.JPG)
Abbildung aus der DKD-R 5-8. This picture is lisenced under cc by-nc-nd-license.

<br/><br/>

I) Erreichen einer Abweichung von < 2 % der Relativen Luftfeuchte oder 0,2 °K vom Sollwert  
II) Wartezeit von mind. 30 min  
III) Messwertaufnahme, mind. 10 Messwerte in 10 Minuten  
IV) Wartezeit von 10 Minuten  
V) Wiederholung von III  
Ist die Messabweichung zwischen III und V kleiner als 2 0% der die angestrebte Messunsicherheit, ist eine ausreichende Angelichszeit eingehalten worden.


Da weder ein Heiz- noch ein Kühlelement im Versuchsaufbau vorgesehen sind, wird in diesem Fall eine Temperatur von 21°C als Zieltemperatur und 33,0 % relativer Luftfeuchtigkeit. 
Sollte sich die Temperatur trotz Dämmung als zu instabil erweisen, kann das Experiment mit einer Reptilienheizmatte erweitert werden. Dabei sollte eine Temperatur höher als die Raumtemperatur angestrebt werden (z.b. 25°C bei 32,8% rH). Eine Heizmatte könnte jedoch auch, aufgrund der Hysterese der verbauten Sensoren und der benötigten Reaktionszeit der Heizelemente weitere Unsicherheiten in den Messaufbau einbringen.
<br/><br/>

### 3.4.2 Messung
Nach dem Angleichzeit und Messzeitraum bestimmt wurden, werden die Sensoren mit dem Messgerät in eine Box gelegt und der versuch begonnen. Dies wird für jede der 3 Luftfeuchtigkeiten wiederholt.

<br/><br/>

# 4 Annäherung an die Kalibrierung mit Klimaschrank
Kalibrierverfahren mit Klimaschrank sind nach der Richtlinie des DKD zulässig, verlangen aber einen hohen Aufwand. Die Methode könnte hier Verwendung finden um die Verlässlichkeit der Salzlösungsmethode zu prüfen. Zusätzlich ist der Ablauf A1 ist besonders interessant, da er als einziger in der Lage ist Hysterese Effekte darzustellen, welche auch bei den Salzlösungen nicht dargestellt werden können.
Die Möglichkeit die Sensoren auch bei verschiedenen Temperaturen (z.B. 10°C, 20°C, 30°C und 40°C) zu testen ist ein weiterer Vorteil dieser Methode. So könnte auch die Anwendung in extremerem Klima oder im denkmalpflegerischen Kontext simuliert werden.
Der DKD empfiehlt bei der Kalibrierung die Verwendung einer unabhängigen Normale zur Referenzwertbestimmung. Zusätzlich müssen Einflussfaktoren, wie z.B. die räumliche Inhomogenität, bestimmt werden. 

<br/><br/>

## 4.1 Geräte
|Menge|Geräte|Typ|
|---|---|---|
|1 Stk.|Klimaschrank|unbekannt|
|1 Stk.|Referenzmessgerät|testo 175H1|
|3 Stk.|Standfüße|selbstbau|
<br/><br/>

## 4.2 Aufbau
Je nach Aufbau des Klimaschranks werden die Sensoren und das Referenzgerät im Inneren des Schrankes platziert. Das Referenzgerät liegt misst dabei im Zentrum des Kalibriervolumens.

<br/><br/>

## 4.3 Ablauf
Der Ablauf A1 der DKD-R 5-8 wird als Vorbild für dieses Experiment genommen. Der Ausgangspunkt S0 muss dabei 5% unterhalb des niedrigsten Wertes N1a bzw. N1b liegen. Für jede gewählte Temperatur müsste dann ein Durchlauf gemacht werden.
Zunächst muss, wie bei Möglichkeit 1 die Angleichzeit bestimmt werden. Der Wert wird dann für eine halbe Stunde gehalten, wobei pro Minute eine Messung erfolgt.[^6] 

![Abbildung des Ablauf A1](https://github.com/ZieBar/M.A.-Thesis/blob/main/Experiment/Abbildungen/Ablauf%20A1.JPG)
Abbildung aus der DKD-R 5-8. This picture is lisenced under cc by-nc-nd-license

<br/><br/>
In diesem Experiment sollen Kalibrierwerte von 15 - 90 % relativer Luftfeuchtigkeit, in 15% Schritten, bei 20°C angefahren werden. Die Messzeit wird auf 15 min mit einer Messung pro Minute festgelegt. Die Angleichszeit kann zur Zeit nur geschätzt werden. Als Orientierung dient das Beispiel der DKD-R mit 3 h Angleichszeit.

### 4.3.1 Einflussgrößen [^7]

- Räumliche Inhomogenität
- Zeitliche Instabilität
- Strahlungseinfluss 
- Druckdifferenz
- Strömungsverhältnisse (positionierung der Bezugsnormale und Kalibreirgegenstand parrallel zur Strömungsrichtung)
- Rückwirkungen (z.b. Eigenerwärmung)

#### 4.3.1.1 Räumliche Inhomogenität
Messungen von Temperatur und Luftfeuchtigkeit müssen am Referenzmessort und an den vorgesehenen Messpunkten vorgenommen werden. Abweichung und Verteilung müssen erfasst werden.

#### 4.3.1.2 Zeitliche Instabilität
Zur Erfassung der zeitlichen Instabilität müssen mindestens 30 Messungen in 30 Minuten in regelmäßigen Abständen erfolgen.

#### 4.3.1.3 Strahlungseinfluss
Zur Erfassung des Strahlungseinflusses muss die Temperatur im Zentrum des Kalibriervolumens mit einem Thermometer mit niedrigem und einem mit hohem Emmissionsgrad gemessen werden. Die Gastemperatur muss durch die Messung des Thermometers mit niedrigem Emmisionsgrad extrapoliert werden und der gesamte Strahlungseinfluss als Rechteckverteilung in der Messunsicherheit berücksichtigt werden.

#### 4.3.1.4 Druckdifferenzen
Druckdifferenzen können innerhalb des kalibreirvolumens auftreten und müssten sie, da sie einen Einfluss auf die Feuchte haben, mit einem entsprechenden Gerät erfasst werden.

#### 4.3.1.5 Strömungsverhältnisse
Die Strömungsrichtung im Kalibriervolumen muss erfasst werden und ihr Einfluss auf die unterschiedliche Positionierung von Bezugsnormale und Kalibriergegenstand geprüft werden

#### 4.3.1.6
Die Rückwirkung durch die Eigenerwärmung des Kalibreirvolumens muss geprüft werden. Die DKD-R %-8 gibt hierzu keine genaueren Angaben.


 <br/><br/>

---

## 5 Auswertung
Die Auswertung erfolgt mit Excel, LibreClac, Python oder R. Dabei ist auf folgende Parameter zu achten:
- Genauigkeit (Wie nah ist der Mittelwert aller Messungen am realen Wert?)
- Präzision (Wie nah liegen die Werte beieinander?)
- Verteilung (Liegen die Messungen häufiger in einem bestimmten Bereich?)
- Hysterese (Wie stark ändert sich die Messung in Abhänigkeit ob dieser von einem höheren oder niedrigerem Wert angestuert wird?)

![testo-Messkriterien](https://github.com/ZieBar/M.A.-Thesis/blob/9bfccf15ac7a891084de5ca83df9ba364f1dc509/Experiment/Abbildungen/abbildung-genauigkeit-praezision-de.jpg)

Abbildung von testo Industrial Services [^8]


---

## 5 offene Fragen
Der Klimaschrank ermöglicht viele Variationen. Daher muss hier priorisiert werden. 

- [ ] Wiederholung der Versuche mit längeren Messzeiträumen zur Validierung der Methoden?
- [ ] Mehr Zwischenschritte bei den Luftfeuchtigkeiten einbauen?
- [ ] Mehrere Temperaturen bei gleichen Abständen der Luftfeuchtigkeiten ausprobieren?
- [ ] Muss die Prüfung der Sensoren auf der Höhe eines akkreditierten Kalibrierslabors sein?

Eine Normgerechte Kalibrierung ist sehr aufwendig und nur mit vielen zusätzlichen Messgeräten bzw. Sensoren möglich und als Eigenleistung nicht wirklilch Durchführbar.
- [ ] Reicht eine Annäherung and die Kalibreirung aus? Sprich: durchführung der Experimente und Nennung der Einflussgrößen als Fehlequellen, ggf. bestimmung einer oder zweier Fehlerquellen
- [ ] Gibt es pauschale Messunsicherheiten, welche bei nicht exakter Bestimmung eingebracht werden können? => Frage an Kalibierlabor senden

# Literatur
[^1]: Richtlinie DKD-R 5-8, Ausgabe 02/2019, Revision 0, Kalibrierung von Hygrometern zur
direkten Erfassung der relativen Feuchte, Physikalisch-Technische Bundesanstalt,
Braunschweig und Berlin. DOI: 10.7795/550.2019021, S.30

[^2]: DKD-R 5-8, S.30

[^3]: Oberloier, S., Pearce, J., 2017. General Design Procedure for Free and Open-Source Hardware for Scientific Equipment. Designs 2, 2. https://doi.org/10.3390/designs2010002

[^4]: DKD-R 5-8, S.30

[^5]: DKD-R 5-8, S. 48

[^6]: DKD-R 5-8, S. 41

[^7]: DKD-R 5-8, S. 31 ff.

[^8]: Messicherheitsfibel, Testo Industrial Services, n.d.,S.15


