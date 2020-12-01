
// --- Que fait ce programme ? ---
/* Fait clignoter une LED*/

// --- Circuit à réaliser ---
// Connecter une LED en série avec résistance sur la broche 2 (configurée en sortie)



// --- constantes des broches ---

const int LED=13; //declaration constante de broche

void setup()   {
pinMode(LED, OUTPUT); 
} 

void loop(){

digitalWrite(LED,HIGH);
delay(250);
digitalWrite(LED,LOW);
delay(125);}
