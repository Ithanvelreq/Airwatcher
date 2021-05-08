#include <iostream>
#include <cmath>
#include <fstream>
#include "vector"
#include <string>
#include <algorithm>
#define PI 3.141592
using namespace std;


//Conversion des degrés en radian
double convertRad(double input){
    return (PI * input)/180;
}


double  distanceEntre2points(double lat_a_degre, double lon_a_degre, double lat_b_degre,double lon_b_degre){

    double Latitude1 = convertRad(lat_a_degre);
    double Longitude1 = convertRad(lon_a_degre);
    double Latitude2 = convertRad(lat_b_degre);
    double Longitude2= convertRad(lon_b_degre);

    double d=6371;
    double k=sin(Latitude1)*sin(Latitude2)+cos(Latitude1)*cos(Latitude2)*cos(Longitude2-Longitude1);
            double h=d* acos(k);

return h;
}



struct Mesure{
    string date;
    string sensorID;
    string attributeID;
    double value;

};

vector<string> selctionnerCapteur(double latitude,double longitude,double rayon){
//récupère l'id des sensors qui nous intéresse qui sont dans le rayon demande
    ifstream capteur ("/Users/emilienmarion/Desktop/3IF/S2/GL/dataset/sensors.csv");  //Ouverture d'un fichier en lecture
    vector<string> listecapteur;
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

            if(distanceEntre2points(lat,longi,latitude,longitude)<rayon){
                listecapteur.push_back(sensorID);
            }
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return  listecapteur;
}

//remplacer date par Time stamp
//vector<string> listecapteurs ,string date
//vector<Mesure> obtenirBonneMesure(){
vector<Mesure> obtenirBonneMesure(string dateAtt,vector<string> capteurs){


    ifstream mesurecsv("/Users/emilienmarion/Desktop/3IF/S2/GL/dataset/measurements.csv");
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
                if(sensorID==capteurs[i]){
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
            Mesure mesure;
            mesure.sensorID=sensorID;
            mesure.date=date;
            mesure.attributeID=attributeID;
            mesure.value=value;
            mesures.push_back(mesure);



        }


    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

    }



    return mesures;



}
