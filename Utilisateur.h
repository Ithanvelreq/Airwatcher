/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ------
#ifndef DEF_utilisateur
#define DEF_utilisateur

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Utilisateur>
//classe abstraite qui définit un utilisateur
//
//------------------------------------------------------------------------ 

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getId();
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Utilisateur(string id, string mdp="", string email="", string n="", string p="");
    // Constructeur de la classe Utilisateur

    virtual ~Utilisateur();
    // Destructeur de la classe Utilisateur

//------------------------------------------------------------------ PRIVE 
protected:
//----------------------------------------------------- Attributs protégés
    string userId;
    string motDePasse;
    string mail;
    string nom;
    string prenom;
};

//----------------------------------------- Types dépendants de <Utilisateur>

#endif // DEF_utilisateur
