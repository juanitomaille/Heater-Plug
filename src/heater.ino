/* Zone commune pour tous les capteurs, à adapter */

#include <sstream>
#include <string>

// la librairie UP-RISE
#include <protovox.h>
const char*       PROTOVOX_HARDWARE_NAME = "ESP01S-HEATER";  //identification du hardware sur le réseau
const char*       PROTOVOX_TOPIC_PATH = "/home/heater";
const char*       PROTOVOX_HUMAN_NAME = "prise chaudière";
#define           PROTOVOX_VERSION      "v0.3"






Protovox  myProtovox;

// Temps de veille profonde (deep sleep) entre 2 mesures.
// La veille profonde est indispensable et nécessite de relier physiquement les broches RST et DO
#define durationSleep 500 // secondes



/* FIN de zone commune*/

/* Zone déclaration spécifique aux capteurs */



/* FIN de zone spécifique */


bool heaterState = false;


void setup() {



  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("------  |||   START   |||   ------");
  Serial.println();
  Serial.print("VERSION SENSOR :"); Serial.println(PROTOVOX_VERSION);
    // gestion de la connection au wifi et MQTT

  myProtovox.connect(PROTOVOX_HARDWARE_NAME, PROTOVOX_TOPIC_PATH);

  char* topic_string;
  strcat(topic_string, PROTOVOX_TOPIC_PATH);
  strcat(topic_string, "/state"); // MQTT : état de la chaudière


  mqtt.subscribe(topic_string,1);
}

void loop() {
  //Serial.println("en attente de mise à jour ...");
  mqtt.loop();

  // on récupère le résultat de la requète MQTT:

  Serial.println(myProtovox.getTopic());
  Serial.println(myProtovox.getMessage());
  Serial.println();


}
