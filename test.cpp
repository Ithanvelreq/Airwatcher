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
    Particulier p("p1", liste);
    Gouvernement g1("g1");
    Purificateur pur1("pur1", 1009.2, 57.2, "19-02-2021", "31-05-2021");
    Purificateur pur2("pur2", 1009.2, 57.2, "19-02-2021", "31-05-2021");
    
    vector<Purificateur> listePurifs = {pur1, pur2};
    Provider pro("pro1", listePurifs);

    vector<Purificateur> vp = pro.getListe();
    afficherVector(vp);

    
    Admin a("A");
}

void afficherVector(vector<Purificateur> vp){
    for(auto const & it : vp){
     cout<<it;
     /* OU OU OU */
     it.print(std::cout);
}
