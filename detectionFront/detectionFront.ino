/*
Probleme de vitesse de lecture +1 pls fois par seconde préférer un système en changement d'état
*/

/* ===> ICI ce code implémente de x fois/seconde


int monBouton = 2; // bouton en broche 2
int compteur = 0;  // un compteur
int etatBouton; // L'état du bouton

void setup() {
  // le bouton en entrée
  pinMode(monBouton, INPUT); 
}

void loop() {
  // si on appuie sur le bouton
  etatBouton = digitalRead(monBouton);
  if(etatBouton == HIGH) {
    // alors on incrémente le compteur
    compteur = compteur+1;
  }
}


*/
int monBouton = 2; // bouton en broche 2
int compteur = 0;  // un compteur
int etatBouton; // L'état du bouton
int memoire = LOW; // La mémoire de l'état du bouton

void setup() {
  // le bouton en entrée
  pinMode(monBouton, INPUT); 
}

void loop()
{
    // lecture de l'état du bouton
    etatBouton = digitalRead(monBouton);

    // Si le bouton a un état différent de celui enregistré ET
    // que cet état est "haut"
    if((etatBouton != memoire) && (etatBouton == HIGH))
    {
        // on incrémente le compteur
        compteur++;
    }

    // on enregistre l'état du bouton pour le tour suivant
    memoire = etatBouton;
}
/**/