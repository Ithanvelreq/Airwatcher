/*************************************************************************
                           Timestamp  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Timestamp> (fichier Timestamp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>

//------------------------------------------------------ Include personnel
#include "Timestamp.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

int Timestamp::getYear(){
	return year;
}
int Timestamp::getMonth(){
	return month;
}
int Timestamp::getDay(){
	return day;
}
int Timestamp::getHour(){
	return hour;
}
int Timestamp::getMinute(){
	return minute;
}
int Timestamp::getSeconde(){
	return seconde;
}




//-------------------------------------------- Constructeurs - destructeur

Timestamp::Timestamp(int y, int mo, int d, int h, int mi, int s)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Timestamp>" << endl;
	#endif
	year = y;
	month = mo;
	day = d;
	hour = h;
	minute = mi;
	seconde = s;
} //----- Fin de Timestamp


Timestamp::~Timestamp()
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Timestamp>" << endl;
	#endif
} //----- Fin de ~Timestamp


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

