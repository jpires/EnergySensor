#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>

#include <SPI.h>         
#include <Ethernet.h>
#include <Udp.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x7A, 0x0C};
byte ip[] = {192, 168, 10, 10};
byte gateway[] = {192, 168, 10, 1};
byte sub[] = {255, 255, 255, 0};
unsigned int localPort = 8888;      // local port to listen for UDP packets

IPAddress server(192, 168, 10, 10); //CHANGE TO APROPRIATED VALUE
uint16_t port = 8080; //CHANGE TO APROPRIATED VALUE
EthernetClient client;
EthernetUDP Udp;

void setup()
{
  // start Ethernet and UDP
  Ethernet.begin(mac,ip, sub, gateway);
//  Udp.begin(localPort);
  Serial.begin(9600);
  Udp.begin(localPort);
}

void loop(){

	//delay(500);

	int sample[300];
	sample[0] = analogRead(0);
	Serial.println(sample[0]);

	//for(int i=0; i < 3000; i++){
	//	sample[i] = analogRead(0);
	//}

	//for(int i=0; i < 3000; i++){
	//	Serial.println(sample[i]);
	//}


	/*double power, energy;
    powerMeter(&power, &energy);
    Serial.println(power, 3);
    Serial.println(energy, 3);
	//Serial.println(1.0/3, 3);



  /*unsigned long time = unixTime();
    Serial.println(time);
  if(client.connected()){
    Serial.println("Entrei");
    int power, energy;
    powerMeter(&power, &energy);
    Serial.println(power);
        Serial.println(energy);
    unsigned long time = unixTime();
    
    char* str = createPOST(time, power, energy);
    
    client.println(str);
        Serial.println(str);
    free(str);
    
    delay(500);
    int size = client.available();
    char response[50];
    
    int i=0;
    while(i < size){
      Serial.print(client.read());
      //response[i] = client.read();
      i++;  
    }
    client.flush();
  }else{
    client.connect(server, port);
    Serial.println("Connected");
  }*/
  //delay(500);
}
