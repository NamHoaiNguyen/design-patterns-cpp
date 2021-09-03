#ifndef INCLUDE_ABSTRACT_H
#define INCLUDE_ABSTRACT_H

template<typename T>
class FunitureAbstract 
{
public:
    ~FunitureAbstract () = default;

    virtual void createChar() = 0;
    virtual void createTable() = 0;
};

#endif