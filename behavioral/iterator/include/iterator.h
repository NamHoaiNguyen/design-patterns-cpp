#ifndef iterator_h
#define iterator_h

template<typename T>
class Iterator {
private:

public:
    virtual ~Iterator() { }

    virtual void first() = 0;

    virtual void next() = 0;

    virtual bool isDone() const = 0;
    
    virtual T currentItem() const = 0;
};

#endif