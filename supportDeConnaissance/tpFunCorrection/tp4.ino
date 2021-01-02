/*
  Feu bicolore et barrière
 
 Le montage :
 * Une LED rouge sur la broche 3 en serie avec une resistance de 220Ω
 * Une LED verte sur la broche 4 en serie avec une resistance de 220Ω
 
 * Un servomoteur branché sur les broches 9, +5V et GND
 
 * Bouton poussoir branché sur la broche 2 depuis +5V
 * Une résistance de 1KΩ bracnhé sur la broche 2 depuis GND
 
 créé le 18 Avril 2014
 par Baptiste Gaultier
 
 Ce code est en CC0 1.0 Universal
 
 https://www.france-universite-numerique-mooc.fr/courses/MinesTelecom/04002/Trimestre_1_2014/about
 
 */
 
#include <Servo.h> 
 
Servo servo;  // création de l'objet servo issu
              // du moule Servo
 

// Initialisation des constantes
const int bouton = 2;

const int ledRouge =  3;
const int ledVerte =  4;

// Déclaration des variables :
int etatBouton = 0;
int pos = 0;

// le code dans cette fonction est exécuté une fois au début
void setup() {
  // on souhaite communiquer avec l'ordinateur
  Serial.begin(9600); 
  
  // indique que les broches des LED
  // sont des sorties :
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVerte, OUTPUT);
  
  // indique que la broche bouton est une entrée :
  pinMode(bouton, INPUT);
  
  // on accroche notre servomoteur branché sur la broche 9
  servo.attach(9);
  
  // allume le feu rouge
  digitalWrite(ledRouge, HIGH); 
  
  // positionne la barrière horizontalement
  servo.write(0);
}

// le code dans cette fonction est exécuté en boucle
void loop(){
  // read the state of the pushbutton value:
  etatBouton = digitalRead(bouton);

  // si le bouton est appuyé
  if (etatBouton == HIGH) {
    // alors on envoie un message sur le moniteur série
     Serial.print("Bouton appuye");
     
    // puis on remonte la barrière de 90°
    for(pos = 0; pos <= 90; pos++) {
      servo.write(pos);
      delay(15);
    }
    
    // puis on allume le feu vert durant 5 secondes
    digitalWrite(ledRouge, LOW);
    digitalWrite(ledVerte, HIGH);
    delay(5000);
    
    // et on repasse au rouge
    digitalWrite(ledVerte, LOW);
    digitalWrite(ledRouge, HIGH);
    
    // enfin, on redescend la barrière
    for(pos = 90; pos>=0; pos--) {
      servo.write(pos);
      delay(15);
    }
  }
}