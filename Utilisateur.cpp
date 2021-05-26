#include <iostream>
#include <string>
using namespace std;
#include "Utilisateur.h"

Utilisateur::Utilisateur(string id){
    userId = id;
    motDePasse = "mdp";
    mail = "mail@gmail.com";
    nom = "Diego";
    prenom = "Maradona";
}

Utilisateur:: ~Utilisateur(){
}
