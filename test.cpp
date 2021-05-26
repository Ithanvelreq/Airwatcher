#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Utilisateur.h"
#include "Admin.h"
#include "Gouvernement.h"
#include "Particulier.h"
#include "Provider.h"


int main(){
    Utilisateur *user1 = new Utilisateur("util1");
    delete user1;
    struct Cleaner c1;
    c1.cleanerId = "0001";
    vector<Cleaner> liste = {c1};
    Provider* fournisseur = new Provider("p1", liste);
    delete fournisseur;
    Gouvernement* utiGouv = new Gouvernement("g1");
    delete utiGouv;
    


}