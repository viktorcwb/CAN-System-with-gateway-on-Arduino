# CAN-System-with-gateway-on-Arduino
CAN-based Distributed System Architecture consists on 3 ECU's made on Arduino, with the job of read a potentiometer and activate LED's and a DC motor. 1 ECU perform the potentiomete read and send the data by CAN BUS with 500kbps, other ECU is responsble for recive the data from ECU 1 on 500 kbps, than retransmit it at 250kbps and the last one recieve the 250kbps data and activate 4 LED's and 1 DC motor accordling to the implemented logic.
Federal Technologic University of Paraná
Embeded Systems for Automotive Industry Especialization
Students: Adriano Marcelino, Ataide Aires, Luis Gavlovski, Lucas Romário, Matheus Pizzatto, Tiago Araujo, Victor Volochtchuk
Teacher: Doc. Max Mauro Dias
08/12/2018
