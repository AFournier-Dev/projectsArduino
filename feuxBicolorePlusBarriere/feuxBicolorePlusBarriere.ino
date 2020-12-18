#include <Servo.h> 

Servo myservo;  // créer un objet appelé myservo à partir
// du moule Servo

int pos = 0;    // variable pour stocker la position courante du servo
const int buttonPin = 2;     // Numéro de la broche à laquelle est connecté le bouton poussoir
int buttonState = 0;         // variable qui sera utilisée pour stocker l'état du bouton
void setup() 
{ 
  myservo.attach(9);  // attacher notre objet myservo au servomoteur branché sur la broche 9 
  
  pinMode(buttonPin, INPUT);  // indique que la broche buttonPin est une entrée
  
  pinMode(4, OUTPUT); // LED VERTE
  pinMode(3, OUTPUT); // LED ROUGE
  digitalWrite(3, HIGH); // Allume la led Rouge à l'initialisation
} 


void loop() 
{ 
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH){
    for(pos = 0; pos <= 90; pos += 1){  // aller de 0° à 179°// une étape à la fois
      myservo.write(pos);              // aller à la position stocké dans 'pos'
      delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
    } 
    digitalWrite(3, LOW); // eteindre LED rouge  
    digitalWrite(3, HIGH);// allumer la verte
  delay(5000); // attendre 5s
    digitalWrite(3, HIGH); // allumer la rouge

    
    for(pos = 90; pos>=0; pos-=1){     /// aller de 180° à 1°
    myservo.write(pos);              // aller à la position stocké dans 'pos'
      delay(15);                       // attendre 15ms que le servomoteur se rende à 'pos'
    } 
  }
  
  
}  
