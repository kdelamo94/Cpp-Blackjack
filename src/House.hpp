#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "GenericPlayer.hpp"

class House : public GenericPlayer{
  public:
    //Janitor Functions
    House(const string& name = "House");

    //Member functions
    void flipFirst();

    //Overidden functions
    virtual bool isHitting() const;
};

#endif
