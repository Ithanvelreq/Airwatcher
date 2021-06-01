/*************************************************************************
                           Admin  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Interface de la classe <Admin> (fichier Admin.h) ------
#ifndef DEF_admin
#define DEF_admin

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <Utilisateur.h>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Admin>
//classe abstraite fille de Utilisateur qui définit un utilisateur de type administrateur
//
//------------------------------------------------------------------------ 

class Admin : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeurs - destructeur
    Admin(string userId);
    // Constructeur de la classe Admin

    virtual ~ADmin();
    // Destructeur de la classe Admin
};

//----------------------------------------- Types dépendants de <Admin>

#endif // DEF_admin
