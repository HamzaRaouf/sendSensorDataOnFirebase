#include <ESP8266WiFi.h>                 
#include <FirebaseArduino.h>      

#define FIREBASE_HOST "aquatic-chordate-guidance-default-rtdb.firebaseio.com"
// #define FIREBASE_HOST "https://aquatic-chordate-guidance-default-rtdb.firebaseio.com"
// // #define FIREBASE_HOST "https://console.firebase.google.com/project/aquatic-chordate-guidance/database/aquatic-chordate-guidance-default-rtdb/data/~2F"      
#define FIREBASE_AUTH "AIzaSyCvd6KptAWRIJ9JorrIVpDRAuLr2CZ1SpA"  

#define WIFI_SSID "PTCL_BB"
#define WIFI_PASSWORD "F4D45FAD"
// #define WIFI_SSID "Signal"                                  
// #define WIFI_PASSWORD "1234567809"            
 
// // #define DHTPIN D2                                            // Digital pin connected to DHT11
// // #define DHTTYPE DHT11                                        // Initialize dht type as DHT 11
// // DHT dht(DHTPIN, DHTTYPE);   
 
void setup() 
{
  Serial.begin(9600);


   Serial.print("Connecting to Wi-Fi");
    unsigned long ms = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        digitalWrite(LED_BUILTIN, LOW); 
        delay(300);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(300); 
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
  // dht.begin();                                                  //reads dht sensor data 
               
  // WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  // Serial.print("Connecting to ");
  // Serial.print(WIFI_SSID);
  // while (WiFi.status() != WL_CONNECTED) {
  //   Serial.print(".");
  //   delay(500);
  // }
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                 // connect to the firebase
 
}
 
void loop() 
{
 
  // float h = dht.readHumidity();                                 // Read Humidity
  // float t = dht.readTemperature();                              // Read temperature
  
  // if (isnan(h) || isnan(t))                                     // Checking sensor working
  // {                                   
  //   Serial.println(F("Failed to read from DHT sensor!"));
  //   return;
  // } 
  // Serial.print("Humidity: ");  
  // Serial.print(h);
  // String fireHumid = String(h) + String("%");                   //Humidity integer to string conversion
  
  // Serial.print("%  Temperature: ");  
  // Serial.print(t);  
  // Serial.println("°C ");
  // String fireTemp = String(t) + String("°C");  
  delay(500);
 
 
  // Firebase.pushString("/DHT11/Humidity", fireHumid);            //setup path to send Humidity readings
  Firebase.pushString("/water_level","-1");         //setup path to send Temperature readings
    // if (Firebase.failed()) 
    // {
 
      // Serial.print("pushing /logs failed:");
      // Serial.println(Firebase.error()); 
      // return;
  }
  