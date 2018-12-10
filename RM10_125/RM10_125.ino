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
//const int SPI_CS_PIN = 9; // Set CS pin
float cmMsec, inMsec;
long sensorValue1 = 0;
unsigned char len = 0;
unsigned char buf[8];
unsigned long ID = 0;
unsigned char mask = 1;

#define pino_led_0 28
#define pino_led_1 30
#define pino_led_2 32
#define pino_led_3 34
#define pino_pwm 8

MCP_CAN CAN(11);

 
//Inicializa o sensor nos pinos definidos acima

void setup()
{
  Serial.begin(250000);
  while (CAN_OK != CAN.begin(CAN_250KBPS)) // init can bus : baudrate = 250k
  {
    Serial.println("CAN BUS Shield init fail");
    Serial.println(" Init CAN BUS Shield again");
    delay(100);
  }
  Serial.println("CAN BUS Shield init ok with 250K!");
   
  Serial.println("Lendo dados do sensor...");
  pinMode(pino_led_0,OUTPUT);
  pinMode(pino_led_1,OUTPUT);
  pinMode(pino_led_2,OUTPUT);
  pinMode(pino_led_3,OUTPUT);
  pinMode(pino_pwm,OUTPUT);
}
 
void loop()
{  
    if(CAN_MSGAVAIL == CAN.checkReceive())            // Check to see whether data is read
    {
     ID = CAN.getCanId();
     //Serial.print("Chegou");
      
      CAN.readMsgBufID(&ID, &len, buf);
      //Serial.print(ID);

Serial.print("\r\n");
        Serial.print("Mensagem 0x200");
        CAN.readMsgBuf(&len, buf);    // Read data
        sensorValue1 = buf[0];
        Serial.print('\t');
        Serial.print(sensorValue1);
        Serial.print('\t');       
    }


    
    digitalWrite(pino_led_0,mask & buf[0]);
    digitalWrite(pino_led_1,mask<<1 & buf[0]);
    digitalWrite(pino_led_2,mask<<2 & buf[0]);
    digitalWrite(pino_led_3,mask<<3 & buf[0]);
    analogWrite (pino_pwm,buf[0]*17);
    

  delay(10); // send data once per second
}
