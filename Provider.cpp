/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 31/05/2021
    copyright            : (C) 2021 par VELARDE REQUENA/MDARHRI/MARION/FABREGUES
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
vector<Purificateur> Provider:: getListe(){
    return listePurifs;
}//----- Fin de getListe()

void Provider:: setListe(vector<Purificateur> liste){
    copy (liste.begin(), liste.end(), listePurifs.begin());
}//----- Fin de setListe()

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider(string id, vector<Purificateur> liste):Utilisateur(id){
{
    #ifdef MAP
        cout << "Appel au constructeur de <Provider>" << endl;
    #endif
    copy (liste.begin(), liste.end(), listePurifs.begin());
} //----- Fin de Provider


Provider:: ~Provider()
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider

