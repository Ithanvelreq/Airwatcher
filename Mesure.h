/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 05/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA / MDARHRI / FABREGUES / MARION
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
			   emilien.marion@insa-lyon.fr    thomas.fabregues@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Rôle de la classe <MESURE>
//Permet de créer des objets de type Mesure qui donne des informations sur 
//le type de mesure, sa valeur et la date de réalistion de cette mesure.
//Elle est capable de créer ces objets en lisant un fichier csv
//
//------------------------------------------------------------------------

class Mesure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );

string getDate();
string getSensorID();
string getAttributeID();
double getValue();

//-------------------------------------------- Constructeurs - destructeur
	Mesure(string d, string capteur, string attribut, double valeur);
	//Constructeur de la classe Mesure

	~Mesure();
	//Destructeur de la classe Mesure

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Mesures protégés

	string date;
	string sensorID;
	string attributeID;
	double value;

//-------------------------------- Autres définitions dépendantes de <Mesure>

};

#endif // MESURE_H

