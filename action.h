#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED
#include <string>
class action
{
private :
  std::string  act ;

public:
  action(std::string a) ;
  ~action();
  std::string getAction();

};


#endif // ACTION_H_INCLUDED
