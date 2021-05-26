#ifndef DEF_prov
#define DEF_prov
 
#include <iostream>
#include <string>
#include <vector>
#include "Utilisateur.h"

struct Cleaner
{
    string cleanerId;
};
 
class Provider : public Utilisateur
{
    public:
    Provider(string id, vector<Cleaner> liste);
    ~Provider();

    private:
    vector<Cleaner> listeCleaners;

   
};
#endif