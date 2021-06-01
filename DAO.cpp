/*************************************************************************
                           DAO  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <DAO> (fichier DAO.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DAO.h"
#include "vector"
#define PI 3.141592
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
vector<Sensor> DAO::selectionnerCapteur(double latitude,double longitude,double rayon){
    //récupère l'id des sensors qui nous intéresse qui sont dans le rayon demande
    ifstream capteur ("../dataset/sensors.csv");  //Ouverture d'un fichier en lecture
    vector<Sensor> listecapteur;
    if(capteur) {
        //Tout est prêt pour la lecture.
        string ligne;
        while (getline(capteur, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            //On lit une ligne complète
            string::iterator it = ligne.begin();
            string sensorID;
            double lat;
            double longi;
            while (*it != ';') {
                sensorID.insert(sensorID.end(), *it);
                it++;
            }
            it++;
            string lat1;
            while (*it != ';') {

                lat1.insert(lat1.end(), *it);
                it++;
            }
            it++;
            string lon1;
            while (*it != ';') {

                lon1.insert(lon1.end(), *it);
                it++;
            }

            lat = atof(lat1.c_str());
            longi = atof(lon1.c_str());
            Sensor sensor(sensorID, lat, longi);

            if(distanceEntre2points(lat,longi,latitude,longitude)<rayon){
                listecapteur.push_back(sensor);
            }
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return  listecapteur;
}//Fin de la methode


//remplacer date par Time stamp?
//vector<string> listecapteurs ,string date
//vector<Mesure> obtenirBonneMesure(){
vector<Mesure> DAO::obtenirBonneMesure(string dateAtt,vector<Sensor> capteurs){
    ifstream mesurecsv("../dataset/measurements.csv");
    string ligne;
    vector<Mesure> mesures;
    if(mesurecsv){
        while (getline(mesurecsv, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            string date;
            string sensorID;
            string attributeID;
            string value1;
            double value;

            string::iterator it = ligne.begin();
            for(int i=0;i<10;i++) {
                date.insert(date.end(), *it);
                it++;
            }

            if(date!=dateAtt){
                continue;
            }

            while(*it!='S'){
               it++;
            }
            while (*it != ';') {
                sensorID.insert(sensorID.end(), *it);
                it++;
            }
            int test=0;

            for(int i(0); i<capteurs.size(); ++i) {
                if(sensorID==capteurs[i].getSensorID()){
                    test++;
                }
            }
            if(test==0){
                continue;
            }


            it++;
            while (*it != ';') {
                attributeID.insert(attributeID.end(), *it);
                it++;
            }
            it++;
            while (*it != ';') {
                value1.insert(value1.end(), *it);
                it++;
            }

           value= atof(value1.c_str());
            Attribut attribut = chercherAttributParId(attributeID);
            Mesure mesure(date, sensorID, value, attribut);
            mesures.push_back(mesure);
        }


    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

    }



    return mesures;
}//Fin de la methode

//Chercher un attribut à partir de son ID
Attribut DAO::chercherAttributParId(string AttributeID){
	ifstream attributCSV("../dataset/attributes.csv");
	string ligne;
	Attribut attribut;
	if(attributCSV){
		while(getline(attributCSV, ligne)){
			string::iterator it = ligne.begin();
			string attID;
			while (*it != ';') {
				attID.insert(attID.end(), *it);
		        	it++;
		    	}
			it++;
			if(attID!=AttributeID){
		        	continue;
		    	}
			string unit;
			while (*it != ';') {
				unit.insert(unit.end(), *it);
		        	it++;
		    	}
			it++;
			string description;
			while (*it != ';') {
				description.insert(description.end(), *it);
		        	it++;
		    	}
			attribut.setID(attID);
			attribut.setUnite(unit);
			attribut.setDescription(description);
		}
	}else{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	return attribut;
}

Sensor DAO::trouverCapteurParId(string idCapteur){
    ifstream capteur ("../dataset/sensors.csv");  //Ouverture d'un fichier en lecture
    Sensor sensor;
    if(capteur) {
        //Tout est prêt pour la lecture.
        string ligne;
        while (getline(capteur, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            //On lit une ligne complète
            string::iterator it = ligne.begin();
            string sensorID;
            double lat;
            double longi;
            while (*it != ';') {
                sensorID.insert(sensorID.end(), *it);
                it++;
            }
            if(sensorID != idCapteur){
                continue;
            }
            it++;
            string lat1;
            while (*it != ';') {

                lat1.insert(lat1.end(), *it);
                it++;
            }
            it++;
            string lon1;
            while (*it != ';') {

                lon1.insert(lon1.end(), *it);
                it++;
            }

            lat = atof(lat1.c_str());
            longi = atof(lon1.c_str());

            sensor.setID(sensorID);
	        sensor.setLatitude(lat);
	        sensor.setLongitude(longi);
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
	return sensor;
}//Fin de la methode

//Retourne la liste de tous les particuliers
vector<Particulier> DAO::obtenirParticuliers(){
	vector<Particulier> particuliers;
	ifstream usersCSV("../dataset/users.csv");
	string ligne;
	if(usersCSV){
		while(getline(usersCSV, ligne)){
			string userID;
			string sensorID;
			string::iterator it = ligne.begin();
			while(*it != ';'){
				userID.insert(userID.end(), *it);
				it++;
			}
			it++;			
			while (*it != ';'){
				sensorID.insert(sensorID.end(), *it);
				it++;
			}
			int exist =0;
			for(int i=0; i<particuliers.size(); i++){
				if(userID == particuliers[i].getID() ){
					Sensor sensor = trouverCapteurParId(sensorID); 
					particuliers[i].addSensor(sensor);
					exist=1;
					break;
				}
			}
			if(!exist){
				Sensor sensor = trouverCapteurParId(sensorID); 
				vector<Sensor> capteurs;
				capteurs.push_back(sensor);
				Particulier particulier(userID, capteurs);
				particuliers.push_back(particulier);
			}
		}
	}else{
		cout<<	 "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	return particuliers;		
}//Fin de la methode

//------------------------------------------------- Surcharge d'op�rateurs
//-------------------------------------------- Constructeurs - destructeur
DAO::DAO ( const DAO & unDAO )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DAO>" << endl;
#endif
} //----- Fin de DAO (constructeur de copie)


DAO::DAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DAO>" << endl;
#endif
} //----- Fin de DAO


DAO::~DAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DAO>" << endl;
#endif
} //----- Fin de ~DAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es

//Conversion des degrés en radian
double DAO::convertRad(double input){
    return (PI * input)/180;
}


double DAO::distanceEntre2points(double lat_a_degre, double lon_a_degre, double lat_b_degre,double lon_b_degre){

    double Latitude1 = convertRad(lat_a_degre);
    double Longitude1 = convertRad(lon_a_degre);
    double Latitude2 = convertRad(lat_b_degre);
    double Longitude2= convertRad(lon_b_degre);

    double d=6371;
    double k=sin(Latitude1)*sin(Latitude2)+cos(Latitude1)*cos(Latitude2)*cos(Longitude2-Longitude1);
    double h=d* acos(k);

    return h;
}




