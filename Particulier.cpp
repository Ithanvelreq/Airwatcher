#include <iostream>
#include <string>
using namespace std;
#include "Particulier.h"

Particulier::Particulier(string id, vector<Capteur> liste):Utilisateur(id){
    listeCapteurs = liste;
}
Particulier:: ~Particulier(){}