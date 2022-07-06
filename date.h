#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
class Date
{
public :

    Date(int j,int m,int a);
    ~Date();
    void afficheDate() ;
    void incrementer(int n) ;
    void decrementer() ;
    int jour ;
    int mois ;
    int annee;

};

bool operator==(Date const& a, Date const& b) ; //comparer deux dates

#endif // DATE_H_INCLUDED
