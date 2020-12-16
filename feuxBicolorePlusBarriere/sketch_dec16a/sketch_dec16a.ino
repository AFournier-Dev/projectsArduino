// Les vidéos et les codes de mes TP Arduino se trouvent sur mon site perso:
// http://uncledens.chez-alice.fr/arduino/index.htm
//
// Pour ce TP : https://youtu.be/zLJA9I9N2B4

#include <Servo.h> 

Servo servo; // création de l'objet servo


// 3 constantes
const int bouton = 2;

const int ledRouge = 3;
const int ledVerte = 4;

// 2 variables :
int etatBouton = 0;
int pos = 0;

// exécution 1x au début
void setup() {
 // pour communiquer avec l'ordinateur
 Serial.begin(9600); 

 // les broches des LED en sortie
 pinMode(ledRouge, OUTPUT);
 pinMode(ledVerte, OUTPUT);

 // la broche bouton en entrée :
 pinMode(bouton, INPUT);

 // le servomoteur sur la broche 9
 servo.attach(9);

 // allume le feu rouge
 digitalWrite(ledRouge, HIGH); 

 // barrière horizontal 0 ; verticale 90
 servo.write(0);
}
// boucle infinie
void loop(){
 // lire la caleur du bouton:
 etatBouton = digitalRead(bouton);

 // si le bouton est appuyé
 if (etatBouton == HIGH) {
    // alors message sur le moniteur série
    Serial.print("Bouton appuye");

    // et barrière à 90°
    for(pos = 0; pos <= 90; pos++) {
        servo.write(pos);
        delay(15);
    }

    // puis feu vert pendant 5 secondes
    digitalWrite(ledRouge, LOW);
    digitalWrite(ledVerte, HIGH);
    delay(5000);

    // et de nouveau le rouge
    digitalWrite(ledVerte, LOW);
    digitalWrite(ledRouge, HIGH);

    // enfin, barrière descend de 90° à 0°
    for(pos = 90; pos>=0; pos--) {
        servo.write(pos);
        delay(15);
    }
 }
}
