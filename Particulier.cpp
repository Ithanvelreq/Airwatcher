/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Particulier.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
vector<Sensor> Particulier:: getListe(){
    return listeSensors;
}//----- Fin de getListe()

void Particulier:: setListe(vector<Sensor> liste){
    listeSensors = liste;
}//----- Fin de setListe()

int Particulier:: getPoint(){
    return point;
}

void Particulier:: setPoint(int p){
    point = p;
}

int Particulier:: getBanni(){
    return banni;
}

void Particulier:: setBanni(int b){
    banni = b;
}

//-------------------------------------------- Constructeurs - destructeur
Particulier::Particulier(string id, vector<Sensor> liste):Utilisateur(id)
{
    cout << "constructeur particulier"<<endl;
    #ifdef MAP
        cout << "Appel au constructeur de <Particulier>" << endl;
    #endif
    listeSensors = liste;
    point = 0;
    banni = 0;
} //----- Fin de Particulier


Particulier:: ~Particulier()
{
#ifdef MAP
    cout << "Appel au destructeur de <Particulier>" << endl;
#endif
} //----- Fin de ~Particulier

