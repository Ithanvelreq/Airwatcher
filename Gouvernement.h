/*************************************************************************
                           Gouvernement  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Interface de la classe <Gouvernement> (fichier Gouvernement.h) ------
#ifndef DEF_gouv
#define DEF_gouv

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include "Utilisateur.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Gouvernement>
//classe abstraite fille de Utilisateur qui définit un utilisateur de type Gouvernement
//
//------------------------------------------------------------------------ 

class Gouvernement : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeurs - destructeur
    Gouvernement(string userId);
    // Constructeur de la classe Gouvernement

    virtual ~Gouvernement();
    // Destructeur de la classe Gouvernement
};

//----------------------------------------- Types dépendants de <Gouvernement>

#endif // DEF_gouv
