#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include "prix_journalier.h"
#include <vector>
#include <string>
#include <map>
#include "date.h"

class bourse
{
public :
    bourse();
    ~bourse();
    static float chercherPrix(std::string a,Date d);



};



class bourseVecteur: public bourse
{

public :
    bourseVecteur();
    ~bourseVecteur();
   static std::vector <prix_journalier> prixJ;
static float chercherPrix(std::string a,Date d);
void AjouterPrixJournalier(prix_journalier p) ;
void afficherPrixAujourdhui(Date date);
};

class bourseMap: public bourse
{
public :
    bourseMap();
    ~bourseMap();
    static std::map<action,prix_journalier> prixJ;
    static float chercherPrix(std::string a,Date d);
    void AjouterPrixJournalier(prix_journalier p) ;
    void afficherPrixAujourdhui(Date date);
};


#endif // BOURSE_H_INCLUDED
