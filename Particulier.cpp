#include <iostream>
#include <string>
using namespace std;
#include "Particulier.h"

Particulier::Particulier(string id, vector<Sensor> liste):Utilisateur(id){
    listeCapteurs = liste;
}
Particulier:: ~Particulier(){}