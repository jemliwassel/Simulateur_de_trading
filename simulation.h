#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "date.h"
#include "bourse.h"
#include "trader.h"
#include "portefeuille.h"
#include <string>
#include <iostream>
using namespace std ;


class simulation
{
public :
  simulation(/*traderHumain& trade,*/portefeuille& porte,bourse &Bourse);
    ~simulation() ;
    //void appliquerDecision(Date date , typeTransaction &type);
    void appliquerDecision(Date date,transaction &trans);
    void ajouterTitre(titre t,Date d);      //ajouter un titre
    void modiferTitre(std::string act,int q, Date d); // Modifier un titre déja existant
    void acheter(std::string act,int q, Date d) ;
    void Vendre(std::string act,int q, Date d) ;
    static Date choisirDate();  //Choisir la date de début
    void ajouterSolde(float s) ;
    float getSoldePortefeuille() ;
    float Gain(Date date);
    std::string getLogin();
    std::string getMdp() ;
    portefeuille &getPortefeuille();


private :

//Date dateSimulation ;  // Date de début de trading
//Date dateActuelle ;    //Date actuelle
int nbJours ;           //Nombre de jours de la simulation

//traderHumain trad ;           //trader humain de la simulation
portefeuille portef ;   // portefeuille de la simulation
bourse b ;
};

#endif // SIMULATION_H_INCLUDED
