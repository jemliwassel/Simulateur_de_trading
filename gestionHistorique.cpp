#include "gestionHistorique.h"
#include "bourse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std ;
gestionHistorique::gestionHistorique()
{

}


gestionHistorique::~gestionHistorique()
{

}


void gestionHistorique::recherchePrixJournalier()
{
     bourseVecteur b;
    ifstream fichier("prices_simple.csv");
    if (fichier)
    {
        string ligne ;
        getline(fichier,ligne);
        while(getline(fichier,ligne))
        {
            Date d(atoi(ligne.substr(0,2).c_str()),atoi(ligne.substr(3,2).c_str()),atoi(ligne.substr(6,4).c_str()));
            int position1=ligne.find(";");
            int position2=ligne.substr(position1+1).find(";");
            string act=ligne.substr(position1+1,position2);
            float prix=atof(ligne.substr(position1+position2+2,ligne.substr(position1+position2+2).find(";")).c_str());
            prix_journalier pj(act,prix,d);
            b.AjouterPrixJournalier(pj);
        }
    }

    else
    {
        cout<< "ERREUR : Impossible d'ouvrir le fichier en lecture ."<<endl;
    }

}
