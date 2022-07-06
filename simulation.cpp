#include "simulation.h"
#include "trader.h"
#include "date.h"
#include "portefeuille.h"
#include <string>
#include <iostream>
#include <string>

using namespace std ;

simulation::simulation(/*traderHumain& trade,*/portefeuille& porte,bourse &Bourse) : /*trad(trade),*/portef(porte),b(Bourse)
{
}

simulation::~simulation()
{

}

void simulation::ajouterTitre(titre t,Date d)
{
    float prix ;
    portef.ajouterT(t);
    prix=bourseVecteur::chercherPrix(t.getAction(),d);
    portef.ajouterBudget(-t.getQuantite()*prix);
}


void simulation::modiferTitre(std::string act,int q, Date d)
{
    float s,prix ;
    for(unsigned int i=0;i<portef.getTitre().size();i++)
    {
        if((portef.getTitre()[i]).getAction()==act)
        {

            //(portef.getTitre()[i]).modifierQuantite(q);
                 portef.modifierQ(act,q);
             prix=bourseVecteur::chercherPrix(act,d);
            s=q*prix ;
            portef.ajouterBudget(-s);
        }
    }
}

void simulation::acheter(std::string act,int quantite,Date date)
{
   // float prix,s ;
bool existe=false ;
for(unsigned int i=0;i<portef.getTitre().size();i++)
{
    if((portef.getTitre()[i]).getAction()== act)
    {
        /*portef.getTitre()[i].modifierQuantite(quantite);
        prix=bourseVecteur::chercherPrix(act,date);
        s=-quantite*prix ;
        portef.ajouterBudget(s);*/
        modiferTitre(act,quantite,date);
        existe=true;
        break;

    }
}

if(!existe)
{
    titre t(act,quantite);
    ajouterTitre(t,date);
}

}

void simulation::Vendre(std::string act,int q, Date d)
{
   // float prix,s;
 //  bool existe=false ;
    for(unsigned int i=0;i<portef.getTitre().size();i++)
    {
        if((portef.getTitre()[i]).getAction()==act/*&& q<portef.getTitre()[i].getQuantite()*/)
        {


            modiferTitre(act,-q,d);
        //    existe=true;
            break;

        }

       /* else
        {
            cout<< " Vous ne disposez pas d'une quantite suffisante pour vendre cette action"<<endl;
        }*/
    }

    /*if(!existe)
    {
        cout<<"Cette action n'existe pas dans votre portefeuille"<<endl;
    }*/
}

void simulation::appliquerDecision(Date date,transaction &trans)
{
    string act ;
    int quantite;
    if (trans.type==rien)
    {
        bool test=false;
        while(!test)
        {
            date.incrementer(1);
            for(int i=0;bourseVecteur::prixJ.size();i++)
            {
                if(bourseVecteur::prixJ[i].getDate()==date)
                {
                    test=true ;
                    break;
                }
            }
            if (date.annee==2017)
            {
                cout<<"date limite depasse"<<endl;
                trans.type=deconnecter;
                break;
            }
        }
    }

    else if (trans.type==achat)
    {

       /* cout<<"Donnez le nom de l'action a acheter"<<endl ;
        cin>>act;
        cout<<"Donnez la quantite de l'action a acheter"<<endl ;
        cin>>quantite;
        this->acheter(act,quantite,date);*/

        this->acheter(trans.a.getAction(),trans.quantiteTr,date);

    }

    else if(trans.type==vente)
    {
       /* cout<<"Donnez le nom de l'action a vendre"<<endl ;
        cin >>act;
        cout<<"Donnez la quantite de l'action a vendre"<<endl ;
        cin>>quantite;
        this->Vendre(act,quantite,date);*/

        this->Vendre(trans.a.getAction(),trans.quantiteTr,date);

    }

    else if(trans.type==ajouter)
    {
        float montant;
        cout<<" Entrer le montant a ajouter : "<<endl;
        cin>>montant;
        this->ajouterSolde(montant);
    }


}

Date simulation::choisirDate()
{
    Date d(04,01,2010);
    cout<<" On va choisir la date de debut de la simulation "<<endl ;
    cout<<"Le jour : "<<endl;
    cin>>d.jour;
    cout<<" Le mois: "<<endl;
    cin>>d.mois;
    cout<<"L'annee : "<<endl;
    cin>>d.annee;
    bool bo=false;
    while(!bo)
    {
        for(int i=0;bourseVecteur::prixJ.size();i++)
        {
            if(bourseVecteur::prixJ[i].getDate()==d)
            {
                bo=true ;
                break;
            }
        }
        if(!bo)
        {
            d.incrementer(1);
        }
    }
    return(d);
}

float simulation::Gain(Date date)
{
    float gain=0 ;
   /* for(unsigned int i; i<portef.getTitre().size();i++)
    {
        gain+=portef.getTitre()[i].getQuantite()*bourseVecteur::chercherPrix(portef.getTitre()[i].getAction(),date);
    }

    gain=gain + portef.getSoldeRestant()-portef.getSoldeDepart();*/
    gain=portef.gain(date);
    return(gain);
}

portefeuille& simulation::getPortefeuille()
{
    return portef ;
}



void simulation::ajouterSolde(float s)
{
    this->portef.ajouterBudget(s);
}
