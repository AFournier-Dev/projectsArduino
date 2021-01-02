/*
    Thérémine lumineux
 
 Le montage :
 * Un piezo branché sur la broche 8
 * Une photorésistance branchée sur la broche A2 depuis +5V
 * Une résistance de 10kΩ branchée sur la broche A2 depuis GND
 
 créé le 9 Avril 2014
 par Baptiste Gaultier
 
 Ce code est en CC0 1.0 Universal
 
 https://www.france-universite-numerique-mooc.fr/courses/MinesTelecom/04002/Trimestre_1_2014/about
*/

// variable pour stocker la valeur reçue sur A2
int sensorValue;

void setup() {
}

void loop() {
  // lire la valeur de la photorésistance et stocker ça dans une variable
  // Attention, sur les schéma/montage en dessous, elle est branchée sur A2 (et non A0)
  sensorValue = analogRead(A2);

  // re étalonne la variable vers un grand intervalle de fréquences audibles
  int pitch = map(sensorValue, 0, 1023, 50, 30000);

  // jouer la fréquence sur le piezo branché sur la broche 8
  tone(8, pitch);

  // attendre 10 ms
  delay(10);
}