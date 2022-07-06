#include "bourse.h"
#include<string>
#include<vector>
#include<cstdlib>
using namespace std ;
vector<prix_journalier> bourseVecteur::prixJ;

bourse::bourse()
{

}

bourse::~bourse()
{

}

bourseVecteur::bourseVecteur()
{

}

bourseVecteur::~bourseVecteur()
{

}

float bourseVecteur::chercherPrix(string a,Date d)
{
    bool rech(false);
    for(unsigned int i=0;i<prixJ.size();i++)
    {
        if(prixJ[i].getDate()==d && prixJ[i].getAction()==a)
        {
            rech=true ;
            return (prixJ[i].getPrix()) ;
        }
    }

    if(!rech)
        return(0);
}


void bourseVecteur::AjouterPrixJournalier(prix_journalier p)
{
    prixJ.push_back(p);
}


void bourseVecteur::afficherPrixAujourdhui(Date date)
{
    cout<<" Voici les actions qui correspondent a la date d'aujourd'hui: ";
    date.afficheDate();

     for(unsigned int i=0; i<prixJ.size();i++)     //afficher les prix Journaliers de lda date "date"
        {
            if(prixJ[i].getDate()==date)
            {
                cout<<"Action : "<<prixJ[i].getAction()<<" -- "<<"Prix :"<<prixJ[i].getPrix()<<endl;
            }
        }
}


bourseMap::bourseMap()
{

}


bourseMap::~bourseMap()
{

}



