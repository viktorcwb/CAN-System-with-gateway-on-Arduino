//Federal Technologic University of Paraná
//Embeded Systems for Automotive Industry Especialization
//Students: Adriano Marcelino, Ataide Aires, Luis Gavlovski, Lucas Romário, Matheus Pizzatto, Tiago Araujo, Victor Volochtchuk
//Teacher: Doc. Max Mauro Dias
//08/12/2018

#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include <SPI.h>

const int SPI_CS_PIN_CAN2 = 11; // Set CS pin for CAN2
const int SPI_CS_PIN_CAN3 = 9; // Set CS pin for CAN3

MCP_CAN CAN2(SPI_CS_PIN_CAN2);
MCP_CAN CAN3(SPI_CS_PIN_CAN3);

void setup()
{
  Serial.begin(9600);
  while (CAN_OK != CAN2.begin(CAN_500KBPS)) // init can bus : baudrate = 500k
  {
    Serial.println("CAN2 BUS Shield init fail");
    Serial.println(" Init CAN2 BUS Shield again");
    delay(10);
  }
  Serial.println("CAN2 BUS Shield init ok with 500K!");

  while (CAN_OK != CAN3.begin(CAN_250KBPS)) // init can bus : baudrate = 250k
  {
    Serial.println("CAN3 BUS Shield init fail");
    Serial.println(" Init CAN3 BUS Shield again");
    delay(10);
  }
  Serial.println("CAN3 BUS Shield init ok with 250K!");
}

void loop()
{
 
}
