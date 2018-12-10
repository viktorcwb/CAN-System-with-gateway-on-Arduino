//Federal Technologic University of Paraná
//Embeded Systems for Automotive Industry Especialization
//Students: Adriano Marcelino, Ataide Aires, Luis Gavlovski, Lucas Romário, Matheus Pizzatto, Tiago Araujo, Victor Volochtchuk
//Teacher: Doc. Max Mauro Dias
//08/12/2018


#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include <SPI.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9; // Set CS pin
const int ledHIGH = 1;
const int ledLOW = 0;
float cmMsec, inMsec;
//long sensorValue = 0;
long sensorValue1 = 0;
//long sensorValue2 = 0;
unsigned char stmp1 = 0;

MCP_CAN CAN(SPI_CS_PIN);

#define pino_poten A0


void setup()
{
  Serial.begin(250000);
  while (CAN_OK != CAN.begin(CAN_500KBPS)) // init can bus : baudrate = 125k
  {
    Serial.println("CAN BUS Shield init fail");
    Serial.println(" Init CAN BUS Shield again");
    delay(10);
  }
  Serial.println("CAN BUS Shield init ok!");
   
  Serial.println("Lendo dados do sensor...");
  
  pinMode(pino_poten,INPUT);
 }


 
void loop()
{

      sensorValue1 = analogRead(pino_poten);
      Serial.print("\n sensorValue1: ");
      Serial.print(sensorValue1);
      stmp1=sensorValue1>>6;
//      stmp1[0] = sensorValue1>>0;
//     stmp1[1] = sensorValue1>>6;
     Serial.print("\n sensorValue1: ");
     Serial.print(stmp1);
//      stmp1[2] = sensorValue1>>16;
//      stmp1[3] = sensorValue1>>24;
      CAN.sendMsgBuf(0x02, CAN_STDID, 1, &stmp1);
//      // send data: id = 0x00, standard frame, data len = 1, stmp: data  buf

  delay(10); // send data once per second
}
