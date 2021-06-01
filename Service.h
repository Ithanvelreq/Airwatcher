/*************************************************************************
                           Service  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Service> (fichier ${file_name}) ------
#if ! defined ( SERVICE_H )
#define SERVICE_H

//--------------------------------------------------- Interfaces utilis�es
#include "DAO.h"
#include "Sensor.h"
#include "Mesure.h"
#include "Particulier.h"
#include <time.h>
//------------------------------------------------------------- Constantes 
#define SEUIL 300
//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Service>
//
//
//------------------------------------------------------------------------ 

class Service
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    pair<string, int> trouverIndiceAtmo(double latitude, double longitude, double rayon, string date);
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int trouverCapteurDef(string id);
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur
    Service ( const Service & unService );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Service ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Service ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es
map<string, double> calculerMoyenneParElement(vector<Mesure> mesures);
void recompenserParticuliers(vector<Particulier> & particuliers, vector<Mesure> mesures);
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
pair<string, int> indiceDeLaJournee(map<string, double> moyennes);

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Service>

#endif // SERVICE_H
