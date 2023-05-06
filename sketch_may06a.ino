#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

IPAddress my_ip(192, 168, 1, 7);
IPAddress ip_client(192, 168, 1, 1);
byte my_mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
unsigned int localPort = 1024;
EthernetUDP Udp;
void setup()
{
  Serial.begin(9600);
  Ethernet.begin(my_mac, my_ip);
  Udp.begin(localPort);
}
void udp_send(String u)
{
    Udp.beginPacket(ip_client, localPort);
    Udp.print(u);
    Udp.endPacket();   
}
void loop()
{
    udp_send("2724120502");
    delay(100);
}
