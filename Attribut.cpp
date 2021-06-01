/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string Attribut::getID() {
	return attributID;
}

string Attribut::getUnite(){
	return unite;
}

string Attribut::getDescription(){
	return description;
}

void Attribut::setID(string id){
	attributID = id;
}
void Attribut::setUnite(string unit){
	unite = unit;
}
void Attribut::setDescription(string desc){
	description = desc;
}

//-------------------------------------------- Constructeurs - destructeur

Attribut::Attribut(string id, string u, string desc)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Attribut>" << endl;
	#endif
	attributID = id;
	unite = u;
	description = desc;
} //----- Fin de Attribut

Attribut::Attribut(const Attribut & attribut){
	attributID = attribut.attributID;
	unite = attribut.unite;
	description = attribut.description;
}//------ Fin de Attribut par copie

Attribut::Attribut(){

}//------ Fin de Attribut par defaut

Attribut::~Attribut()
{	
	#ifdef MAP
		cout << "Appel au destructeur de <Attribut>" << endl;
	#endif
} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

