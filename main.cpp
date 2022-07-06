#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "gestionHistorique.h"
#include "prix_journalier.h"
#include "date.h"
#include "titre.h"
#include "transaction.h"
#include "trader.h"
#include "bourse.h"
#include "simulation.h"

using namespace std;

int main()
{


 cout << "Bienvenue dans notre bourse " <<endl<<endl ;
float budget ;

int nombreJourSimulation ;
cout<<"Taper le nombre de jours de la simulation : "<<endl;
cin>>nombreJourSimulation;

vector <prix_journalier> vectSimulation ;
Date dateFin(0,0,0) ;
    int mode=0;
    int i=0;
    cout<<"**** Choisir le mode de travail ****"<<endl;
    cout<<" Mode client humain : Taper 1 "<<endl;
    cout<<" Mode aleatoire : Taper 2"<<endl;
    cout<<" Mode algorithmique : Taper 3"<<endl;
    cin>>mode;
    system("cls");
bourseVecteur b ;
    if (mode==1)
    {
        cout<<"Entrer votre budget:"<<endl;
   cin>>budget;
   system("cls");
        Date date(04,01,2010) ;
        typeTransaction t=rien;

        string act ;
        portefeuille portef(budget,budget);
         gestionHistorique g ;
        g.recherchePrixJournalier();
//        traderHumain tHumain(nom,prenom,login,motDePasse);
        traderHumain tHumain ;
       simulation s(/*tHumain,*/portef,b);
        date=s.choisirDate();

b.afficherPrixAujourdhui(date);    //Afficher les actions et leurs prix de la date saisie par le trader humain
    action a("");
        transaction trans(rien,a,0) ;

      while(trans.type != deconnecter && i<nombreJourSimulation)   // On est encore dans la période de simulation
       {

           cout<<"*******************"<<endl;

         trans=tHumain.faireDecision(date,portef,b);
         if(trans.type==rien)
         {
             i++;
             date.incrementer(1);
             b.afficherPrixAujourdhui(date);

         }

            s.appliquerDecision(date,trans);
            cout<<endl;
            cout<< "Solde restant : " <<s.getPortefeuille().getSoldeRestant()<<endl;
            cout<<"*******************"<<endl;

       }

/*
       for(unsigned int i=0; i<portef.getTitre().size();i++)
       {
           cout<<(portef.getTitre()[i]).getAction()<<(portef.getTitre()[i]).getQuantite()<<endl;
       }*/
cout<<"Voici vos action : "<<endl;
       portef=s.getPortefeuille();
       portef.afficherPortefeuille();


        cout <<"Voici votre gain"<<endl ;
        cout<<portef.gain(date)<<endl;

    }


    if (mode==2)
    {
        cout<<"Entrer votre budget : "<<endl;
        cin>>budget;
        system("cls");
        int jour =rand()%31 +1;
        int mois =rand()%12+1;
        int annee = rand()%6+2010;
        Date d(jour,mois,annee);
        d.afficheDate() ;
        portefeuille portef(budget,budget);
        gestionHistorique g;
        g.recherchePrixJournalier();
        traderAleatoire traderA ;
        simulation s(portef,b);
         action a("");
        transaction trans(rien,a,0) ;
         while(trans.type != deconnecter && i<nombreJourSimulation)
         {
            cout<<"*******************"<<endl;
            trans=traderA.faireDecision(d,portef,b);
            if(trans.type==rien)
         {
             i++;
             d.incrementer(1);

         }
            s.appliquerDecision(d,trans);
            cout<<endl;
            cout<< "Solde restant : " <<s.getPortefeuille().getSoldeRestant()<<endl;
            cout<<"*******************"<<endl;
         }
        cout<<"Voici vos action : "<<endl;
       portef=s.getPortefeuille();
       portef.afficherPortefeuille();
       cout<<"*************"<<endl;
       cout <<"Voici votre gain"<<endl ;
        cout<<portef.gain(d)<<endl;




    }



}
