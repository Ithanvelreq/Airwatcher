/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : 05/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA / MDARHRI / FABREGUES / MARION
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
			   emilien.marion@insa-lyon.fr    thomas.fabregues@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Purificateur> (fichier Purificateur.h) ----------------
#if ! defined ( PURIFICATEUR_H )
#define PURIFICATEUR_H
//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Rôle de la classe <PURIFICATEUR>
//Permet de créer des objets de type Purificateur qui donne des informations sur 
//sa localisation et sa durée de fonctionnement
//Elle est capable de créer ces objets en lisant un fichier csv
//
//------------------------------------------------------------------------

class Purificateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );

string getPurificateurID();
double getLatitude();
double getLongitude();
string getStart();
string getStop();


//-------------------------------------------- Constructeurs - destructeur
	Purificateur(string id, double la, double lo, string start, string stop);
	//Constructeur de la classe Purificateur

	~Purificateur();
	//Destructeur de la classe Purificateur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Purificateurs protégés

	string purificateurID;
	double latitude;
	double longitude;
	string startTimestamp;
	string stopTimestamp;

//-------------------------------- Autres définitions dépendantes de <Purificateur>
};
#endif // PURIFICATEUR_H



