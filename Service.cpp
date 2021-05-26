/*************************************************************************
                           Service  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Service> (fichier Service.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Service.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
    string Service::trouverIndiceAtmo(double latitude, double longitude, double rayon, string date){
        DAO dao;
        vector<Sensor> capteurs = dao.selectionnerCapteur(latitude, longitude, rayon);
        if(capteurs.empty()){
            return "pas de capteurs dans la zone choisie";
        }
        vector<Mesure> mesures = dao.obtenirBonneMesure(date, capteurs);
        return calculerIndiceAtmo(mesures);
    }

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
Service::Service ( const Service & unService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de Service (constructeur de copie)


Service::Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
} //----- Fin de Service


Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
string  Service::calculerIndiceAtmo(vector<Mesure> mesures){
    // Algorithme :
    //
    if(mesures.empty()){
        return "pas de mesure valide dans la zone choisie";
    }

    double sommeO3=0;
    double sommeNO2=0;
    double sommeSO2=0;
    double sommePm10=0;
    int nbO3=0;
    int nbNO2=0;
    int nbSO2=0;
    int nbPM0=0;


    for(int i(0);i<mesures.size();i++){
        if(mesures[i].getAttributeID()=="O3"){
            sommeO3=sommeO3 + mesures[i].getValue();
            nbO3++;

        }else if(mesures[i].getAttributeID()=="NO2"){
            sommeNO2=sommeNO2+mesures[i].getValue();
            nbNO2++;

        }else if(mesures[i].getAttributeID()=="SO2"){
            sommeSO2=sommeSO2+mesures[i].getValue();
            nbSO2++;

        }else if (mesures[i].getAttributeID()=="PM10"){
            sommePm10=sommePm10+mesures[i].getValue();
            nbPM0++;

        }

    }
    double moyenneO3=sommeO3/nbO3;
    double moyenneNo2=sommeNO2/nbNO2;
    double moyenneSO2=sommeSO2/nbSO2;
    double moyennePM10=sommePm10/nbPM0;

    cout<<"moyenneO3:" <<moyenneO3<<endl;
    cout<<"moyenneSO2:" <<moyenneSO2<<endl;
    cout<<"moyennePM10:" <<moyennePM10<<endl;
    cout<<"moyenneNO2:" <<moyenneNo2<<endl;

    double maxi1=max(moyenneNo2,moyenneO3);
    double maxi2=max(moyenneSO2,moyennePM10);
    double maxi=max(maxi1,maxi2);
    cout<<"le maxi est "<<maxi<<endl;
    return maxi;


}//----- Fin de M�thode