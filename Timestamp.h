/*************************************************************************
                           Timestamp  -  description
                             -------------------
    début                : 05/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA / MDARHRI / FABREGUES / MARION
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
			   emilien.marion@insa-lyon.fr    thomas.fabregues@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Timestamp> (fichier Timestamp.h) ----------------
#if ! defined ( TIMESTAMP_H )
#define TIMESTAMP_H
//--------------------------------------------------- Interfaces utilisées

#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Rôle de la classe <TIMESTAMP>
//Permet de créer des objets de type Timestamp qui permettent d'avoir une date précise
//
//
//------------------------------------------------------------------------

class Timestamp
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );

int getYear();
int getMonth();
int getDay();
int getHour();
int getMinute();
int getSeconde();

int operator<(Timestamp ts);

int operator>(Timestamp ts);

int operator==(Timestamp ts);

//-------------------------------------------- Constructeurs - destructeur
	Timestamp(int y, int mo, int d, int h, int mi, int s);
	//Constructeur de la classe Timestamp

	~Timestamp();
	//Destructeur de la classe Timestamp

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Timestamps protégés

	int year;
	int month;
	int day;
	int hour;
	int minute;
	int seconde;

//-------------------------------- Autres définitions dépendantes de <Timestamp>
};

#endif // TIMESTAMP_H



