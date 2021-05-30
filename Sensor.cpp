/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>

//------------------------------------------------------ Include personnel
#include "Sensor.h"
using namespace std;
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string Sensor::getSensorID(){
	return sensorID;
}
double Sensor::getLatitude(){
	return latitude;
}
double Sensor::getLongitude(){
	return longitude;
}
void Sensor::setID(string id){
	sensorID = id;
}
void Sensor::setLatitude(double la){
	latitude = la;
}
void Sensor::setLongitude(double lo){
	longitude = lo;
}
//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor(string id, double la, double lo)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Sensor>" << endl;
	#endif
	sensorID = id;
	latitude = la;
	longitude = lo;
} //----- Fin de Sensor

Sensor::Sensor(){
	
}

Sensor::~Sensor()
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Sensor>" << endl;
	#endif
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

