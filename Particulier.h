#ifndef DEF_particulier
#define DEF_particulier
 
#include <iostream>
#include <string>
#include <vector>
#include "Utilisateur.h"

struct Capteur
{
    string capteurId;
};

class Particulier : public Utilisateur
{
    public:
    Particulier(string id, vector<Capteur> liste);
    virtual ~Particulier();

    private:
    vector<Capteur> listeCapteurs;
    int point;
    int banni;
};
#endif