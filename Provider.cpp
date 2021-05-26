#include <iostream>
#include <string>
using namespace std;
#include "Provider.h"

Provider::Provider(string id, vector<Purificateur> liste):Utilisateur(id){
    listeCleaners = liste;
}
Provider:: ~Provider(){}