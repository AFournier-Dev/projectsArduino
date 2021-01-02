/* 
  Feu tricolore
 
 TP de la semaine 1 du MOOC "Programmer un objet avec Arduino"
 Allume trois LED comme suit :
 Verte allumée pendant 3 secondes
 Orange allumée pendant 1 seconde
 Rouge allumée pendant 3 secondes

 
 Le montage :
 * Une LED rouge sur la broche 2 en série avec une résistance de 220Ω
 * Une LED orange sur la broche 3 en série avec une résistance de 220Ω
 * Une LED verte sur la broche 4 en série avec une résistance de 220Ω
 
 créé le 18 Mai 2018
 par Baptiste Gaultier
 
 Ce code est en CC0 1.0 Universal
 
 https://www.fun-mooc.fr/courses/MinesTelecom/04017/session01/about
 */

int rouge = 2;
int orange = 3;
int verte = 4;

// le code dans cette fonction est exécuté une fois au début
void setup() {
  // indique que les broches des LED
  // sont des sorties :
  pinMode(rouge, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(verte, OUTPUT);     
}

// le code dans cette fonction est exécuté en boucle
void loop() {
  digitalWrite(verte, HIGH);
  delay(3000);
  digitalWrite(verte, LOW);
  
  digitalWrite(orange, HIGH);
  delay(1000);
  digitalWrite(orange, LOW);

  digitalWrite(rouge, HIGH);
  delay(3000);
  digitalWrite(rouge, LOW);

  
}