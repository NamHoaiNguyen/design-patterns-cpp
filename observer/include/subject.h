#include "user.h"
#include "observer/observer.h"

#include <memory>

template<typename T>
class Subject {
public:
    virtual void Attach(T* observer) = 0;
    virtual void Detach(T* observer) = 0;
    virtual void Notify() = 0;    
};
