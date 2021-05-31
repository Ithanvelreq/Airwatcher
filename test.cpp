#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Utilisateur.h"
#include "Admin.h"
#include "Gouvernement.h"
#include "Particulier.h"
#include "Provider.h"
#include "Sensor.h"
#include "Purificateur.h"

int main(){
    Utilisateur user1("util1");
    Sensor s1 ("s1", 100.5, 65.3);
    Sensor s2 ("s2", 100.5, 65.3);
    vector<Sensor> liste = {s1, s2};
    Provider* fournisseur = new Provider("p1", liste);
    delete fournisseur;
    Gouvernement* utiGouv = new Gouvernement("g1");
    delete utiGouv;
    


}