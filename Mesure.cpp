/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Mesure.h"
#include "Timestamp.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Timestamp * Mesure::getDate(){
	return date;
}
string Mesure::getSensorID(){
	return sensorID;
}
string Mesure::getAttributeID(){
	return attributeID;
}
double Mesure::getValue(){
	return value;
}

//-------------------------------------------- Constructeurs - destructeur

Mesure::Mesure( Timestamp * d, string capteur, string attribut, double valeur)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Mesure>" << endl;
	#endif
	date = d;
	sensorID = capteur;
	attributeID = attribut;
	value = valeur;
} //----- Fin de Mesure


Mesure::~Mesure()
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Mesure>" << endl;
	#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

