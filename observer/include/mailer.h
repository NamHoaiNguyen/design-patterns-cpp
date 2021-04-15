#ifndef mailer
#define mailer 

#include "observer.h"

class Mailer : public Observer
{
    virtual void update() override;
};

void Mailer::update()
{

}

#endif