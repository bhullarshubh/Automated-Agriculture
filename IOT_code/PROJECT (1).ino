#include <WiFi.h>
#include "HTTPClient.h"
#include "time.h"
#include <DHT.h>
#include <ArduinoJson.h>
#include <Adafruit_BMP085.h>
#include "WiFi.h"
#include "WebServer.h"

const char* ssid = "Redmi";
const char* password = "2002@Lez";


WiFiServer server1(80);

String header;

Adafruit_BMP085 bmp;

#define DHTPIN_1 4
#define DHTPIN_2 18
#define DHTTYPE DHT11

int TRIGGER = 25;
int ECHO = 33;
int ECHO_POWER = 26;
int Signal_Pin = 35;

DHT DHT_1(DHTPIN_1, DHTTYPE);
DHT DHT_2(DHTPIN_2, DHTTYPE);

float Humidity_1 = 0;
float Humidity_2 = 0;
float Temperature_1 = 0;
float Temperature_2 = 0;
float Time_Taken = 0;
float Distance1 = 0;
float Distance = 0;
float Pressure =0;
float Rain_Water_Sensor =0;

String Humidity_1_String = "";
String Humidity_2_String = "";
String Temperature_1_String = "";
String Temperature_2_String = "";
String DAY_HOUR = "";
String Distance_String = "";
String Pressure_String = "";
String Rain_Water_Sensor_String = "";

String cse_ip = "192.168.43.248";
String cse_port = "8080";
String server = "http://" + cse_ip + ":" + cse_port + "/~/in-cse/in-name/";
String ae = "iot_project_final";


int x=1;
int y=0;
void createCI1(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "echo_distance" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI2(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "humidity_1" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI3(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "temperature_1" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI4(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "humidity_2" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI5(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "temperature_2" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI6(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "DAY_HOUR" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI7(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "pressure" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}

void createCI8(String& val)
{
    HTTPClient http;
    http.begin(server + ae + "/" + "water_sensor" + "/");
    http.addHeader("X-M2M-Origin", "admin:admin");
    http.addHeader("Content-Type", "application/json;ty=4");
    int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");
    Serial.println(code);
    if (code == -1)
        Serial.println("Connection failed");
    http.end();
}


IPAddress ip;

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 10000;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
   ip = WiFi.localIP();
   Serial.println(ip);
   Serial.println("WiFi connected");
  server1.begin();

    DHT_1.begin();
    DHT_2.begin();
    bmp.begin();

    pinMode(TRIGGER, OUTPUT); 
    pinMode(ECHO, INPUT);

    digitalWrite(TRIGGER,LOW);
    
}

void loop(){
  WiFiClient client = server1.available(); 
  delay(100);
    Humidity_1    = DHT_1.readHumidity();
    Temperature_1 = DHT_1.readTemperature();
    delay(100);
    Humidity_2    = DHT_2.readHumidity();
    Temperature_2 = DHT_2.readTemperature();
    delay(100);
    
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    Time_Taken = pulseIn(ECHO, HIGH);
    Distance1 = Time_Taken * (0.0343/2);
    Distance  = 12.00-Distance1;
    
    Pressure = bmp.readPressure();

    Rain_Water_Sensor = analogRead(Signal_Pin);
            

    Serial.println("Temperature_1: " + (String) Temperature_1 + "C");
    Serial.println("Humidity_1: " + (String) Humidity_1 + "%");
    Serial.println("Temperature_2: " + (String) Temperature_2 + "C");
    Serial.println("Humidity_2: " + (String) Humidity_2 + "%");
    Serial.println("Water level: " + (String) Distance + "cm");
    Serial.println("Atomspiric pressure: "+ (String) Pressure + "Pa");
    Serial.println("Water Sensor Reading: "+ (String)Rain_Water_Sensor+"" );
    
    Humidity_1_String = Humidity_1;
    Humidity_2_String = Humidity_2;
    Temperature_1_String =Temperature_1;
    Temperature_2_String =Temperature_2;
    DAY_HOUR = y;
    Distance_String = Distance;
    Pressure_String = Pressure;
    Rain_Water_Sensor_String = Rain_Water_Sensor;
    
    Serial.println(DAY_HOUR);
    /*
    createCI1(Distance_String);
    createCI2(Humidity_1_String);
    createCI3(Temperature_1_String);
    createCI4(Humidity_2_String);
    createCI5(Temperature_2_String);
    //createCI6(DAY_HOUR);
    createCI7(Pressure_String);
    createCI8(Rain_Water_Sensor_String);
*/
    
  if (client) {                            
    
    Serial.println("New Client.");  
    String currentLine = "";         
    while (client.connected()) {
      
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".alert {padding: 20px;background-color: #f44336;color: white;}");
            client.println(".closebtn {margin-left: 15px;color: white;font-weight: bold;float: right;font-size: 22px;line-height: 20px;cursor: pointer;transition: 0.3s;}");
            client.println(".alert {padding: 20px;background-color: #f44336;color: white;}");
            client.println(".closebtn:hover {color: black;}</style></head>");
            
            client.println("<body><h1>ALPHA TEAM</h1>");

    
            client.println("<p>Water level: " + Distance_String + "cm</p>");
            
            client.println("<p>Temperature_1: " + Temperature_1_String + "C</p>");
            
            client.println("<p>Humidity_1: " + Humidity_1_String + "%</p>");
            
            client.println("<p>Atomspiric pressure: "+ Pressure_String + "Pa</p>");
            
            client.println("<p>Temperature_2: " + Temperature_2_String + "C</p>");
            
            client.println("<p>Humidity_1: " + Humidity_2_String + "%</p>");
            
            client.println("<p>Water Sensor Reading: "+ Rain_Water_Sensor_String+"</p>");
            
            if(Distance < 2.5)
            {
              client.println("<br><br><p>Click on the \"x\" symbol to close the alert message.</p><div class=\"alert\"><span class=\"closebtn\" onclick=\"this.parentElement.style.display='none';\">&times;</span> <strong>Water level is LOW! </strong> <br>Switch ON the PUMP</div></p>");       
            }
            else if(Distance > 5)
            {
              client.println("<br><br><p>Click on the \"x\" symbol to close the alert message.</p><div class=\"alert\"><span class=\"closebtn\" onclick=\"this.parentElement.style.display='none';\">&times;</span> <strong>Water level is HIGH! </strong> <br>DRAIN OUT the WATER</div></p>");
              
            }
            if( Rain_Water_Sensor > 2000)
            {
              client.println("<br><br><p>Click on the \"x\" symbol to close the alert message.</p><div class=\"alert\"><span class=\"closebtn\" onclick=\"this.parentElement.style.display='none';\">&times;</span> <strong>It is RAINING NOW</strong></div></p>");
            }
            client.println("</body></html>");
            
            client.println();
            client.flush();

             break;
          } 
          else 
          {
            currentLine = "";
          }
    }
    
    header = "";
    Serial.println("");
  }
  delay(1000);
}
