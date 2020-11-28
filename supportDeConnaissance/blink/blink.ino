/*
  Clignotement
  Allume la LED 13 pendant 1 seconde,
  puis l'éteint pendant 1 seconde.
*/

// On stocke la valeur 13 dans la variable "led", pour indiquer que la led se trouve sur la broche 13 
// La variable "led" est un nombre entier (integer in english)
int led = 13;

// le code dans cette fonction est exécuté une fois au début 
void setup() {

// indique que la broche de la LED 13 est une sortie :  
pinMode(led, OUTPUT); 
} 

// le code dans cette fonction est exécuté en boucle 
void loop() {  
digitalWrite(led, HIGH);   // allumer la LED (tension 5V sur la broche)  
delay(1000);                       // attendre 1000ms = 1s  
digitalWrite(led, LOW);    // éteindre la LED (tension 0V sur la broche)  
delay(1000);                       // attendre à nouveau 1 seconde 
}
