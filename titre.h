#ifndef TITRE_H_INCLUDED
#define TITRE_H_INCLUDED
#include "action.h"
class titre
{
public :
    titre(action a ,int q);
    ~titre();
    void modifierQuantite(int q);
    std::string getAction() ;
    int getQuantite();
private :

    action act ;
    int quantite;

};

#endif // TITRE_H_INCLUDED
