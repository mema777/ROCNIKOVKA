#include <OneWire.h>
#include <DallasTemperature.h>

#define mosfet A3  
#define ONE_WIRE_BUS A0

int t1 = 0;
int t2 = 0;
byte maxt;

OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);

int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};
byte digit1, digit2, digit3;  
           void setup()  
         {  
              sensors.begin();  
         //     Serial.begin(9600);
              pinMode(A3, OUTPUT);  
              pinMode(A1, OUTPUT);  

         
           for (int i = 2; i < 9; i++)  
             {  
              pinMode(i, OUTPUT);  
             }  

              pinMode(11, OUTPUT);  
              pinMode(12, OUTPUT);  
              pinMode(13, OUTPUT);  
         }  





         
          void loop() {  
            disoff();

             gettemp();
             vypis(t1);
             delay(1000);
             disoff();
             delay(500);

             pulvypis(t2);
             delay(1000);
             disoff();
             delay(500);
             
             
             maxt = map(analogRead(A5),0,1023,50,10);
             vypispot();
             delay(500);
             disoff();
             delay(300);


          //     Serial.print(t1);  Serial.print("        ");  Serial.print(t2); Serial.print("        ");  Serial.println(maxt);



          if (t1 >=(t2+50) && t1<(maxt*10))
          {digitalWrite(mosfet, 1);}
         
          else if ((t1 <(t2+40)) || (t1>(maxt*10)))
          {digitalWrite(mosfet, 0);}
           
           }
