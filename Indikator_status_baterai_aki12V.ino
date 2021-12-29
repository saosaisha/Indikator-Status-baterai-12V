/*
Baterai Indikator
sumber :
David Cuartielles, modified 30 Aug 2011, By Tom Igoe
http://arduino.cc/en/Tutorial/AnalogInput

Bisa digunakan pada tegangan baterai berapa saja
Contoh disini menggunakan bterai 12V
Yang mempunyai range tegangan 10.8-14,4V
 ATtiny85
- an 120ohms resistor dari PB0 ke Anoda RED LED dan Katoda ke GND
- an 100ohms resistor dari PB1 ke Anoda Yellow LED dan Katoda ke GND
- an 100ohms resistor dari PB0 ke Anoda Blue LED dan Katoda ke GND
Buat sebagai pembanding tegangan pada PB3 Yaitu 1:4--- +BAT --|10k|-|10k|-|10k|--PB3--|10k|-GND, pin PB3(A2)
- Untuk mencoba bisa menggunakan potensiometer 10-50kohms variabile
  ujungnya ke  at +5V and GND, dan pin tengah ke PB3(A2)

*/
// Bila menggunakan led biasa green ganti dengan yellow
int sensorPin = A2;   // PB3 Pembaca tegangan analog baterai
int ledRPin = 0;      // ke Anoda RED LED
int ledGPin = 1;      // ke Anoda Yellow LED
int ledBPin = 2;      // ke Anoda BLUE LED


int u = 0;  // Pembacaan awal input analog 0 Volt

float k=4.95/5; // Toleransi pembacaan tegangan
/*
 * Misal
 * tegangan terendah baterai 11.5V
 * maka 11,5 x (255/5)=
 * Teganga tertinggi 13,8
 * maka 13.8 x(255/5)=704
 */
int treapta1 = 586/k;       // Ubat=11,5
int treapta2 = 612/k;       // Ubat=12
int treapta3 = 663/k;       // Ubat=13
int treapta4 = 704/k;       // Ubat=13,8



void setup() {
  // declare the ledPins as an OUTPUT:
  pinMode(ledRPin, OUTPUT);  
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(sensorPin,INPUT);
}

void loop() {

  // Semua led off
    digitalWrite(ledRPin, LOW);    // turn the red led off
    digitalWrite(ledGPin, LOW);    // turn the green led off
    digitalWrite(ledBPin, LOW);    // turn the blue led off
 
  
 // baca tegangan aki
  u = analogRead(sensorPin);    

// voltage below 11.5V
if (u < treapta1)
{
  digitalWrite(ledGPin, LOW);    // turn the green led off
  digitalWrite(ledBPin, LOW);    // turn the blue led off

  digitalWrite(ledRPin, HIGH);   // turn the red led on
  delay(100);
  digitalWrite(ledRPin, LOW);    // turn the red led off
  delay(100);
  digitalWrite(ledRPin, HIGH);   // turn the red led on
  delay(100);
  digitalWrite(ledRPin, LOW);    // turn the red led off
  delay(1000);
}

// voltage ower 11,5V & below 12V
if (u > treapta1 && u < treapta2)
{
  digitalWrite(ledGPin, LOW);    // turn the green led off
  digitalWrite(ledBPin, LOW);    // turn the blue led off

  digitalWrite(ledRPin, HIGH);   // turn the red led on
  delay(100);
}

// voltage ower 12V & below 13V
if (u > treapta2 && u < treapta3)
{ 
  digitalWrite(ledBPin, LOW);    // turn the blue led off
 
  digitalWrite(ledRPin, HIGH);   // turn the red led on
  delay(500);
  digitalWrite(ledRPin, LOW);    // turn the red led off
  delay(100);
  digitalWrite(ledGPin, HIGH);   // turn the green led on
  delay(200);
}

// voltage ower 13,5V & below 13,8V
if (u >= treapta3 && u < treapta4)
{ 
  digitalWrite(ledRPin, LOW);    // turn the red led off
  digitalWrite(ledBPin, LOW);    // turn the blue led off

  digitalWrite(ledGPin, HIGH);   // turn the green led on
  delay(100);
}

// voltage ower 13,9
if (u > treapta4)
{
  digitalWrite(ledRPin, LOW);    // turn the red led off
  
  digitalWrite(ledGPin, HIGH);   // turn the green led on
  delay(500);
  digitalWrite(ledGPin, LOW);   // turn the green led off
  delay(100);
  digitalWrite(ledBPin, HIGH);   // turn the blue led on
  delay(200);
}
}
