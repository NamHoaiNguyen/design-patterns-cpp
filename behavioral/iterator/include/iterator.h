#ifndef iterator 
#define iterator 

template<typename T>
class Iterator {
private:

public:
    Iterator() = default;

    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual void currentItem() const = 0;
};

#endif