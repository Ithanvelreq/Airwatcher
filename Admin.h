#ifndef DEF_admin
#define DEF_admin
 
#include <iostream>
#include <string>
#include "Utilisateur.h"
 
class Admin : public Utilisateur
{
    public:
    Admin(string id);
    virtual ~Admin();

    private:
   
};
#endif