double  trouverIndiceAtmo( vector<Mesure> mesures){
    double sommeO3=0;
    double sommeNO2=0;
    double sommeSO2=0;
    double sommePm10=0;
    int nbO3=0;
    int nbNO2=0;
    int nbSO2=0;
    int nbPM0=0;


    for(int i(0);i<mesures.size();i++){
        if(mesures[i].attributeID=="O3"){
            sommeO3=sommeO3 + mesures[i].value;
            nbO3++;

        }else if(mesures[i].attributeID=="NO2"){
            sommeNO2=sommeNO2+mesures[i].value;
            nbNO2++;

        }else if(mesures[i].attributeID=="SO2"){
            sommeSO2=sommeSO2+mesures[i].value;
            nbSO2++;

        }else if (mesures[i].attributeID=="PM10"){
            sommePm10=sommePm10+mesures[i].value;
            nbPM0++;

        }

    }
    double moyenneO3=sommeO3/nbO3;
    double moyenneNo2=sommeNO2/nbNO2;
    double moyenneSO2=sommeSO2/nbSO2;
    double moyennePM10=sommePm10/nbPM0;

    cout<<"moyenneO3:" <<moyenneO3<<endl;
    cout<<"moyenneSO2:" <<moyenneSO2<<endl;
    cout<<"moyennePM10:" <<moyennePM10<<endl;
    cout<<"moyenneNO2:" <<moyenneNo2<<endl;

    double maxi1=max(moyenneNo2,moyenneO3);
    double maxi2=max(moyenneSO2,moyennePM10);
    double maxi=max(maxi1,maxi2);
    cout<<"le maxi est "<<maxi<<endl;
    return maxi;


}