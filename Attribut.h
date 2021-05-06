/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 05/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA / MDARHRI / FABREGUES / MARION
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
			   emilien.marion@insa-lyon.fr    thomas.fabregues@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H
//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Rôle de la classe <ATTRIBUT>
//Permet de créer des objets de type Attribut qui donne des informations sur le type
//de mesure correspondant et son unité.
//Elle est capable de créer ces objets en lisant un fichier csv
//
//------------------------------------------------------------------------

class Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );

string getID();
string getUnite();
string getDescription();

//-------------------------------------------- Constructeurs - destructeur
	Attribut(string id, string u, string desc);
	//Constructeur de la classe Attribut

	~Attribut();
	//Destructeur de la classe Attribut

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	string attributID;
	string unite;
	string description;

//-------------------------------- Autres définitions dépendantes de <Attribut>
};

#endif // ATTRIBUT_H



