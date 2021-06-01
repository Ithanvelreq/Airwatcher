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
pair<string, int> Service::trouverIndiceAtmo(double latitude, double longitude, double rayon, string date){
    DAO dao;
    vector<Sensor> capteurs = dao.selectionnerCapteur(latitude, longitude, rayon);
    vector<Mesure> mesures = dao.obtenirBonneMesure(date, capteurs);
    map<string, double> moyennes = calculerMoyenneParElement(mesures);

    /*Récompenser les particuliers*/
	vector<Particulier> particuliers = dao.obtenirParticuliers();
	recompenserParticuliers(particuliers, mesures);

    pair<string, int> indice = indiceDeLaJournee(moyennes);
    
    return indice;
}

int Service::trouverCapteurDef(string id)
{
    DAO dao;
    int res = 0;
    Sensor evaluatedSensor = dao.trouverCapteurParId(id);
    vector<Sensor> vectorSensor;
    vectorSensor.push_back(evaluatedSensor);

    //On trouve les voisins du capteur
    double rayon = 10.0;
    vector<Sensor> listeneighs;
    while(listeneighs.size() < 5){
        listeneighs = dao.selectionnerCapteur(evaluatedSensor.getLatitude(), evaluatedSensor.getLongitude(), rayon);
        rayon += 10.0;
    }
    
    string lastdate = "2019-12-";
    int lastday = 31;
    string currentDate = lastdate + to_string(lastday);
    double ecartalamoyenne = 0;

    //On calcule l'ecart a la moyenne pendant les derniers 7 jours
    while(lastday > 24){
        vector<Mesure> mesuresVoisins = dao.obtenirBonneMesure(currentDate, listeneighs);

        /*Récompenser les particuliers*/
        vector<Particulier> particuliers = dao.obtenirParticuliers();
        recompenserParticuliers(particuliers, mesuresVoisins);

        map<string, double> moyennesMesuresVoisins = calculerMoyenneParElement(mesuresVoisins);
        vector<Mesure> mesuresCapteurTeste = dao.obtenirBonneMesure(currentDate, vectorSensor);

        vector<Mesure>::iterator it;
        for(it = mesuresCapteurTeste.begin(); it<mesuresCapteurTeste.end(); it++){
            if(it->getAttribut().getID()=="O3"){
                ecartalamoyenne += abs(it->getValue() - moyennesMesuresVoisins.find("O3")->second);
            }else if(it->getAttribut().getID()=="NO2"){
                ecartalamoyenne += abs(it->getValue() - moyennesMesuresVoisins.find("NO2")->second);

            }else if(it->getAttribut().getID()=="SO2"){
                ecartalamoyenne += abs(it->getValue() - moyennesMesuresVoisins.find("SO2")->second);

            }else if (it->getAttribut().getID()=="PM10"){
                ecartalamoyenne += abs(it->getValue() - moyennesMesuresVoisins.find("PM10")->second);
            }
        }
        lastday--;
    }
    //C'est le capteur 36 qui ne marche pas
    if(ecartalamoyenne>SEUIL){
        res = 1;
    }

    return res;
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
    res.insert(pair<string, double>("O3", moyenneO3));
    res.insert(pair<string, double>("NO2", moyenneNo2));
    res.insert(pair<string, double>("SO2", moyenneSO2));
    res.insert(pair<string, double>("PM10", moyennePM10));
    return res;


}//----- Fin de M�thode

void Service::recompenserParticuliers(vector<Particulier> particuliers, vector<Mesure> mesures){
	for(int i=0; i<mesures.size(); i++){
		for(int j=0; j<particuliers.size(); j++){
			for(int k=0; k<particuliers[j].getListe().size(); k++){
				if(particuliers[j].getListe()[k].getSensorID() == mesures[i].getSensorID() ){
					particuliers[j].setPoint(particuliers[j].getPoint()+1);
					cout << "Le particulier "<<particuliers[j].getId()<<" se voit attribuer un point en plus, pour un total de "<<particuliers[j].getPoint()/*particuliers[j].points*/<<endl;
				}
			}
		}
	}

}
pair<string, int> Service::indiceDeLaJournee(map<string, double> moyennes)
{
    vector<double> listeIndicePourPM10{0, 10, 20, 30, 40, 50, 65, 80, 100, 125};
    vector<double> listeIndicePourSO2{0, 40, 80, 120, 160, 200, 250, 300, 400, 500};
    vector<double> listeIndicePourNO2{0, 30, 55, 85, 110, 135, 165, 200, 275, 400};
    vector<double> listeIndicePourO3{0, 30, 55, 80, 105, 130, 150, 180, 210, 240};

    map<string, vector<double>> listeIndices;
    listeIndices.insert(pair<string, vector<double>>("NO2", listeIndicePourNO2));
    listeIndices.insert(pair<string, vector<double>>("SO2", listeIndicePourSO2));
    listeIndices.insert(pair<string, vector<double>>("PM10", listeIndicePourPM10));
    listeIndices.insert(pair<string, vector<double>>("O3", listeIndicePourO3));

    map<string, double>::iterator it;
    int indiceCourrant = 1;
    int indiceFinal = 1;
    string elementfinal;
    int fini = 0;
    for(it = moyennes.begin(); it!=moyennes.end(); it++){
        while(!fini){
            if(it->second >= listeIndices.find(it->first)->second.back()){
                //saturation
                fini = 1;
            }else if(it->second>=listeIndices.find(it->first)->second[indiceCourrant-1] && it->second<=listeIndices.find(it->first)->second[indiceCourrant]){
                //on a trouve l'encadrement
                fini = 1;
            }

            if(fini && indiceCourrant>indiceFinal){
                indiceFinal = indiceCourrant;
                elementfinal = it->first;
            }
            indiceCourrant++;
        }
        fini = 0;
        indiceCourrant = 1;
    }
    return pair<string, int>(elementfinal, indiceFinal);
}//----- Fin de M�thode
