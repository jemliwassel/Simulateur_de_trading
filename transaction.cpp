#include "transaction.h"
#include "action.h"
#include "string"

transaction::transaction(typeTransaction t, action act, int c): type(t),a(act),quantiteTr(c)
{

}

/*
transaction::transaction()
{

    type=rien;
    action::action(" ") act;
    a=act;
    quantiteTr=0;


}*/

transaction::~transaction()
{

}

