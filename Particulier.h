#ifndef DEF_particulier
#define DEF_particulier
 
#include <iostream>
#include <string>
#include <vector>
#include "Utilisateur.h"
#include "Sensor.h"

class Particulier : public Utilisateur
{
    public:
    Particulier(string id, vector<Sensor> liste);
    virtual ~Particulier();

    private:
    vector<Capteur> listeCapteurs;
    int point;
    int banni;
};
#endif