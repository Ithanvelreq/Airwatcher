/*************************************************************************
                           DAO  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <DAO> (fichier ${file_name}) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilis�es
#include "Mesure.h"
#include "Sensor.h"
#include "Attribut.h"
#include "Particulier.h"
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include "vector"
#include "map"
#include "Mesure.h"
#include "Sensor.h"
#include <algorithm>
using namespace std;
//------------------------------------------------------------- Constantes
#define PI 3.141592
#define DATASETSENSORS "../dataset/sensors.csv"
#define DATASETMESURES "../dataset/measurements.csv"
#define DATASETATTRIBUTES "../dataset/attributes.csv"
#define DATASETUSERS "../dataset/users.csv"
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <DAO>
//
//
//------------------------------------------------------------------------ 

class DAO
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    vector<Sensor> selectionnerCapteur(double latitude,double longitude,double rayon);
    vector<Mesure> obtenirBonneMesure(string dateAtt,vector<Sensor> capteurs);
    Sensor trouverCapteurParId(string id);
    Attribut chercherAttributParId(string attributeID);
    vector<Particulier> obtenirParticuliers();
    
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    DAO & operator = ( const DAO & unDAO );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DAO ( const DAO & unDAO );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es
    double convertRad(double input);
    double  distanceEntre2points(double lat_a_degre, double lon_a_degre, double lat_b_degre,double lon_b_degre);

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <DAO>

#endif // XXX_H
