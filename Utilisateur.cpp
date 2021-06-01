/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string Utilisateur::getId()
{
    return userId;
} //----- Fin de getId

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur(string id, string mdp, string email, string n, string p)
{
    #ifdef MAP
        cout << "Appel au constructeur de <${file_base}>" << endl;
    #endif
    userId = id;
    motDePasse = mdp;
    mail = email;
    nom = n;
    prenom = p;
} //----- Fin de Utilisateur


Utilisateur:: ~Utilisateur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur

