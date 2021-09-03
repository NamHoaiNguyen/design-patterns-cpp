#ifndef INCLUDE_FURNITURE_FACTORY_H
#define INCLUDE_FURNITURE_FACTORY_H

template<typename T>
class FunitureFactory
{
public:
    ~FunitureFactory () = default;

    virtual void createChar() = 0;
    virtual void createTable() = 0;
};

#endif