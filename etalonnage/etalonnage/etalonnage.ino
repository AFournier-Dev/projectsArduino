const int capteur = 0; //capteur branché sur la pin analogique 0
float tension = 0.0;
int valeur = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    valeur = analogRead(capteur);
    tension = (valeur*5.0)/1024;

    Serial.print("Tension : ");
    Serial.print(tension);
    Serial.println(" V");
    Serial.print("Valeur : ");
    Serial.println(valeur);
    Serial.println("---------------------");

    delay(500);
}

// attention code non complet cf dossier avec documents
