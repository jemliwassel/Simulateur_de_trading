#ifndef PRIX_JOURNALIER_H_INCLUDED
#define PRIX_JOURNALIER_H_INCLUDED
#include <string.h>
#include "date.h"
#include "action.h"
class prix_journalier
{
public :

    prix_journalier(action a,float p,Date d);
    ~prix_journalier();
    //void recherchePrixJournalier();
    std::string getAction() ;
    Date getDate() ;
    float getPrix();

private:
    action Act;
    float prix ;
    Date date ;
};

#endif // PRIX_JOURNALIER_H_INCLUDED
