#include <memory>

template<typename T>
class Subject {
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void notify() = 0;
};