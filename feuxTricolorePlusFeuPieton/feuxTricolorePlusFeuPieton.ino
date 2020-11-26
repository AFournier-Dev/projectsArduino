/*
 * Feux tricolore avec feux pieton activé par un bouton poussoir
 */

/*
 * Initialisation des constantes
 */

//bouton poussoir
const int buttonPin = 2;          // declaration de la constante bouton poussoir sur la broche 2

//LED du feux tricolore
const int ledPinGreenCar = 10;    // declaration de la constante feu vert voiture sur la broche 10
const int ledPinOrangeCar = 11;   // declaration de la constante feu orange voiture sur la broche 11
const int ledPinRedCar = 12;      // declaration de la constante feu rouge voiture sur la broche 12

//LED feux pieton
const int ledPinGreenWalker = 8; // declaration de la constante feu rouge voiture sur la broche 8
const int ledPinRedWalker = 9;   // declaration de la constante feu rouge voiture sur la broche 9


// Déclaration des variables :
int buttonState = 0;         // variable qui sera utilisée pour stocker l'état du bouton

/*Ici on declare dans le setup 
 * tout les led (3+2) en output
 * le bouton poussoir en Input
 */

void setup() {

 
  pinMode(buttonPin, INPUT); // indique que la broche buttonPin est une entrée
  
  pinMode(ledPinGreenCar, OUTPUT);     // indique que la broche ledPinGreenCar est une sortie
  pinMode(ledPinOrangeCar, OUTPUT);    // indique que la broche ledPinOrangeCar est une sortie
  pinMode(ledPinRedCar, OUTPUT);       // indique que la broche ledPinRedCar est une sortie
  
  pinMode(ledPinGreenWalker, OUTPUT);  // indique que la broche ledPinGreenWalker est une sortie
  pinMode(ledPinRedWalker, OUTPUT);    // indique que la broche ledPinRedWalker est une sortie

    /*CE CODE EST EN COMMENTAIRE CAR J AI REFACTORISER LE CODE EN V2 AVEC DECLARATION DE CONSTANTE
    pinMode(10, OUTPUT); // LED verte pour feux tricolore voiture
    pinMode(11, OUTPUT); // LED orange pour feux tricolore voiture
    pinMode(12, OUTPUT); // LED rouge pour feux tricolore voiture
    */
}

void loop() { // le code dans cette fonction est exécuté en boucle

  // lit l'état du bouton et stocke le résultat
  // dans buttonState :
  

// lecture de l'état du bouton dans buttonState idem debut semaine 2

// Si buttonState est à 5V (HIGH→bouton appuyé)
  
buttonState = digitalRead(buttonPin);  

  if (buttonState == LOW) {  
     
    // sinon boucle pour le feux des voiture avec les constantes déclarées au début avant le setup
    digitalWrite(ledPinRedWalker, HIGH); //allume le feu rouge pieton tant qu'on est dans le else 
                                         //     donc pas d'appuie sur le bouton
    digitalWrite(ledPinGreenCar, HIGH);
    delay(3000);
    digitalWrite(ledPinGreenCar, LOW);
    digitalWrite(ledPinOrangeCar, HIGH);
    delay(1000);
    digitalWrite(ledPinOrangeCar, LOW); 
    digitalWrite(ledPinRedCar, HIGH);
    delay(3000);
    digitalWrite(ledPinRedCar, LOW);
    
    
    
  } 
   if (buttonState == HIGH){
   // on allume le feu vert des pietons
    digitalWrite(ledPinRedWalker, LOW);     //extinction du feu rouge pieton
    digitalWrite(ledPinGreenWalker, HIGH);  //allume le feu vert pieton
    delay(5000);                            //    pendant 5s (5000ms);
    digitalWrite(ledPinGreenWalker, LOW);  //eteind le feu vert pieton
    digitalWrite(ledPinRedWalker, HIGH);    //allume le feu rouge et fin du if et retour dans la boucle 
  }

delay (2000); //ici on attend 2secondes pour refaire le test sur le bouton ca oblige a rester longtemps sur le bouton poussoir car il faut appuyer suffisament longtemps pour que ça soit pris en compte.
                  //même si le delai est à 20ms il faut appuyer suffisament longtemps car au bon moment

  /*
   * premiere boucle du feux tricolore
   */
    

}
