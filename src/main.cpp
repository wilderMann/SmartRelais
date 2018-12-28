#include <ESP8266WiFi.h>
#include "config.h"

<<<<<<< HEAD
#define DEVICE_NAME "Nachttisch"
#define LED D1
void printWifiStatus();
String prepareHtmlPage();
void handleMessage(AdafruitIO_Data *data);

WiFiServer server(80);
AdafruitIO_Feed *status = io.feed("on-slash-off");
int PinStatus = 0;
=======
#define LED D1
void printWifiStatus();
String prepareHtmlPage();

char ssid[] = "x x";      // your network SSID (name)
char pass[] = "x";   // your network password

WiFiServer server(80);
>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490

void setup()
{
  Serial.begin(115200);
<<<<<<< HEAD
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();
  status->onMessage(handleMessage);
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
=======
  Serial.println();

  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED, OUTPUT);
<<<<<<< HEAD
  status->get();
=======

>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
  server.begin();

   printWifiStatus();
}

void loop() {

<<<<<<< HEAD
  io.run();
=======
>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  unsigned long timeout = millis() + 3000;
  while (!client.available() && millis() < timeout) {
    delay(1);
  }
  if (millis() > timeout) {
    Serial.println("timeout");
    client.flush();
    client.stop();
    return;
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request
  int val;
<<<<<<< HEAD
  if (req.indexOf("aus") != -1) {
    val = 0;
  } else if (req.indexOf("ein") != -1) {
    val = 1;
  } else if (req.indexOf("status") != -1){
    String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\nRefresh: 1\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nThe lamp is turned ";
    if(PinStatus){
      s += "on";
    }else{
      s+= "off";
    }
    client.print(s);
    return;
  } else{
=======
  if (req.indexOf("/gpio/0") != -1) {
    val = 0;
  } else if (req.indexOf("/gpio/1") != -1) {
    val = 1;
  } else {
>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
    Serial.println("invalid request");
    client.print("HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html><body>Not found</body></html>");
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(LED, val);
<<<<<<< HEAD
  PinStatus = val;
=======
>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val) ? "high" : "low";
  s += "</html>\n";
<<<<<<< HEAD
  status->save(val);
=======

>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
  // Send the response to the client
  client.print(s);
  delay(1);
Serial.println("Client disconnected");
<<<<<<< HEAD
//delay(1000);
=======
>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

String prepareHtmlPage()
{
  String htmlPage =
     String("HTTP/1.1 200 OK\r\n") +
            "Content-Type: text/html\r\n" +
            "Connection: close\r\n" +  // the connection will be closed after completion of the response
            "Refresh: 5\r\n" +  // refresh the page automatically every 5 sec
            "\r\n" +
            "<!DOCTYPE HTML>" +
            "<html>" +
            "Analog input:  " + String(analogRead(A0)) +
            "</html>" +
            "\r\n";
  return htmlPage;
}
<<<<<<< HEAD

void handleMessage(AdafruitIO_Data *data){
  Serial.print("received <- ");
  Serial.println(data->value());
  String data_rec = data->toString();
  String nameOn = DEVICE_NAME;
  String nameOff = DEVICE_NAME;
  if(!data_rec.compareTo(nameOff+ '0')){
    digitalWrite(LED, 0);
    PinStatus = 0;
    Serial.println("turning Off");
  }
  if(!data_rec.compareTo(nameOn+ '1')){
    digitalWrite(LED, 1);
    PinStatus = 1;
    Serial.println("turning On");
  }
}
=======
>>>>>>> 25181abbdd8034ae039a47bdf27f212d5c826490
