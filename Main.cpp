#include <iostream>
#include <cstring>
#include "Service.h"
using namespace std;

void rappelCommandes();
string obtenirDate(char * strdate);
double obtenirCoord(char * strcoord, int latoulong /** 1 pour latiude et 2 pour longitude*/);
double obtenirRayon(char * strray);
double obtenirNumSensor(char * strnumsensor);
string obtenirIdSensor(double res, char * strnumsensor);


int main()
{
    int taillecom = 20;
    char * command = new char[taillecom];
    char * strlat = new char[taillecom];
    char * strlon = new char[taillecom];
    char * strR = new char[taillecom];
    char * strdate = new char[taillecom];
    char * strnumsensor = new char[taillecom];
    double lat;
    double lon;
    double rayon;
    string date;
    string idSensor;
    double numSensor;
    Service service;


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

            if(lat!=404 && lon!=404 && rayon>=0 && date!="x"){
                pair<string, int> res = service.trouverIndiceAtmo(lat, lon, rayon, date);
                cout << "l'indice ATMO de la journee est " << res.second << " et c'est l'element " << res.first << " qui sature"<< endl;
            }else if (lat==404 || lon==404){
                cout << "Votre saisie comporte des erreurs, veuillez verifier que les coordonnees soient valides" << endl;
            }else if(rayon<=0){
                cout << "Le rayon doit etre superieur a 0!" << endl;
            }else{
                cout << "Le format de date n'est pas respecte ou la date saisie n'existe pas, veuillez verifier svp" << endl;
            }

            
        }else if(!strcmp(command, "2")){
            cout << "Pour vérifier si un capteur est defectueux, veuillez entrer le numéro de ce capteur" << endl;
	    cin.getline(strnumsensor, taillecom);
	    numSensor = obtenirNumSensor(strnumsensor);
	    if(numSensor>0){
		idSensor = obtenirIdSensor(numSensor, strnumsensor); 
		if(idSensor == ""){
			cout << "Le numéro que vous avez entré ne correspond à aucun capteur" << endl; 
            	}else{
			//int def = service.trouverCapteurDef(idSensor);
			int def = 1;
			if(def){
				cout << "Attention ! Ce capteur est defectueux" << endl;
			}else{
				cout << "Ce capteur n'est pas defectueux" <<endl;
			}
		}
            }else{
		cout << "Le format numéro positif n'a pas été respecté" <<endl;
	    }
            
        }else if(!strcmp(command, "help")){
            rappelCommandes();
        }else if(!strcmp(command, "exit")){
            //on sortira de l'application
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
    delete [] strnumsensor;

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

string obtenirDate(char * strdate){
    string s(strdate);
    string syear = s.substr(0, 4);
    string smonth = s.substr(5, 2);
    string sday = s.substr(8, 2);
    string res;
    
    

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
        res = syear+"-"+smonth+"-"+sday;
    }else{
        res = "x";
    }
    
    return res;
}

double obtenirNumSensor(char * strnumsensor){
	string s(strnumsensor);
	double res;
	try{
		res = stof(s);
	}catch(exception & e){
		res = -1;
	}
	return res;
}
string obtenirIdSensor(double res, char * strnumsensor){
	string s(strnumsensor);
	string sensor = "sensor";
	string idSensor;

	if(res>=0 && res<=99){
		idSensor = sensor + s;
	}else{
		idSensor = "";
	}
	return idSensor;
}