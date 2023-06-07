# Experiment-Vorschlag
## Einleitung
Für Free-Open-Source-Datenlogger gibt es eine Reihe möglicher Sensoren. In den meisten Projekten, kommt jedoch nur ein einziger zum Einsatz. Größtenteils ist die Methode zur Untersuchung der Genauigkeit und Verlässlichkeit der Sensoren problematisch. Die Kalibrierung (die Bestimmung der Messungenauigkeiten einer Messeinrichtung) ist ein komplexer Vorgang. Die Richtlinie DKD-R 5-8 des Deutsche Kalibrierdienst (DKD) beschäftigt sich mit dem Kalibrieren von Hygrometern zur direkten Erfassung der relativen Feuchte. Zwei Methoden wären im Rahmen dieser Masterarbeit mit den zur Verfügung stehenden Ressourcen durchführbar:
-	Kalibrierung im Klimaschrank nach Ablauf A1 (Siehe DKD-R 5-8, Kapitel 9.3.2) 
-	Salzlösungen (explizit angegeben als nicht zur Kalibrierung geeignet, aber für Kontrollen ausreichend)
	
Eine Norm-gerechte Kalibrierung der Sensoren scheint im Rahmen dieser Masterarbeit nicht bzw. nicht in Eigenleistung möglich zu sein. Die beiden Methoden können jedoch genutzt werden um einen annähernden Eindruck der Qualität der Sensoren zu bekommen

## Messaufbau

Die Verkabelung und das Messprinzip bleibt bei beiden Möglichkeiten gleich und wird daher hier nur einmal zusammengefasst.
Insgesamt wurden 6 Sensortypen ausgewählt. Von jedem Typ wurden jeweils 3 Exemplare beschafft. Insgesamt müssen also die Daten von 18 Sensoren erfasst und ausgewertet werden.
|Sensoren |	DHT22	| BME280	| BME680	| SHT31	| SHT41	| SHT85 |
|---------|---------|-----------|-----------|-------|-------|-------|
|Kommunikation |	One-Wire	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C |#


Als Microcontroller-Unit (µCU) wurde der ESP8266 gewählt. Dieser hat den Vorteil, dass er mit WiFi ausgestattet ist und so verschiedene Wege der Kommunikation ermöglicht.
Die Menge der vorhandenen und benötigten Pins bei den µCUs und den Sensoren ermöglicht jedoch nur eine Verbindung zu maximal 6 Sensoren pro µCU. Daher müssen mehrere µCUs eingesetzt werden. Diese könnten die Daten einen zentralen µCU senden, welcher die Daten auf einer SD-Karte speichert.


![Schematische Darstellung des Messaparats](https://pad.sbb.spk-berlin.de/uploads/upload_90282ace48bb6c56694ed8611a43bd28.jpg)




Außer dem SHT41 und dem SHT85 haben alle Sensoren mit I2C eine sekundäre I2C-Adresse, diese kann über den ADDR- (STH) bzw. SDO- (BME) Pin aktiviert werden. Da mehr als zwei Sensoren ausgelesen werden müssen, wird im Programm nur die sekundäre Adresse abgefragt. Diese wird sukzessive bei den einzelnen Sensoren Aktiviert. 

![Verkabelung der Sensoren SHT31 und BME 280](https://pad.sbb.spk-berlin.de/uploads/upload_2143bdc4721b52e9c1503104ba039d42.jpg)

Die Sensoren BME280 und SHT31 haben sekundäre i2C-Adressen, welche durch die Verbindung des SOD bzw. ADDR aktiviert werden können. Dies geschieht hier durch die violett dargestellten Kabel, welche jeweils mit einem digitalen Pin Verbunden sind. Diese können sukzessive ein oder ausgeschaltet werden.


![Verkabeluing der Sensoren BME680 und DHT22](https://pad.sbb.spk-berlin.de/uploads/upload_4d5af4174012a01d583da3cd989112b3.jpg)

Der DHT22 kann durch das One-Wire Protokoll problemlos durch den jeweiligen Digitalen pin ausgelesen werden.


![Verkabelung der Sensoren SHt41 und SHT85](https://pad.sbb.spk-berlin.de/uploads/upload_b07666070f8f43ca64331931d257e6f8.jpg)

Im Falle des SHT41 und ST85 muss ein Multiplexer für das Auslesen dazwischengeschaltet werden.

## Prüfung mit gesättigten Salzlösungen 

Eine Bedingung für Open-Source-Hardware ist die breite Verfügbarkeit von Ressourcen zur Herstellung der Geräte. Die Kalibrierung oder zumindest Prüfung der Sensoren ist in diesem Fall ein wichtiger Teil der Herstellung. Salze wie Natriumchlorid (NaCl) Magnesium Chlorid Hexahydrat (MgCl2 · H2O) und Kaliumcarbonat K2CO3 sind einfach verfügbar und generieren durch die Deliqueszenzfeuchte Luftfeuchtigkeit, welche relativ Temperaturunabhängig sind. Jedoch sind sie nach den vorgaben des Deutschen Kalibrierdienstes nicht für Kalibrierungen geeignet. Bei adequater Nutzung sind sie jedoch für die Überprüfung von Sensoren ausreichend.

### Material
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

### Geräte
|Menge|Gerät|Typ|
|-----|-----|---|
|1 Stk.|Thermohygrometer|Testo H175|
|1 Stk.|3D-Drucker|Prusa i3 MK3S+|

### Aufbau

#### Dämmung
Aus den Dämmplatten wird eine Box von X x X mm gebaut. Darin werden die drei PP-Boxen positioniert. Die äußere Box dient zur thermischen Stabilisierung des Versuchsaufbaus. Ggf. kann diese durch das Auffüllen der Leerräume noch erhöht werden. 

#### Ansetzen der Lösungen
Die drei PP-Boxen werden zunächst abgewaschen, mit destilliertem Wasser ausgespült und anschließend mit einem Faserfreiem Tuch getrocknet. Anschließend wird in jeweils eine der Boxen ein Salz eingefüllt bis der Boden bedeckt ist welches dann mit destilliertem Wasser benetzt wird, bis eine trüber Mischung entsteht. 
Eine Übersättigung muss vermieden werden.

#### Herstellung der Standfüße

Pro Box werden drei Standfüße (180 x 88 x 45 mm) eingesetzt, sodass die Sensoren und das Referenzgerät oberhalb der Salzlösungen liegen. Diese werden mit dem 3D-Drucker hergestellt und zusammengebaut. 

![](https://github.com/ZieBar/M.A.-Thesis/blob/main/_DSC3610.jpg)

Das herausnehmbare Gitter soll dazu dienen, eine wasserdampfdurchläßige Membran aus Tyvek® zum Schutz der Sensoren einzulegen.

#### Positionierung der Sensoren
Da nur ein Referenzgerät zur Verfügung steht, musste der ursprüngliche Messaufbau abgewandelt werden. Nun sollen alle Sensoren gelichzeitig und zusammen mit dem Messgerät in jeweils einer Box positioniert werden. Das Referenzmessgerät wird in der Mitte aufgestellt, während die Breadboards an die Seiten kommen
Die Sensoren können dann mit Verlängerungskabeln ebenfalls in der Mitte positioniert werden, wodurch ein Raum von ca. 175x90x60mm in der Mitte der Box zum eigentlichen Kalibriervolumen wird.

![](https://pad.sbb.spk-berlin.de/uploads/upload_8562ba412255e9b17369ac0d462e3856.jpg)

### Ablauf
#### Berechnen der Angeleichzeit und Messzeitraum
Als erstes muss die Angleichszeit bestimmt werden, in der das Feuchtigkeitsgleichgewicht in der Box hergestellt wird. Diese ist abhängig vom Volumen und der Dichtigkeit der Box, sowie dem Luftstrom und der zu erreichenden Zielfeuchte.  
Hierfür wird die Salzlösung angesetzt, die Füße eingesetzt und der Testo H175 mittig platziert. Visuell kann über das Display des Referenzgerätes das Erreichen der Zielfeuchte kontrolliert und die Daten anschließend ausgewertet werden.
Der Vorgang wird in jeder Box wiederholt. Ggf. kann der Versuch mit und ohne Membran wiederholt werden.
.
Nach DKD-R 5-8 wird die angleich und Messzeitraum wiefolgt bestimmt:

I) Erreichen einer Abweichung von <2% der Relativen Luftfeuchte oder 2°K vom Sollwert
II) WarteZeit von mind. 30 min
III) Messwertaufnahme, mind. 10 Messwerte in 10 Minuten
IV) Wartezeit von 10 Minuten
V) Wiederholung von III

#### Messung
Nach dem Angleichzeit und Messzeitraum bestimmt wurden, werden die Sensoren mit dem Messgerät in eine Box gelegt und der versuch begonnen. Dies wird für jede der 3 Luftfeuchtigkeiten wiederholt.

### Annäherung an die Kalibrierung mit Klimaschrank
Kalibrierverfahren mit Klimaschrank sind nach der Richtlinie des DKD zulässig, verlangen aber einen hohen Aufwand. Die Methode könnte hier Verwendung finden um die Verlässlichkeit der Salzlösungsmethode zu prüfen. Zusätzlich ist der Ablauf A1 ist besonders interessant, da er als einziger in der Lage ist Hysterese Effekte darzustellen, welche auch bei den Salzlösungen nicht dargestellt werden können.
Die Möglichkeit die Sensoren auch bei verschiedenen Temperaturen (z.B. 10°C, 20°C, 30°C und 40°C) zu testen ist ein weiterer Vorteil dieser Methode. So könnte auch die Anwendung in extremerem Klima oder im denkmalpflegerischen Kontext simuliert werden.
Der DKD empfiehlt bei der Kalibrierung die Verwendung einer unabhängigen Normale zur Referenzwertbestimmung. Zusätzlich müssten Einflussfaktoren, wie z.B. die räumliche Inhomogenität durch mind. 5 verschiedene Messunkte im Kalibriervolumen, bestimmt werden. 

#### Geräte

#### Aufbau

#### Ablauf

## Auswertung
Die Auswertung erfolgt mit Excel, LibreClac, Python oder R. Dabei ist auf folgende Parameter zu achten:
- Genauigkeit (wie nah ist der Mittelwert aller Messungen am realen Wert?)
- Präzision (wie nah liegen die Werte beieinander?)
- Verteilung (liegen die Messungen häufiger in einem bestimmten Bereich?)
- Hysterese ()

## offene Fragen
Der Klimaschrank ermöglicht viele Variationen. Daher muss hier priorisiert werden. 

- [ ] Wiederholung der Versuche mit längeren Messzeiträumen zur Validierung der Methoden?
- [ ] Mehr Zwischenschritte bei den Luftfeuchtigkeiten einbauen?
- [ ] Mehrere Temperaturen bei gleichen Abständen der Luftfeuchtigkeiten ausprobieren?

