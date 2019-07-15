

#include<OneWire.h>
#include<DallasTemperature.h>
//Data wire is plugged into digital pin2
#define ONE_WIRE_BUS 2
//setup one wire  instance to communicate with any One wire device
OneWire oneWire(ONE_WIRE_BUS);
// pass one wire refrence to Dallas temperature library
DallasTemperature sensor (&oneWire);

int deviceCount=0;
float tempC;
void setup(void)
{
  sensors.begin();
  serial.begin(9600);
  
  Serial.print("Locating devices...");
  Serial.print("Found");
  deviceCount=sensor.getDeviceCount();
  Serial.println(" Devices");
  Serial.println(" ");
}
void loop(void)
{
  sensors.requestTemperatures();
  for(int i=0;i<deviceCount;i++)
  {
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    tempC=sensors.getTempCByIndex(i);
    Serial.print(tempC);
    Serial.print((char)176);
    Serial.print("C | ");
    Serial.print(DallasTemperature::toFahrenheit(temp));
    Serial.print((char)176);
    Serial.println("F");
  }
  Serial.println(" ");
  delay(1000);
}

