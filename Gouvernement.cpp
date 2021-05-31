/*************************************************************************
                           Gouvernement  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Réalisation de la classe <Gouvernement> (fichier Gouvernement.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Gouvernement.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Gouvernement::Gouvernement(string id):Utilisateur(id)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Gouvernement>" << endl;
    #endif
} //----- Fin de Gouvernement


Gouvernement:: ~Gouvernement()
{
#ifdef MAP
    cout << "Appel au destructeur de <Gouvernement>" << endl;
#endif
} //----- Fin de ~Gouvernement

