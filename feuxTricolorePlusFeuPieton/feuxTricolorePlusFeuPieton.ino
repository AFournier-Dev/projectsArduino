/*
 * Feux tricolore avec feux pieton activé par un bouton poussoir
 */

/*
 * Initialisation des constantes
 */

//bouton poussoir
const int buttonPin = 2; // declaration de la constante bouton poussoir sur la broche 2

//LED du feux tricolore
const int ledPinGreenCar = 10;  // declaration de la constante feu vert voiture sur la broche 10
const int ledPinOrangeCar = 11; // declaration de la constante feu orange voiture sur la broche 11
const int ledPinRedCar = 12;    // declaration de la constante feu rouge voiture sur la broche 12

//LED feux pieton
const int ledPinGreenWalker = 8; // declaration de la constante feu rouge voiture sur la broche 8
const int ledPinRedWalker = 9;   // declaration de la constante feu rouge voiture sur la broche 9

// Déclaration des variables :
int buttonState = 0; // variable qui sera utilisée pour stocker l'état du bouton

/*Ici on declare dans le setup 
 * tout les led (3+2) en output
 * le bouton poussoir en Input
 */

void setup()
{

  pinMode(buttonPin, INPUT); // indique que la broche buttonPin est une entrée

  pinMode(ledPinGreenCar, OUTPUT);  // indique que la broche ledPinGreenCar est une sortie
  pinMode(ledPinOrangeCar, OUTPUT); // indique que la broche ledPinOrangeCar est une sortie
  pinMode(ledPinRedCar, OUTPUT);    // indique que la broche ledPinRedCar est une sortie

  pinMode(ledPinGreenWalker, OUTPUT); // indique que la broche ledPinGreenWalker est une sortie
  pinMode(ledPinRedWalker, OUTPUT);   // indique que la broche ledPinRedWalker est une sortie

  /*CE CODE EST EN COMMENTAIRE CAR J AI REFACTORISER LE CODE EN V2 AVEC DECLARATION DE CONSTANTE
    pinMode(10, OUTPUT); // LED verte pour feux tricolore voiture
    pinMode(11, OUTPUT); // LED orange pour feux tricolore voiture
    pinMode(12, OUTPUT); // LED rouge pour feux tricolore voiture
    */
}

void loop()
{ // le code dans cette fonction est exécuté en boucle

  // lit l'état du bouton et stocke le résultat
  // dans buttonState :

  // lecture de l'état du bouton dans buttonState idem debut semaine 2

  // Si buttonState est à 5V (HIGH→bouton appuyé)

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW)
  {

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
  if (buttonState == HIGH)
  {
    // on passe le feu voiture à rouge pendant 5 seconde
    digitalWrite(ledPinRedCar, HIGH);
    delay(5000);
    // on allume le feu vert des pietons

    digitalWrite(ledPinRedWalker, LOW);    //extinction du feu rouge pieton
    digitalWrite(ledPinGreenWalker, HIGH); //allume le feu vert pieton
    delay(5000);                           //    pendant 5s (5000ms);
    digitalWrite(ledPinGreenWalker, LOW);  //eteind le feu vert pieton
    digitalWrite(ledPinRedWalker, HIGH);
    digitalWrite(ledPinRedCar, LOW); //allume le feu rouge et fin du if et retour dans la boucle
  }
}

/*
NOTE MÉDIANE DES PAIRS. - 3 POINTS
Code fonctionnel mais améliorable 
PAIR 1 - CODE FONCTIONNEL MAIS AMÉLIORABLE
la ligne 86 : delay (2000); n'était pas demandée et laisse pendant 2 secondes le feu tricolore sans feu allumé. 
ligne 82 et 83 devraient être placée dans la condition "buttonState == LOW" car si on laisse le bouton appuyé le 
feu bicolore reste vert et le feu tricolore ne redémarre pas dans la condition "buttonState == HIGH" il manque 
l'instruction de passer le feu tricolore à rouge, ce qui a pour inconvénient de ne pas avoir de feu pour les voitures 
et de ne pas respecter l'instruction "puis rouge pendant 5 secondes" de l'énoncé.

PAIR 2 - CODE NON FONCTIONNEL
il faut garder en permanence le BP appuyé pour faire passer le feu pieton au vert, alors qu'il est demandé que 
l'appui sur le bouton soit detecté pendant que le feu auto est au vert, alors la sequence du feu pieton peut etre lancée

PAIR 3 - CODE FONCTIONNEL MAIS AMÉLIORABLE
Boucle du feu tricolore, une tempo de 2s en trop sur le cycle La gestion du bouton n'est pas correctement réalisée, le 
feu piéton doit s'activer lorsqu'on appui sur le bouton pendant que le feu tricolore vert est allumé. Le feu tricolore 
reste éteint pendant que le feu piéton passe au vert (risque d'accident).
*/
