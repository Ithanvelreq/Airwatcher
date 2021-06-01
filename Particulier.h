/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ------
#ifndef DEF_parti
#define DEF_parti

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <vector>
#include "Utilisateur.h"
#include "Sensor.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Sensor>
//classe abstraite fille de Utilisateur qui définit un Particulier
//
//------------------------------------------------------------------------ 

class Particulier : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    vector<Sensor> getListe();

    void setListe (vector<Sensor> liste);

    int getPoint();

    void setPoint(int p);

    int getBanni();

    void setBanni(int b);

//-------------------------------------------- Constructeurs - destructeur
    Particulier(string id, vector<Sensor> liste);
    // Constructeur de la classe Particulier

    virtual ~Particulier();
    // Destructeur de la classe Particulier

//------------------------------------------------------------------ PRIVE 
protected:
//----------------------------------------------------- Attributs protégés
    vector<Sensor> listeSensors;
    int point;
    int banni;
};

//----------------------------------------- Types dépendants de <Particulier>

#endif // DEF_parti
