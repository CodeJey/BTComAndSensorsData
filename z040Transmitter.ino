#include <DHT.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
 
float hum;
float temp;
const int AirValue = 620;
const int WaterValue = 310; //the air and water valuea should be inputed
int soilMoistureValue = 0;
int soilmoisturepercent=0;
  
void setup() 
{
      Serial.begin(9600);
//      Serial.println("Arduino with HC-0x FC-114 is ready");
      BTSerial.begin(9600);  
//      Serial.println("BTserial started at 9600");
      dht.begin();
 
}
 
void loop()
{
   soilMoistureValue = analogRead(A0);
   soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
   hum = dht.readHumidity();
   temp= dht.readTemperature();
   BTSerial.write("Temperature: ");
   BTSerial.print(temp);
   BTSerial.write(" Celsius");
   BTSerial.write('\n');
   BTSerial.write("Humidity: ");
   BTSerial.print(hum);
   BTSerial.write(" %");
   BTSerial.write('\n');
   BTSerial.write("Soil moisture: ");
   BTSerial.print(soilmoisturepercent);
   BTSerial.write(" %");
   BTSerial.write('\n');
   BTSerial.write('~');
   BTSerial.write('\n');
    delay(7500);
}
