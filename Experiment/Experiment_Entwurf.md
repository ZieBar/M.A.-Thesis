# Experiment-Vorschlag
## 1 Einleitung
Für Free-Open-Source-Datenlogger gibt es eine Reihe möglicher Sensoren. In den meisten Projekten, kommt jedoch nur ein einziger zum Einsatz. Größtenteils ist die Methode zur Untersuchung der Genauigkeit und Verlässlichkeit der Sensoren problematisch. Die Kalibrierung (die Bestimmung der Messungenauigkeiten einer Messeinrichtung) ist ein komplexer Vorgang. Die Richtlinie DKD-R 5-8 des Deutsche Kalibrierdienst (DKD) beschäftigt sich mit dem Kalibrieren von Hygrometern zur direkten Erfassung der relativen Feuchte. Zwei Methoden wären im Rahmen dieser Masterarbeit mit den zur Verfügung stehenden Ressourcen durchführbar:
-	Kalibrierung im Klimaschrank nach Ablauf A1 (Siehe DKD-R 5-8, Kapitel 9.3.2) 
-	Salzlösungen (explizit angegeben als nicht zur Kalibrierung geeignet, aber für Kontrollen ausreichend)
	
Eine Norm-gerechte Kalibrierung der Sensoren scheint im Rahmen dieser Masterarbeit nicht bzw. nicht in Eigenleistung möglich zu sein. Die beiden Methoden können jedoch genutzt werden um einen annähernden Eindruck der Qualität der Sensoren zu bekommen

---

## 2 Messaufbau

Die Verkabelung und das Messprinzip bleibt bei beiden Möglichkeiten gleich und wird daher hier nur einmal zusammengefasst.
Insgesamt wurden 6 Sensortypen ausgewählt. Von jedem Typ wurden jeweils 3 Exemplare beschafft. Insgesamt müssen also die Daten von 18 Sensoren erfasst und ausgewertet werden.
<br/><br/>
|Sensoren |	DHT22	| BME280	| BME680	| SHT31	| SHT41	| SHT85 |
|---------|---------|-----------|-----------|-------|-------|-------|
|Kommunikation |	One-Wire	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C	| SPI, I2C |#

<br/><br/>
Als Microcontroller-Unit (µCU) wurde der ESP8266 gewählt. Dieser hat den Vorteil, dass er mit WiFi ausgestattet ist und so verschiedene Wege der Kommunikation ermöglicht.
Die Menge der vorhandenen und benötigten Pins bei den µCUs und den Sensoren ermöglicht jedoch nur eine Verbindung zu maximal 6 Sensoren pro µCU. Daher müssen mehrere µCUs eingesetzt werden. Diese könnten die Daten einen zentralen µCU senden, welcher die Daten auf einer SD-Karte speichert.
<br/><br/>

![Schematische Darstellung des Messaparats](https://private-user-images.githubusercontent.com/133433673/244176352-2a19a4f3-1f4c-4515-935c-c05821b03551.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY2NzUzLCJuYmYiOjE2ODYxNjY0NTMsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM1Mi0yYTE5YTRmMy0xZjRjLTQ1MTUtOTM1Yy1jMDU4MjFiMDM1NTEuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMTkzNDEzWiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9MTcxMTlmY2I4NWRmNzljYjU4NGZkMjU1NjViNTk2NTFjYjJjNTc0MzUyOGNhOWRjOWQ1ZmJiNGYxZDU0MTZmZCZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.ZYyDsrA8qcZsCwZpWU3qDHtwDmB8Dn-5ygtlfA8kDGY)


Außer dem SHT41 und dem SHT85 haben alle Sensoren mit I2C eine sekundäre I2C-Adresse, diese kann über den ADDR- (STH) bzw. SDO- (BME) Pin aktiviert werden. Da mehr als zwei Sensoren ausgelesen werden müssen, wird im Programm nur die sekundäre Adresse abgefragt. Diese wird sukzessive bei den einzelnen Sensoren Aktiviert. 
<br/><br/>

![Verkabelung der Sensoren SHT31 und BME 280](https://private-user-images.githubusercontent.com/133433673/244176356-4fbcd460-229d-46ff-bd6a-ba4dc4124ad3.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY2NzUzLCJuYmYiOjE2ODYxNjY0NTMsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM1Ni00ZmJjZDQ2MC0yMjlkLTQ2ZmYtYmQ2YS1iYTRkYzQxMjRhZDMuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMTkzNDEzWiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9NGJiODM4MDAwYzhjNDQ1ZWJhY2E0ZDI3NzkxNDY1ZmFhNzNhNjExMTc4YzYzMWIyYjZiYmM3MjZhNGYwZDZkOCZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ._TtT-dFxAXPnzXK5gVq5lYrnG2lfgdooSYAlq1bHrG4)

<br/><br/>

Die Sensoren BME280 und SHT31 haben sekundäre i2C-Adressen, welche durch die Verbindung des SOD bzw. ADDR aktiviert werden können. Dies geschieht hier durch die violett dargestellten Kabel, welche jeweils mit einem digitalen Pin Verbunden sind. Diese können sukzessive ein oder ausgeschaltet werden.
<br/><br/>

![Verkabeluing der Sensoren BME680 und DHT22](https://private-user-images.githubusercontent.com/133433673/244177902-0ce25354-85b3-4775-b3a7-977d44bb2fda.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY2ODczLCJuYmYiOjE2ODYxNjY1NzMsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NzkwMi0wY2UyNTM1NC04NWIzLTQ3NzUtYjNhNy05NzdkNDRiYjJmZGEuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMTkzNjEzWiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9YzQzMjY3MjZjNGMyNGM4MDdkNzJmNGZjMzkzNTc2ZjQzZWIzMmZmZjY3NGVlNDg2MTdiMzRhNDAzYzVmOGQ2YSZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.DiX4OrxI0ezoRoAk-fbVI8HFWYOI-z7NLPNnT360-Kw)



Der DHT22 kann durch das One-Wire Protokoll problemlos durch den jeweiligen Digitalen pin ausgelesen werden.

<br/><br/>
![Verkabelung der Sensoren SHt41 und SHT85](https://private-user-images.githubusercontent.com/133433673/244176365-f14bc21c-0c62-44ba-99b2-d46596d0c71a.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY2NzUzLCJuYmYiOjE2ODYxNjY0NTMsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM2NS1mMTRiYzIxYy0wYzYyLTQ0YmEtOTliMi1kNDY1OTZkMGM3MWEuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMTkzNDEzWiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9MjE2OGExNWIzZGZiMWEzMTQwMDQ3ZjJhZTUzOTkyZDdmZWJiODMxMTNiZTJlYjk4M2I5NDM3NTFmZmIyMjBmMSZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.FhnDZ3-0zVk0VltL5NStkaag8gccnxZjiOag_P6yIvs)

Im Falle des SHT41 und ST85 muss ein Multiplexer für das Auslesen dazwischengeschaltet werden.

<br/><br/>

---
## 3 Prüfung mit gesättigten Salzlösungen 

Eine Bedingung für Open-Source-Hardware ist die breite Verfügbarkeit von Ressourcen zur Herstellung der Geräte. Die Kalibrierung oder zumindest Prüfung der Sensoren ist in diesem Fall ein wichtiger Teil der Herstellung. Salze wie Natriumchlorid (NaCl) Magnesium Chlorid Hexahydrat (MgCl2 · H2O) und Kaliumcarbonat K2CO3 sind einfach verfügbar und generieren durch die Deliqueszenzfeuchte Luftfeuchtigkeit, welche relativ Temperaturunabhängig sind. Jedoch sind sie nach den vorgaben des Deutschen Kalibrierdienstes nicht für Kalibrierungen geeignet. Bei adequater Nutzung sind sie jedoch für die Überprüfung von Sensoren ausreichend.
<br/><br/>
### 3.1 Material
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

### 3.2 Geräte
|Menge|Gerät|Typ|
|-----|-----|---|
|1 Stk.|Thermohygrometer|Testo 175H1|
|1 Stk.|3D-Drucker|Prusa i3 MK3S+|

<br/><br/>

### 3.3 Aufbau

#### 3.3.1 Dämmung
Aus den Dämmplatten wird eine Box von X x X mm gebaut. Darin werden die drei PP-Boxen positioniert. Die äußere Box dient zur thermischen Stabilisierung des Versuchsaufbaus. Ggf. kann diese durch das Auffüllen der Leerräume noch erhöht werden. 
<br/><br/>
#### 3.3.2 Ansetzen der Lösungen
Die drei PP-Boxen werden zunächst abgewaschen, mit destilliertem Wasser ausgespült und anschließend mit einem Faserfreiem Tuch getrocknet. Anschließend wird in jeweils eine der Boxen ein Salz eingefüllt bis der Boden bedeckt ist welches dann mit destilliertem Wasser benetzt wird, bis eine trüber Mischung entsteht. 
Eine Übersättigung muss vermieden werden. 
<br/><br/>

#### 3.3.3 Herstellung der Standfüße

Pro Box werden drei Standfüße (180 x 88 x 45 mm) eingesetzt, sodass die Sensoren und das Referenzgerät oberhalb der Salzlösungen liegen. Diese werden mit dem 3D-Drucker hergestellt und zusammengebaut. 
Das herausnehmbare Gitter soll dazu dienen, eine wasserdampfdurchläßige Membran aus Tyvek® zum Schutz der Sensoren einzulegen.


![](https://private-user-images.githubusercontent.com/133433673/244176387-555a0cc5-8fc8-4c4b-bd34-38ee3950bccc.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY2ODc1LCJuYmYiOjE2ODYxNjY1NzUsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM4Ny01NTVhMGNjNS04ZmM4LTRjNGItYmQzNC0zOGVlMzk1MGJjY2MuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMTkzNjE1WiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9ZjY3ZGU5Yjk1OTA2MzlhY2JmZDhmMDFiMWI0OTA2YjE5OGFjZmI1NDU5ZTNmZWEwNWJhYjY0NjBmZjliZDgxMiZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.Fpj44Fr9gGLuzIcbMJfDZCJ7tatNp2h2QBIeIaIj6HI)

<br/><br/>

#### 3.3.4 Positionierung der Sensoren
Da nur ein Referenzgerät zur Verfügung steht, musste der ursprüngliche Messaufbau abgewandelt werden. Nun sollen alle Sensoren gelichzeitig und zusammen mit dem Messgerät in jeweils einer Box positioniert werden. Das Referenzmessgerät wird in der Mitte aufgestellt, während die Breadboards an die Seiten kommen
Die Sensoren können dann mit Verlängerungskabeln ebenfalls in der Mitte positioniert werden, wodurch ein Raum von ca. 175x90x60mm in der Mitte der Box zum eigentlichen Kalibriervolumen wird.

![](https://private-user-images.githubusercontent.com/133433673/244176377-04f6b9c8-d196-4e64-a4d7-2ac5352bc8b8.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY2ODc1LCJuYmYiOjE2ODYxNjY1NzUsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM3Ny0wNGY2YjljOC1kMTk2LTRlNjQtYTRkNy0yYWM1MzUyYmM4YjguanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMTkzNjE1WiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9OGRhMzczMjI2NmVhMDQ2ODNjNWE3ZTNiOWE3MDE4NGEzZDkwN2M1YTkxNWY2MzgxNWE1MmZiMzVlNjllOWE0YyZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.L3Hy1KcDkw0bx8zeZHxxAzAsskPdnm8WbuhZpckGbdI)

<br/><br/>

### 3.4 Ablauf
#### 3.4.1 Berechnen der Angeleichzeit und Messzeitraum
Als erstes muss die Angleichszeit bestimmt werden, in der das Feuchtigkeitsgleichgewicht in der Box hergestellt wird. Diese ist abhängig vom Volumen und der Dichtigkeit der Box, sowie dem Luftstrom und der zu erreichenden Zielfeuchte.  
Hierfür wird die Salzlösung angesetzt, die Füße eingesetzt und der Testo H175 mittig platziert. Visuell kann über das Display des Referenzgerätes das Erreichen der Zielfeuchte kontrolliert und die Daten anschließend ausgewertet werden.
Der Vorgang wird in jeder Box wiederholt. Ggf. kann der Versuch mit und ohne Membran wiederholt werden.
.
Nach DKD-R 5-8 wird die angleich und Messzeitraum wiefolgt bestimmt:

![Angleichszeit und Messzeitraum nacb DKD-R 5-8](https://private-user-images.githubusercontent.com/133433673/244176372-07c4bfab-b553-4b29-8984-d4c85c7a048a.JPG?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY4NzYzLCJuYmYiOjE2ODYxNjg0NjMsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM3Mi0wN2M0YmZhYi1iNTUzLTRiMjktODk4NC1kNGM4NWM3YTA0OGEuSlBHP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMjAwNzQzWiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9NjQwZmViMmVjZGY0NzBkZDk1ZDVkYzA1MjRkYmY2OTY0Zjc2YjEyMmEwNzIzZmFiZTIyNTA4YWVlNmRkMmQ5OSZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.dW6_nU3ncu6SFp9AU0LRXi9j0zFU8JPWTflv6KtOXRY)
Abbildung aus der DKD-R 5-8

<br/><br/>

I) Erreichen einer Abweichung von <2% der Relativen Luftfeuchte oder 2°K vom Sollwert  
II) WarteZeit von mind. 30 min  
III) Messwertaufnahme, mind. 10 Messwerte in 10 Minuten  
IV) Wartezeit von 10 Minuten  
V) Wiederholung von III  

<br/><br/>

#### 3.4.2 Messung
Nach dem Angleichzeit und Messzeitraum bestimmt wurden, werden die Sensoren mit dem Messgerät in eine Box gelegt und der versuch begonnen. Dies wird für jede der 3 Luftfeuchtigkeiten wiederholt.

<br/><br/>

## 4 Annäherung an die Kalibrierung mit Klimaschrank
Kalibrierverfahren mit Klimaschrank sind nach der Richtlinie des DKD zulässig, verlangen aber einen hohen Aufwand. Die Methode könnte hier Verwendung finden um die Verlässlichkeit der Salzlösungsmethode zu prüfen. Zusätzlich ist der Ablauf A1 ist besonders interessant, da er als einziger in der Lage ist Hysterese Effekte darzustellen, welche auch bei den Salzlösungen nicht dargestellt werden können.
Die Möglichkeit die Sensoren auch bei verschiedenen Temperaturen (z.B. 10°C, 20°C, 30°C und 40°C) zu testen ist ein weiterer Vorteil dieser Methode. So könnte auch die Anwendung in extremerem Klima oder im denkmalpflegerischen Kontext simuliert werden.
Der DKD empfiehlt bei der Kalibrierung die Verwendung einer unabhängigen Normale zur Referenzwertbestimmung. Zusätzlich müssen Einflussfaktoren, wie z.B. die räumliche Inhomogenität, bestimmt werden. 

<br/><br/>

### 4.1 Geräte
|Menge|Geräte|Typ|
|---|---|---|
|1 Stk.|Klimaschrank|unbekannt|
|1 Stk.|Referenzmessgerät|testo 175H1|
|3 Stk.|Standfüße|selbstbau|
<br/><br/>

### 4.2 Aufbau
Je nach Aufbau des Klimaschrnks werden die Sensoren und das Referenzgerät im Inneren des Schrankes platziert. Das Referenzgerät liegt misst dabei im Zentrum des Kalibriervolumens.

<br/><br/>

### 4.3 Ablauf
Der Ablauf der DKD-R 5-8 wird als Vorbild für dieses Experiment genommen. Der Ausgangspunkt S0 muss dabei 5% unterhalb des niedrigsten Wertes N1a bzw. N1b liegen. Für jede gewählte Temperatur müsste dann ein Durchlauf gemacht werden.
Zunächst muss, wie bei Möglichkeit 1 die Angleichzeit bestimmt werden. Der Wert wird dann für eine halbe Stunde gehalten, wobei pro Minute eine Messung erfolgt. 

![Abbildung des Ablauf A1](https://private-user-images.githubusercontent.com/133433673/244195778-9ad5f55b-38cf-45b4-8b47-082ebfe0d7e0.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTcxNjAxLCJuYmYiOjE2ODYxNzEzMDEsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE5NTc3OC05YWQ1ZjU1Yi0zOGNmLTQ1YjQtOGI0Ny0wODJlYmZlMGQ3ZTAucG5nP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMjA1NTAxWiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9NWZmN2FmYTg4M2Y5NTI5ODFmZTVkZTM2YjZlYTdlYzQ3MzI0ZjU4YWNkZTg1MjY5YTM4YWExOTdmY2Y5MmRhOCZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.zkb7xwSszgTqzkli2PAi-7Sz18GCr5hAT-9qvQMmzbc)
Abbildung aus der DKD-R 5-8

<br/><br/>

#### 4.3.1 Einflussgrößen

- Räumliche Inhomogenität
- Zeitliche Instabilität
- Strahlungseinfluss 
- Druckdifferenz
- Strömungsverhältnisse (positionierung der Bezugsnormale und Kalibreirgegenstand parrallel zur Strömungsrichtung)
- Rückwirkungen (z.b. Eigenerwärmung)

##### 4.3.1.1 Räumliche Inhomogenität
Messungen von Temperatur und Luftfeuchtigkeit müssen am Referenzmessort und an den vorgesehenen Messpunkten vorgenommen werden. Abweichung und Verteilung müssen erfasst werden.

##### 4.3.1.2 Zeitliche Instabilität
Zur Erfassung der zeitlichen Instabilität müssen mindestens 30 Messungen in 30 Minuten in regelmäßigen Abständen erfolgen.


 <br/><br/>

---

## 5 Auswertung
Die Auswertung erfolgt mit Excel, LibreClac, Python oder R. Dabei ist auf folgende Parameter zu achten:
- Genauigkeit (Wie nah ist der Mittelwert aller Messungen am realen Wert?)
- Präzision (Wie nah liegen die Werte beieinander?)
- Verteilung (Liegen die Messungen häufiger in einem bestimmten Bereich?)
- Hysterese (Wie stark ändert sich die Messung in Abhänigkeit ob dieser von einem höheren oder niedrigerem Wert angestuert wird?)

![testo-Messkriterien](https://private-user-images.githubusercontent.com/133433673/244176374-5127c46e-a9f2-43bc-a6ac-e5d63eb695f5.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJrZXkiOiJrZXkxIiwiZXhwIjoxNjg2MTY4OTE2LCJuYmYiOjE2ODYxNjg2MTYsInBhdGgiOiIvMTMzNDMzNjczLzI0NDE3NjM3NC01MTI3YzQ2ZS1hOWYyLTQzYmMtYTZhYy1lNWQ2M2ViNjk1ZjUuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQUlXTkpZQVg0Q1NWRUg1M0ElMkYyMDIzMDYwNyUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyMzA2MDdUMjAxMDE2WiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9ZTZiZjJmNTNmZTRhMjA5NmM4OTkwZjJjMjA3MmQwYjdlZjBkNTk2MDBmMGY0MzFmNzAwNTkzMTE1MDU1YjE1MSZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.K28iAROWAhBxnyw0tJn9xvV83HOVvb1GDTtHPK6YFpY)
Abbildung von testo Industrial Services


---

## 5 offene Fragen
Der Klimaschrank ermöglicht viele Variationen. Daher muss hier priorisiert werden. 

- [ ] Wiederholung der Versuche mit längeren Messzeiträumen zur Validierung der Methoden?
- [ ] Mehr Zwischenschritte bei den Luftfeuchtigkeiten einbauen?
- [ ] Mehrere Temperaturen bei gleichen Abständen der Luftfeuchtigkeiten ausprobieren?
- [ ] Muss die Prüfung der Sensoren auf der Höhe eines akkreditierten Kalibrierslabors sein?
