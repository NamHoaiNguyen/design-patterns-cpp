#ifndef observer
#define observer

template<typename T>    
class Observer {
public:
    int id;

    virtual void Update() = 0;
};


#endif
