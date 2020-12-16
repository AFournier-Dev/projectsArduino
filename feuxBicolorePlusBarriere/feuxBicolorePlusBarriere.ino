#include <Servo.h> 

Servo myservo;  // créer un objet appelé myservo à partir
// du moule Servo

int pos = 90;    // variable pour stocker la position courante du servo
const int rouge = 3;
const int verte = 4;
const int bouton = 2;  //Le bouton est connecté à la PIN 2
int etatbouton = 0;
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attacher notre objet myservo au servomoteur branché sur la broche 9 
  pinMode(rouge, OUTPUT); // Défintion des entrées/sorties
  pinMode(verte, OUTPUT);
  pinMode(bouton, INPUT);
} 


void loop() 
{ 
   digitalWrite(rouge, HIGH);
  digitalWrite(verte, LOW);



  for(pos = 90; pos < 180; pos += 1)  // aller de 0° à 179°
  {                                  // une étape à la fois
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(5);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
  for(pos = 180; pos>=90; pos-=1)     /// aller de 180° à 1°
  {                                
    myservo.write(pos);              // aller à la position stocké dans 'pos'
    delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
}  
