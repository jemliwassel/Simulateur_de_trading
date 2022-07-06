#include "portefeuille.h"
#include "titre.h"
#include <iostream>
#include <vector>
#include "bourse.h"
using namespace std;
portefeuille::portefeuille(float soldeD,float soldeR) : soldeDepart(soldeD),soldeRestant(soldeR)
{

}


portefeuille::~portefeuille()
{

}


float portefeuille::getSoldeRestant()
{
    return soldeRestant ;
}

float portefeuille::getSoldeDepart()
{
    return soldeDepart ;
}

 vector<titre> portefeuille::getTitre()
 {
     vector<titre> a ;
     for(unsigned int i=0;i<p.size();i++)
     {
         a.push_back(p[i]);
     }
     return a ;
 }



 void portefeuille::ajouterBudget(float budget)
 {
     this->soldeRestant+=budget ;
 }

 void portefeuille::ajouterT(titre &t)
 {
     (this->p).push_back(t);
 }


 void portefeuille::afficherPortefeuille()
 {
     for(unsigned int i=0;i<p.size();i++)
     {
         cout<<"Action : "<<p[i].getAction()<<" -- "<<"Quantite : "<<p[i].getQuantite()<<endl;
     }
 }


 void portefeuille::modifierQ(string act,int q)
 {
     for(unsigned int i=0;i<p.size();i++)
     {
         if (p[i].getAction()==act)
         {
             p[i].modifierQuantite(q);
         }
     }
 }


 float portefeuille::gain(Date date)
 {
     float gain(0) ;
     for(unsigned int i;i<p.size();i++)
     {
         gain=gain+p[i].getQuantite()*bourseVecteur::chercherPrix(p[i].getAction(),date);

     }
     gain+=soldeRestant - soldeDepart;
     return gain ;
 }
