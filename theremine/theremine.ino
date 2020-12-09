/*
Entrée et sortie analogiques + communications série

Ce programme va émettre des sons à l'aide d'un buzzer branché sur la broche 8.
Le son émit par le buzzer sera proportionnel à la luminosité
captée par la photorésistance branchée sur la broche A2.

*/
// Initialisation des constantes :
const int brocheCapteur=A2; // Numéro de la broche à laquelle est connecté la photorésistance
const int brocheBuzzer=8; // Numéro de la broche à laquelle est connectée le buzzer
int valeurCapteur=0; // Valeur lue sur la photorésistance
int valeurSortieBuzzer=0; // Valeur envoyée au buzzer
void setup() {
// Initialise la communication avec l'ordinateur
Serial.begin(9600);
// Indique que la broche brocheCapteur est une entrée :
pinMode(brocheCapteur, INPUT);
// Indique que la broche brocheBuzzer est une sortie :
pinMode(brocheBuzzer, OUTPUT);

}

void loop() {
// lit la valeur de la photorésistance et
// stocke le résultat dans valeurCapteur :
valeurCapteur=analogRead(brocheCapteur);
// change valeurCapteur vers une intervalle de 50 à 30000
// et stocke le résultat dans valeurSortieBuzzer :
valeurSortieBuzzer=map(valeurCapteur, 0, 1024, 50, 30000);
// envoie de cette nouvelle valeur de valeurSortieBuzzer sur le buzzer
// ce qui permetra d'émettre du son
tone(brocheBuzzer, valeurSortieBuzzer);
// envoie les valeur vers l'ordinateur
// juste pour afficher les valeur dans
// le moniteur serie
Serial.print("valeur entrée capteur = ");
Serial.print(valeurCapteur);
Serial.print("\t valeur sortie Buzzer = ");
Serial.println(valeurSortieBuzzer);
//attendre 2 millisecondes pour permettre au son de se moduler
delay(2);

}
