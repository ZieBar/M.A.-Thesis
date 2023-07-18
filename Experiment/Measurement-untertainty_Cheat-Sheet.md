Messunsicherheitsberechnung Cheat Sheet
===



# Begriffe


## Messunsicherheit
 Die Messunsicherheit ist der Schätzwert zur Kennzeichnung eines Wertebereiches, innerhalb dessen der richtige Wert der Messgröße liegt, bzw. dem Messergebnis zugeordneter Parameter, der die Streuung der Werte kennzeichnet, die der Messgröße zugeordnet werden können. (testo Messunsicherheitsfibel)

**Absolute Messunsicherheit:**
Angabe der Unsicherheit in physikalischer Einheit

**relative Messunsicherheit:** Angabe der Unsicherheit in Prozent

**erweiterte Messunsicherheit:** Intervall in dem sich der richtige Messwert mit 95 % Wahrscheinlichkeit (auch eine andere Wahrschienlichkeit ist möglich) befindet.

**Systematische Abweichung:** diejenige Abweichung eines Messwerts einer Messgröße von ihrem wahren Wert, die einseitig gerichtet und durch im Prinzip feststellbare Ursachen bedingt ist. Systematische Abweichungen erzeugen also eine Verschiebung nach einer Seite hin, sie bedeuten in der Tendenz stets zu hohe oder stets zu niedrige Messwerte. Ein typisches Beispiel dafür sind Abweichungen, welche durch falsch justierte Messgeräte entstehen. (https://www.biancahoegel.de/technik/messen/abweichung_systematisch.html#:~:text=Systematische%20Abweichung.%20Unter%20systematische%20Abweichung%20%28oder%20auch%20noch,bei%20unter%20gleichen%20Bedingungen%20wiederholten%20Messungen%20nicht%20erkennen. Zugriff: 20230715) 

**Positionsparameter:** Der "wahre" Wert an den sich eine Messung annähert. I.d.R. mit x̄ angegeben

**Dispersionsparameter:** Aussage über die Streuung

# Verteilungsformen

## Rechteckverteilung

## Normalverteilung

# Statistische Größen

## Positionsparameter: beste Schätzung des wahren Wertes
Der Positionsparameter x̄ gibt den Ort der besten Schätzung des wahren Wertes an.

**Absoluter Fehler** 

Der Absolute Fehler ist die Differenz aus der Einzelmessung und dem Positionsparameter
>$$  x_i - x̄$$
**Abwechungsquadrate**

Da bei der Summation der absoluten Fehler, unter der Annahme einer symmetrischen Verteilung, sich dies statistisch aufheben könnten, werden in der Regel die Abweichungsquadrate gebildet.
>$$ Abweichungsquadrate =\left(x_i - x̄\right)^2$$
Zudem kommen durch die Quadrierung große Abweichungen besonders zum Tragen und streichen mögliche Unsicherheiten einer Messung heraus.

**Summation der Abweichungsquadrate**
> $$Q = \sum_{i=1}^n \left(x_i- x̄\right)^2

Die beste Annäherung des Positionsparameters an den wahren Wert ist dann erreicht, wenn die Abweichungen vom Positionsparameter x̄ so klein wie möglich ist. 
 $$Q(x) => Minimum$$

Daher muss die Funktion Q(x) abgeleitet auf 0 gesetzt werden.

$${dQ\over dx} = -2 \sum_{i=1}^n(x_i - x̄) = 0$$

Da es sich um ein Produkt handelt reicht es aus sich an zu schauen unter welchen Bediungungen der letzte Term = 0 ist.
$$\sum_{i=1}^n x_i - n\times x̄ = 0$$ 

Durch die Addition des Terms $$-n \times x̄$$
und der Division durch $$n$$
ergibt sich als beste Näherung an den "wahren" Wert:
>$$x̄= {1 \over n} \sum_{i=1}^n x_i$$
Dabei handelt es sich um den arithmetischen Mittelwert. Der arithmetische Mittelwert kann also als beste Annäherung an den "wahren" Messwert angenommen werden. 

(https://www.youtube.com/watch?v=sF2_1YNiWXI Zugriff:20230716)

## Varianz
Die Varianz ist ein Maß für die Streuung der Messungen um den Mittlwert. Sie ist definiert als der arithmetische Mittelwert der Abweichungsquadrate. 
> $$ Var = {1 \over n} \sum_{i=1}^n (x_i - x̄)^2$$

## Standardabweichung
Die Standardabweichung σ (Bei Messunsicherheit u(x))ist nun die Wurzel aus der Varianz und ist wieder in der Ausgangsgröße der ursprünglichen Messung.

> $$ σ = \sqrt{{1 \over n-1} \sum_{i=1}^n (x_i - x̄)}$$

Eine Messung wird dann mit dem Positionsparameter ± der Standardabweichung angegeben:
> $$ x̄ ± σ$$

Anstelle des Terms $$1 \over n$$ wird bei der Standardabweichung der Term $$ 1 \over n-1$$ genutzt. Dies dient zweierlei. Einerseits muss bei Einsatz dieses Terms die Anzahl der Messungen n ≥ 2 sein. Zum anderen vergrößert es den Wert der Standard abweichung und ist somit eine vorsichtigere Abschätzung. Je größer n ist desto weniger fällt das -1 ins Gewicht.  

## Erweiterte Sta

Die erweiterte Messunsicherheit U ist ein Kennwert, der einem Bereich um das Messergebnis kennzeichnet, von dem erwartet werden kann, dass er einen großen Anteil der Verteilung der Werte umfasst, die der Messgrösse vernünftigerweise zugeordnet werden können. (https://irgendwelchefragen.de/was-ist-die-erweiterte-messunsicherheit/ Zugriff: 20230716)
Dieser ergibt sich aus dem Produkt der Messunsicherheit bzw. der Standardabweichung und dem Erweiterungsfaktor (bzw. Überdeckungsfaktor) k.

> $$U = k \times σ$$

In der Regel wird in der Kalibrierung eine Überdeckungswahrscheinlichkeit von 95 % angestrebt, was einem Wert von k = 2 entspricht. (testo Messfibel S. 50 f.)


## Fehlerfortpflanzung

## Konformität

# Formelsammlung




|Verteilung|Divisor|
|---------|-------|
|Normalverteilung|$$2$$|
|Rechteckverteilung|$$\sqrt{3}$$|
|U-förmige Verteilung|$$\sqrt{2}$$|
|Dreieckverteilung|$$\sqrt{6}$$|