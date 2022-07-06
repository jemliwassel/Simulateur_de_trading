#include <iostream>
#include <string>
#include <cstdlib>
#include "transaction.h"
#include "trader.h"
#include "date.h"
using namespace std ;
/*trader::trader(std::string nomT,std::string prenomT,std::string loginT,std::string mdpT)
{
    nom=nomT;
    prenom=prenomT;
    login=loginT;
    mdp=mdpT;
}
*/
trader::trader()
{

}

trader::~trader()
{

}
/*
traderHumain::traderHumain(std::string nomT,std::string prenomT,std::string loginT,std::string mdpT) :  trader(nomT,prenomT,loginT,mdpT)
{
   //trader(std::string nomT,std::string prenomT,std::string loginT,std::string mdpT);
   nom=nomT;
    prenom=prenomT;
    login=loginT;
    mdp=mdpT;
}
*/

traderHumain::traderHumain()
{

}


traderHumain::~traderHumain()
{

}


transaction  traderHumain::faireDecision(Date date,portefeuille &portef,bourseVecteur &b)
{
string trans ;
typeTransaction typeTrans ;
action a("");
//typeTransaction tt=rien;
transaction t(rien,a,0);
bool test =false ;
string act;
int quantite;
/*
for(unsigned int i=0;i<portef.getTitre().size();i++)
{
    cout<<"Voici Vos actions "<<endl ;
    cout<<"Action : "<<portef.getTitre()[i].getAction()<<endl;
}
*/
//b.afficherPrixAujourdhui(date);
cout<<endl;
while(!test)
{
    cout<<"Entrer 'achat','vente','rien' 'ajouter' ou 'deconnecter' "<<endl;
    cin>>trans;

    if(trans=="achat")
    {
        typeTrans=achat;
        test=true;
      //break;
    }

    else if(trans=="vente")
    {
        typeTrans=vente;
        test=true;
        //break ;
    }

    else if (trans=="rien")
    {
        typeTrans=rien;
        test=true;
        //break ;
    }

    else if (trans=="deconnecter")
    {
        typeTrans=deconnecter;
        test=true;
        //break ;
    }

    else if(trans=="ajouter")
    {
        typeTrans= ajouter;
        test=true;
    }
}

if (typeTrans==rien)
{
    action a("");
   transaction t(typeTrans,a,0);

}

else if (typeTrans==achat)
{
    cout<<"Donnez le nom de l'action a acheter"<<endl ;
        cin>>act;
        cout<<"Donnez la quantite de l'action a acheter"<<endl ;
        cin>>quantite;
        action a(act);
        t.type=achat;
        t.a=a;
        t.quantiteTr=quantite;
       // transaction t(achat,a,quantite);
}

else if(typeTrans==vente)
{
    cout<<"Donnez le nom de l'action a vendre"<<endl ;
        cin >>act;
        cout<<"Donnez la quantite de l'action a vendre"<<endl ;
        cin>>quantite;
        action a(act);
        t.type=vente;
        t.a=a;
        t.quantiteTr=quantite;

       // transaction t(vente,a,quantite);
}

else if(typeTrans==ajouter)
{
    action a("");
    t.type=ajouter;
  //  transaction t(typeTrans,a,0);
}

else if(typeTrans==deconnecter)
{
    t.type=deconnecter;
}


return (t);





//return (typeTrans);
}

traderAleatoire::traderAleatoire()
{

}


traderAleatoire::~traderAleatoire()
{

}


transaction traderAleatoire::faireDecision(Date date,portefeuille &portef,bourseVecteur &b)
{
    int choix =rand()%5 +2 ;
    int numAction ;    //le numero de l'action dans le vecteur des prix journaliers
    int quantiteAction;  // quantite maximale de l'action a acheter
    int quantiteAleatoire;   //quantite aleatoire de l'action a acheter
    string act ;
    typeTransaction type ;
    action a("");
    transaction t(rien,a,0);

    //cout<<" choix : "<<choix<<endl;
    if(choix==1)  // type de transaction = rien
    {
        type=rien;
        transaction t(type,a,0);
    }

    else if (choix==2)   // type de transaction = achat
    {
        numAction=rand()% b.prixJ.size()+1;

        act=b.prixJ[numAction].getAction() ;
        action a(act);
        quantiteAction=portef.getSoldeRestant() / b.prixJ[numAction].getPrix();
        quantiteAleatoire= rand()% quantiteAction+1;
        t.a=a;
        t.type=achat;
       t.quantiteTr=quantiteAleatoire;

    }

    else if(choix==3)  // type de transaction = vente
    {
        numAction=rand()% portef.getTitre().size()+1;
       act= (portef.getTitre()[numAction]).getAction() ;
        action a(act);
        quantiteAleatoire=rand()%(portef.getTitre()[numAction]).getQuantite() +1;
        t.a=a;
        t.type=vente;
        t.quantiteTr=quantiteAleatoire;
    }

    else if(choix==4)    // type de transaction = ajouter solde
    {
        t.type=ajouter;
    }

    else if (choix==5)      // type de transaction = deconnecter
    {
        t.type=deconnecter;
    }

    return(t);
}


/*
traderAlgo::traderAlgo()
{

}*/

/*
traderAlgo::~traderAlgo()
{

}*/

/*
transaction traderAlgo::faireDecision(Date date,portefeuille &portef,bourseVecteur &b)
{

    typeTransaction type ;
    action a("");
    transaction t(rien,a,0);
    Date demain(date.jour,date.mois,date.annee);
    demain.incrementer(1);
    for (int i=0;i<b.prixJ.size()<i++)
    {
        if(b.chercherPrix((portef.getTitre()[i]).getAction(),date) < b.chercherPrix(b.chercherPrix((portef.getTitre()[i]).getAction(),demain)))
        {
            type=achat;
            transaction(a)
        }
    }


}

*/
