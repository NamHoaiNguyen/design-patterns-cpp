#ifndef observer
#define observer

// template<typename T>    
class Observer {
protected:
	int id;

public:
    virtual void Update() = 0;

    template<typename S>
    friend bool operator ==(const Observer& obs1, const Observer& obs2);
};

template<typename S>
bool operator== (const Observer& obs1, const Observer& obs2)
{
    return &obs1 == &obs2;
}

#endif
