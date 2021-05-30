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
#include <cstdlib>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
<<<<<<< Updated upstream
    void Service::trouverIndiceAtmo(double latitude, double longitude, double rayon, string date){
        DAO dao;
        vector<Sensor> capteurs = dao.selectionnerCapteur(latitude, longitude, rayon);
        if(capteurs.empty()){
            cout<<"pas de capteurs dans la zone choisie"<<endl;
        }
        vector<Mesure> mesures = dao.obtenirBonneMesure(date, capteurs);
        return calculerIndiceAtmo(mesures);
=======
double Service::trouverIndiceAtmo(double latitude, double longitude, double rayon, string date){
    DAO dao;
    vector<string> capteurs = dao.selectionnerCapteur(latitude, longitude, rayon);
    vector<Mesure> mesures = dao.obtenirBonneMesure(date, capteurs);
    map<string, double> moyennes = calculerMoyenneParElement(mesures);

    double maxi1=max(moyennes.find("O3")->second, moyennes.find("No2")->second);
    double maxi2=max(moyennes.find("SO2")->second,moyennes.find("PM10")->second);
    double maxi=max(maxi1,maxi2);
    return maxi;
}

int trouverCapteurDef(string id)
{
    DAO dao;
    Sensor evaluatedSensor = dao.trouverSensorParId(id);
    vector<Sensor> vectorSensor;
    vectorSensor.push_back(evaluatedSensor);
    double rayon = 10.0;
    vector<Sensor> listeneighs;
    while(listeneighs.size() < 5){
        listeneighs = dao.selectionnerCapteur(evaluatedSensor.getLatitude(), evaluatedSensor.getLongitude(), rayon);
        rayon += 10.0;
    }
    
    string lastdate = "-31-2019";
    int lastday = 12;
    string currentDate = to_string(lastday) + lastdate;
    double ecartalamoyenne;
    while(lastday < 20){
        vector<pair<double, string>> moyennesMesuresVoisins = calculerMoyenneParElement(dao.obtenirBonneMesure(currentDate, listeneighs));
        vector<Mesure> mesuresCapteur = dao.obtenirBonneMesure(currentDate, vectorSensor);
        vector<Mesure>::iterator it;

        for(it = mesuresCapteur.begin(); it<mesuresCapteur.end(); it++){

            if(it->getAttributeID()=="O3"){
                ecartalamoyenne = abs(it->getValue() - moyennesMesuresVoisins.find("O3")->second);

            }else if(it->getAttributeID()=="NO2"){
                sommeNO2=sommeNO2+mesures[i].getValue();
                nbNO2++;

            }else if(it->getAttributeID()=="SO2"){
                sommeSO2=sommeSO2+mesures[i].getValue();
                nbSO2++;

            }else if (it->getAttributeID()=="PM10"){
                sommePm10=sommePm10+mesures[i].getValue();
                nbPM0++;

            }
        }
>>>>>>> Stashed changes
    }

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
map<string, double> Service::calculerMoyenneParElement(vector<Mesure> mesures){
    // Algorithme :
    //

    map<string, double> res;
    double sommeO3=0;
    double sommeNO2=0;
    double sommeSO2=0;
    double sommePm10=0;
    int nbO3=0;
    int nbNO2=0;
    int nbSO2=0;
    int nbPM0=0;

    if(mesures.empty()){
        return res;
    }

    for(int i=0;i<mesures.size();i++){
        if(mesures[i].getAttribut().getID()=="O3"){
            sommeO3=sommeO3 + mesures[i].getValue();
            nbO3++;
        }else if(mesures[i].getAttribut().getID()=="NO2"){
            sommeNO2=sommeNO2+mesures[i].getValue();
            nbNO2++;
        }else if(mesures[i].getAttribut().getID()=="SO2"){
            sommeSO2=sommeSO2+mesures[i].getValue();
            nbSO2++;
        }else if (mesures[i].getAttribut().getID()=="PM10"){
            sommePm10=sommePm10+mesures[i].getValue();
            nbPM0++;
        }

    }

    double moyenneO3=sommeO3/nbO3;
    double moyenneNo2=sommeNO2/nbNO2;
    double moyenneSO2=sommeSO2/nbSO2;
    double moyennePM10=sommePm10/nbPM0;
    map<string, double> res;
    res.insert(pair<string, double>("O3", moyenneO3));
    res.insert(pair<string, double>("No2", moyenneNo2));
    res.insert(pair<string, double>("SO2", moyenneSO2));
    res.insert(pair<string, double>("PM10", moyennePM10));
    return res;


}//----- Fin de M�thode