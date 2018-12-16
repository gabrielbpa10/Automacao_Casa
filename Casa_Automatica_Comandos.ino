
#include <Servo.h>


Servo myservo;
Servo myservo2;


int pos = 0;    // variavel da posição do servo
int pos2 = 0;
char aux; 
void setup() {

  myservo.attach(9);  // pino motor janela
  myservo2.attach(7);  // pino motor tranca
  pinMode(3,OUTPUT);//luz
  pinMode(4,OUTPUT);//luz lado de fora
  pinMode(10,OUTPUT);//abre a porta
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {

  Serial.println("Informe o numero:");
  delay(1000);
  aux = Serial.read();
  Serial.println(aux);
  if(aux == '1'){
  abrirJanela();
  } else if(aux == '2'){
  fecharJanela();  
  } else if(aux == '3'){
    abrirTranca();
  } else if(aux == '4'){
    fecharTranca();
  } else if(aux == '5'){
    acenderLuz();
  } else if(aux == '6'){
    apagarLuz();
  }else if(aux == '7'){
    fecharPorta();
  }else if(aux == '8'){
    abrirPorta();
  }
}

void abrirJanela(){
  for (pos = 5; pos <= 110; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                      
  }
}  

 void fecharJanela(){
  for (pos = 110; pos >= 5; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
 }
  void abrirTranca(){
   for (pos = 90; pos2 <= 180; pos2 += 1) { 
    myservo2.write(pos2);             
    delay(15);      
  }}
  void fecharTranca(){
     for (pos = 180; pos2 >= 90; pos2 -= 1) { 
    myservo2.write(pos2);              
    delay(15);      
  }
  }
  void acenderLuz(){
    digitalWrite(3, HIGH);   
                            
  
  }
  void apagarLuz(){
    digitalWrite(3,LOW);
  }
 void abrirPorta(){
  digitalWrite(4, LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(700);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(600);

 }
 void fecharPorta(){
  digitalWrite(4, HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(700);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(600);

 }


