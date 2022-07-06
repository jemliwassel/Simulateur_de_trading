#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include "titre.h"
#include "date.h"
#include <vector>
using std::vector ;
class portefeuille
{
public :
    portefeuille(float soldeD,float soldeR) ;
    ~portefeuille();
    float getSoldeRestant() ;
    float getSoldeDepart() ;
     vector<titre> getTitre();
     void ajouterT(titre &t);
     void ajouterBudget(float budget);
     void afficherPortefeuille();
     void modifierQ(std::string act,int q);
     float gain(Date date);

private :
   std::vector<titre> p ;
   float soldeDepart ;
   float soldeRestant ;
};

#endif // PORTEFEUILLE_H_INCLUDED
