#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include "transaction.h"
#include "portefeuille.h"
#include "date.h"
#include "bourse.h"
#include <string>
#include <vector>
#include <iostream>
class trader
{
public :
    trader();
   // trader(std::string nomT,std::string prenomT,std::string loginT,std::string mdpT) ;
    virtual ~trader() ;
   // virtual typeTransaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b)=0;
   virtual transaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b)=0;
    std::string getLogin() ;
    std::string getMdp();

protected :
/*std::string nom ;
std::string prenom ;
std::string login ;
std::string mdp ;
std::vector <transaction> tr ;
*/
};

class traderAleatoire : public trader
{
public :
    traderAleatoire();
   // traderAleatoire(std::string nomT ,std::string prenomT ,std::string loginT ,std::string mdpT);
    virtual ~traderAleatoire() ;
  // virtual typeTransaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b) ;
    virtual transaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b);
private :

};


class traderAlgo:public trader
{
public :
    traderAlgo();
    //traderAlgo(std::string nomT ,std::string prenomT ,std::string loginT ,std::string mdpT);
    virtual ~traderAlgo();
//virtual typeTransaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b);
virtual transaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b);
private :

};


class traderHumain:public trader
{
public :
    traderHumain();
    //traderHumain(std::string nomT ,std::string prenomT ,std::string loginT ,std::string mdpT);
    virtual ~traderHumain();
 //virtual typeTransaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b) ;
 virtual transaction  faireDecision(Date date,portefeuille &portef,bourseVecteur &b);



private :


};

#endif // TRADER_H_INCLUDED
