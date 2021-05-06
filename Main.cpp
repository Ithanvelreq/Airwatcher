#include <iostream>
#include <cstring>
using namespace std;

void rappelCommandes();
typedef struct timestamp{


}timestamp;

int main()
{
    int taillecom = 20;
    char * command = new char[taillecom];
    char * strlat = new char[taillecom];
    char * strlon = new char[taillecom];
    char * strR = new char[taillecom];
    char * strdate = new char[taillecom];
    double lat;
    double lon;
    double rayon;


    cout << "Bienvenu dans l'application Airwathcher"<< endl << "Auteurs: Mdarhri Marion Fabregues Velarde" << endl;
    cout << "Veuillez rentrer votre nom d'utilisateur svp" << endl;
    cin.getline(command, taillecom);
    cout << "Bienvenu " << command << endl;
    rappelCommandes();
    while(strcmp(command, "exit")!=0){
        cout << "Saisisez le numero qui correspond a votre demande svp" << endl;
        cin.getline(command, taillecom);
        if(!strcmp(command, "1")){
            cout << "Veuillez saisir un point avec sa latitude et sa longitude suivi du rayon (en m) de la zone geographique" << endl;
            cout << "ensuite le jour pour lequel vous voulez connaire la mesure. Respectez le format suivant"<< endl;
            cout << "Latitude Longitude Rayon date au format YYYY-MM-DD" << endl;

            cin.getline(strlat, taillecom, ' ');
            cin.getline(strlon, taillecom, ' ');
            cin.getline(strR, taillecom, ' ');
            cin.getline(strdatedebut, taillecom, ' ');
            cin.getline(strdatefin, taillecom);
            lat = obtenirCoord(strlat, 1);
            lon = obtenirCoord(strlon, 2);
            rayon = obtenirRayon(strR);
            // Il faut faire la meme chose pour les dates

            cout << "lat" << lat << " lon "<<lon<<" R "<< R<< " datedebut "<<datedebut<<" datefin " << datefin<<endl;


        }else if(!strcmp(command, "1")){
            cout << "vous avez choisi 2" << endl;
        }else if(!strcmp(command, "help")){
            rappelCommandes();
        }else{
            cout << "La commande saisie ne corresponds pas aux options disponibles, veuillez ressayer svp" << endl;
        }
    }
    cout << "fini" << endl;
    delete [] command;
    return 0;
}

void rappelCommandes(){
    cout << "Nous vous proposons deux fonctionnalites principales: le calcul de l'indice ATMO (1) et trouver le capteur defectueux (2)"<< endl;
    cout << "Vous pouvez quiter en tout moment l'application en rentrant la commande exit" << endl;
    cout << "Pour rafficher ces instructions tappez help" << endl;
}

double obtenirCoord(char * strcoord, int latoulong /** 1 pour latiude et 2 pour longitude*/){
    string s(strcoord);
    double coord;
    try{
        coord = stof(s);
    }catch(exception & e){
        coord = 404.0;
    }
    //On teste dans le cas d'une latitude
    if(latoulong == 1 && (-90>coord || coord>90)){
        coord = 404.0;
    //On teste dans le cas d'une longitude
    }else if(latoulong == 2 && (-180>coord || coord>180)){
        coord = 404.0;
    }

    return coord;
}

double obtenirRayon(char * strray){
    string s(strray);
    double res;
    try{
        res = stof(s);
    }catch(exception & e){
        res = -1;
    }
    return res;
}
