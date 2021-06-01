/*************************************************************************
                           Admin  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Réalisation de la classe <Admin> (fichier Admin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Admin.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Admin::Admin(string id):Utilisateur(id)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Admin>" << endl;
    #endif
} //----- Fin de Admin


Admin:: ~Admin()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Admin>" << endl;
    #endif
} //----- Fin de ~Admin

