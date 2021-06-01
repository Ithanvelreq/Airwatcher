/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ------
#ifndef DEF_prov
#define DEF_prov

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <vector>
#include "Utilisateur.h"
#include "Purificateur.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Provider>
//classe abstraite fille de Utilisateur qui définit un Provider (fournisseur de purificateur)
//
//------------------------------------------------------------------------ 

class Provider : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    vector<Purificateur> getListe();

    void setListe (vector<Purificateur> liste);


//-------------------------------------------- Constructeurs - destructeur
    Provider(string id, vector<Purificateur> liste);
    // Constructeur de la classe Provider

    virtual ~Provider();
    // Destructeur de la classe Provider

//------------------------------------------------------------------ PRIVE 
protected:
//----------------------------------------------------- Attributs protégés
    vector<Purificateur> listePurifs;
};

//----------------------------------------- Types dépendants de <Provider>

#endif // DEF_prov