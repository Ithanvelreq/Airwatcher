#ifndef DEF_gouv
#define DEF_gouv
 
#include <iostream>
#include <string>
#include "Utilisateur.h"

class Gouvernement : public Utilisateur
{
    public:
    Gouvernement(string id);
    virtual ~Gouvernement();

    private:
   
};
#endif