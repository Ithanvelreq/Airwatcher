#include <iostream>
#include <cstring>
#include "Service.h"
using namespace std;

Service service;

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();


int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}

void test1(){
    cout<< "Execution du test1" << endl;
    cout<< "On evalue l'indice atmo dans le point 46, 1 pour un rayon de 50 le jour 2019-07-11" << endl;
    cout << "Nous attendons les valeurs PM10 et 7"<< endl << endl << endl;
    pair<string, int> res = service.trouverIndiceAtmo(46, 1, 50, "2019-07-11");
    if(res.first=="PM10" && res.second==7){
        cout << "Test reussi avec les valeurs ";
    }else{
        cout<< "Test echoué avec les valeurs ";
    }
    cout << res.first << " " << res.second<<endl<< endl << endl;
}
void test2(){
    cout<< "Execution du test2" << endl;
    cout<< "On evalue l'indice atmo dans le point 46.8,  -1 pour un rayon de 50 le jour 2019-07-11" << endl;
    cout << "Nous attendons les valeurs PM10 et 6 et que User0 finisse avec 4 points"<< endl << endl << endl;
    pair<string, int> res = service.trouverIndiceAtmo(46.8, -1, 50, "2019-07-11");
    if(res.first=="PM10" && res.second==6){
        cout << "Test reussi avec les valeurs ";
    }else{
        cout<< "Test echoué avec les valeurs ";
    }
    cout << res.first << " " << res.second<<endl<< endl << endl;
}
void test3(){
    cout<< "Execution du test3" << endl;
    cout<< "On evalue l'indice atmo dans le point 52,  52 pour un rayon de 10 le jour 2019-07-11" << endl;
    cout << "Nous attendons les valeurs string vide et 1 car il n'y a pas de capteurs dans la zone"<< endl << endl << endl;
    pair<string, int> res = service.trouverIndiceAtmo(52, 52, 10, "2019-07-11");
    if(res.first=="" && res.second==1){
        cout << "Test reussi avec les valeurs ";
    }else{
        cout<< "Test echoué avec les valeurs ";
    }
    cout << res.first << " " << res.second<<endl<< endl << endl;
}
void test4(){
    cout<< "Execution du test4" << endl;
    cout<< "On evalue l'indice atmo dans le point 46,  1 pour un rayon de 50 le jour 2021-07-11" << endl;
    cout << "Nous attendons les valeurs string vide et 1 car il n'y a pas de mesures pour cette date"<< endl << endl << endl;
    pair<string, int> res = service.trouverIndiceAtmo(46, 1, 50, "2021-07-11");
    if(res.first=="" && res.second==1){
        cout << "Test reussi avec les valeurs ";
    }else{
        cout<< "Test echoué avec les valeurs ";
    }
    cout << res.first << " " << res.second<<endl<< endl << endl;
}
void test5(){
    cout<< "Execution du test5" << endl;
    cout << "On cherche a savoir si Sensor0 est defectueux" << endl;
    cout << "Nous attendons la valeur 0 car celui-ci ne l'est pas"<<endl<<endl<<endl;
    int res = service.trouverCapteurDef("Sensor0");
    if(res==0){
        cout << "Test reussi avec les valeurs ";
    }else{
        cout<< "Test echoué avec les valeurs ";
    }
    cout << res<<endl<< endl << endl;
}
void test6(){
    cout<< "Execution du test6" << endl;
    cout << "On cherche a savoir si Sensor36 est defectueux" << endl;
    cout << "Nous attendons la valeur 1 car celui-ci l'est bien"<<endl<<endl<<endl;
    int res = service.trouverCapteurDef("Sensor36");
    if(res==1){
        cout << "Test reussi avec les valeurs ";
    }else{
        cout<< "Test echoué avec les valeurs ";
    }
    cout << res<<endl<< endl << endl;
}