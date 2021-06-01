/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 05/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA / MDARHRI / FABREGUES / MARION
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
			   emilien.marion@insa-lyon.fr    thomas.fabregues@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H
//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Rôle de la classe <SENSOR>
//Permet de créer des objets de type Sensor qui donne des informations sur
//le capteur et sa localisation
//Elle est capable de créer ces objets en lisant un fichier csv
//
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );

string getSensorID();
double getLatitude();
double getLongitude();
void setID(string id);
void setLatitude(double la);
void setLongitude(double lo);

//-------------------------------------------- Constructeurs - destructeur
	Sensor(string id, double la, double lo);
	//Constructeur de la classe Sensor

	Sensor();
	//Constructeur par defaut

	~Sensor();
	//Destructeur de la classe Sensor

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Sensors protégés

	string sensorID;
	double latitude;
	double longitude;

//-------------------------------- Autres définitions dépendantes de <Sensor>
};
#endif // SENSOR_H



