/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Purificateur> (fichier Purificateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>

//------------------------------------------------------ Include personnel
#include "Purificateur.h"
#include "Timestamp.h"
using namespace std;
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string Purificateur::getPurificateurID(){
	return purificateurID;
}
double Purificateur::getLatitude(){
	return latitude;
}
double Purificateur::getLongitude(){
	return longitude;
}
Timestamp * Purificateur::getStart(){
	return startTimestamp;
}
Timestamp * Purificateur::getStop(){
	return stopTimestamp;
}


//-------------------------------------------- Constructeurs - destructeur

Purificateur::Purificateur(string id, double la, double lo, Timestamp * start, Timestamp * stop)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Purificateur>" << endl;
	#endif
	purificateurID = id;
	latitude = la;
	longitude = lo;
	startTimestamp = start;
	stopTimestamp = stop;
} //----- Fin de Purificateur


Purificateur::~Purificateur()
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Purificateur>" << endl;
	#endif
} //----- Fin de ~Purificateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

