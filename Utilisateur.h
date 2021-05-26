#ifndef DEF_utilisateur
#define DEF_utilisateur
 
#include <iostream>
#include <string>
 
class Utilisateur
{
    public:
    Utilisateur(string userId);
    virtual ~Utilisateur();

    private:
    string userId;
    string motDePasse;
    string mail;
    string nom;
    string prenom;
};
#endif