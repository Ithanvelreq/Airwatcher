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
            cout<<"pas de capteurs dans la zone choisie"<<endl;
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
void Service::calculerIndiceAtmo(vector<Mesure> mesures){
    // Algorithme :
    //
    if(mesures.empty()){
        cout<< "pas de mesure valide dans la zone choisie"<<endl;
    }

    double sommeO3=0;
    double sommeNO2=0;
    double sommeSO2=0;
    double sommePm10=0;
    int nbO3=0;
    int nbNO2=0;
    int nbSO2=0;
    int nbPM0=0;

	string unite1;
	string unite2;
	string unite3;
	string unite4;

    for(int i(0);i<mesures.size();i++){
        if(mesures[i].getAttribut().getID()=="O3"){
            sommeO3=sommeO3 + mesures[i].getValue();
            nbO3++;
		unite1 = mesures[i].getAttribut().getUnite();
        }else if(mesures[i].getAttribut().getID()=="NO2"){
            sommeNO2=sommeNO2+mesures[i].getValue();
            nbNO2++;
		unite2 = mesures[i].getAttribut().getUnite();
        }else if(mesures[i].getAttribut().getID()=="SO2"){
            sommeSO2=sommeSO2+mesures[i].getValue();
            nbSO2++;
		unite3 = mesures[i].getAttribut().getUnite();
        }else if (mesures[i].getAttribut().getID()=="PM10"){
            sommePm10=sommePm10+mesures[i].getValue();
            nbPM0++;
		unite4 = mesures[i].getAttribut().getUnite();
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

	string temp1;
	string temp2;

    double maxi1=max(moyenneNo2,moyenneO3);
	if(maxi1 == moyenneO3)
		temp1 = unite1;
	else
		temp1 = unite2;
    double maxi2=max(moyenneSO2,moyennePM10);
	if(maxi2 == moyenneSO2)
		temp2 = unite3;
	else
		temp2 = unite4;

	string uniteFinale;
    double maxi=max(maxi1,maxi2);
	if(maxi == maxi1)
		uniteFinale = temp1;
	else
		uniteFinale = temp2;

    cout<<"l'indice ATMO est "<<maxi<<" "<<uniteFinale<<endl;


}//----- Fin de M�thode