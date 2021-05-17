#include <iostream>
#include <cstring>
#include "Timestamp.h"
using namespace std;

void rappelCommandes();
Timestamp* obtenirDate(char * strdate);
double obtenirCoord(char * strcoord, int latoulong /** 1 pour latiude et 2 pour longitude*/);
double obtenirRayon(char * strray);
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
    Timestamp *date;


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
            cin.getline(strdate, taillecom);
            lat = obtenirCoord(strlat, 1);
            lon = obtenirCoord(strlon, 2);
            rayon = obtenirRayon(strR);
            date = obtenirDate(strdate);

            cout << "lat" << lat << " lon "<<lon<<" R "<< rayon<< " date ";
            //pour l'instant affiche -1 si il y a un probleme lors de la saisie
            if (date!= nullptr){
                date->display();
                delete date; // if not null
            }else{
                cout << "probleme avec la date" << endl;
            }
            
        }else if(!strcmp(command, "1")){
            cout << "vous avez choisi 2" << endl;
        }else if(!strcmp(command, "help")){
            rappelCommandes();
        }else if(!strcmp(command, "exit")){
            //on sortira de l'appli
        }else{
            cout << "La commande saisie ne corresponds pas aux options disponibles, veuillez ressayer svp" << endl;
        }
    }
    cout << "fini" << endl;
    delete [] command;
    delete [] strdate;
    delete [] strlat;
    delete [] strlon;
    delete [] strR;
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

Timestamp* obtenirDate(char * strdate){
    string s(strdate);
    string syear = s.substr(0, 4);
    string smonth = s.substr(5, 2);
    string sday = s.substr(8, 2);
    Timestamp *res;
    

    int year;
    int month;
    int day;

    try{
        year = stof(syear);
        month = stof(smonth);
        day = stof(sday);
    }catch(exception & e){
        year = -1;
        month = -1;
        day = -1;
    }
    
    int doesmonthhave31daysv1 = ((month < 7 && month%2 ==1 && 31<day) || (month < 7 && month%2==0 && 30<day));
    int doesmonthhave31daysv2 = ((month > 6 && month%2 ==0 && 31<day) || (month > 6 && month%2==1 && 30<day));
    int isFeb = (month == 2 && day>28);
    if(1>month || 12< month || 1>day || doesmonthhave31daysv1 || doesmonthhave31daysv2 || isFeb) {
        year = -1;
        month = -1;
        day = -1;
    }

    if(year != -1 && month != -1 && day != -1){
        res = new Timestamp(year, month, day);
    }else{
        res = nullptr;
    }
    
    return res;
}