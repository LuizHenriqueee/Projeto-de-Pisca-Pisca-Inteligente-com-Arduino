//Carrega a biblioteca do RTC DS1307
#include <DS1307.h>
 
//Modulo RTC DS1307 ligado as portas A4 e A5 do Arduino 
DS1307 rtc(A4, A5);
 
void setup()
{
  //Pino que liga o Relé
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);

  //Configura Modulo RTC
  //Aciona o relogio
  rtc.halt(false);
   
  //As linhas abaixo setam a data e hora do modulo
  //e podem ser comentada apos a primeira utilizacao
  //rtc.setDOW(FRIDAY);      //Define o dia da semana
  //rtc.setTime(14, 22, 00);     //Define o horario
  //rtc.setDate(17, 12, 2020);   //Define o dia, mes e ano
   
  //Definicoes do pino SQW/Out
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
   
  Serial.begin(9600);
}

Time t;

void loop()
{
  
  //hora = rtc.getTimeStr();
  t = rtc.getTime();
  Serial.println(rtc.getTimeStr());

  digitalWrite(13,HIGH);
  
  if((t.hour < 18) || (t.hour >= 23)){
    digitalWrite(7,HIGH);
    Serial.println("Desligado");
  } else{
    digitalWrite(7,LOW);
    Serial.println("Ligado");
  }
  
  delay(1000);
}
