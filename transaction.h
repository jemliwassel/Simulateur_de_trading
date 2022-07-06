#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include "action.h"

enum typeTransaction {achat,vente,rien,deconnecter,ajouter};

class transaction
{
public :
    typeTransaction type ;
    action a ;
    int quantiteTr ;
    transaction(typeTransaction t, action act, int q) ;
    transaction();

    ~transaction() ;
};

#endif // TRANSACTION_H_INCLUDED
