#define BLYNK_TEMPLATE_ID "TMPL3G4qXwSSe"
#define BLYNK_TEMPLATE_NAME "DHT sensor"
#define BLYNK_AUTH_TOKEN "bu4K4cOmlvd1Kc1dmo0VDap2SA5g_e1q"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 
#define DHTTYPE DHT11 

char auth[]="bu4K4cOmlvd1Kc1dmo0VDap2SA5g_e1q";
char ssid[]="Never gonna give you up";
char pass[]="password6";
DHT dht(DHTPIN, DHTTYPE);


void setup() {
 
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Sccessful" );
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return; 
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature");
  Serial.print(t);
  Serial.println("degrees celsius.");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);
}