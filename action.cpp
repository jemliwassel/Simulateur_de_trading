#include "action.h"
using namespace std;

action::action(std::string a):act(a)
{

}

action::~action()
{

}

string action::getAction()
{
    return act ;
}
