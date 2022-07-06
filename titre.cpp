#include "titre.h"

titre::titre(action a ,int q) : act(a),quantite(q)
{

}


titre::~titre()
{

}

void titre::modifierQuantite(int q)
{
    quantite+=q;
}

std::string titre::getAction()
{
    return act.getAction();

}

int titre::getQuantite()
{
    return quantite;
}
