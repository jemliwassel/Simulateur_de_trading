#include "date.h"
#include <iostream>
using namespace std ;

Date::Date(int j,int m,int a): jour(j),mois(m),annee(a)
{

}

Date::~Date()
{

}

void Date::afficheDate()
{
   cout << jour << "/" << mois << "/"<< annee<< endl;
}

void Date::incrementer(int n )
{
    int nombreJourMois(0) ;
    bool anneeBissextile(false);

    if(annee%4==0)
        anneeBissextile=true;

    switch(mois)
    {
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10:
    case 12:
        nombreJourMois=31;
    }

    switch (mois)
    {
    case 2 :
        {

        if (anneeBissextile)
        {
            nombreJourMois=29;
        }
        else
        {
            nombreJourMois=28;
        }
        break ;
        }
    case 4:
    case 6 :
    case 9 :
    case 11 :
        nombreJourMois=30;
        break ;


    }

while((n+jour)>nombreJourMois)
{
    n-=nombreJourMois;
    if(mois==12)
    {
        mois=0;
        annee++;
    }
    mois++;
}
jour+=n;

}


void Date::decrementer()
{
    int nombreJourMois(0) ;
    bool anneeBissextile(false);

    if(annee %4==0)
        anneeBissextile=true;
    switch(mois)
    {

    }
}


bool operator==(Date const& a, Date const& b)
{
    if(a.jour==b.jour && a.mois==b.mois && a.annee==b.annee)
    {
        return(true) ;
    }
    else
    {
        return (false);
    }
}


