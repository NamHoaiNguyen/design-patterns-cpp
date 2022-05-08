#ifndef INCLUDE_SINGLETON_H
#define INCLUDE_SINGLETON_H

#include <iostream>
#include <optional>
#include <memory>
#include <mutex>
#include <thread>

template<typename T>
class Singleton {
private:
    static std::shared_ptr<Singleton<T>> mInstancePtr; 
    static Singleton<T> *raw_pointer;
    static std::mutex mutex_;
    T value;

    explicit Singleton(T const& value);
    ~Singleton()
    {
        delete raw_pointer;
    }

public:
    // Singleton(T const& value);
    Singleton(Singleton &signleton) = delete;
    Singleton& operator=(const Singleton &singleton) = delete;
    static std::shared_ptr<Singleton<T>>GetInstance(T const& value);
    static Singleton *GetInstanceRawPointer(T const& value);
    T getValue(); 
};

/*Static member*/
template<typename T>
std::shared_ptr<Singleton<T>> Singleton<T>::mInstancePtr = nullptr;

template<typename T>
Singleton<T> *Singleton<T>::raw_pointer;

template<typename T>
std::mutex Singleton<T>::mutex_;

template<typename T>
Singleton<T>::Singleton(T const& value) : value(value)
{

}

template<typename T>
std::shared_ptr<Singleton<T>>Singleton<T>::GetInstance(T const& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (mInstancePtr == nullptr) {
        mInstancePtr = std::make_shared<Singleton<T>>(value);
    }
    return mInstancePtr;
}

template<typename T>
Singleton<T>* Singleton<T>::GetInstanceRawPointer(T const& value) 
{
    /*should use double checked locking*/
    std::lock_guard<std::mutex> lock(mutex_);
    if (raw_pointer == nullptr) {
        raw_pointer = new Singleton<T>(value);
    }
    return raw_pointer;
}

template<typename T>
T Singleton<T>::getValue() {
    return value;
}

class NewSingleton {
    public:
        static NewSingleton* getInstance(const std::string& str);


    private:
        NewSingleton() = default;

        NewSingleton(const std::string& str) {
            std::cout << str << std::endl;
        }

        // std::string getValue() {
        //     return 
        // }

        static std::optional<NewSingleton> m_instance;
        static std::once_flag m_flag;
};

std::optional<NewSingleton> NewSingleton::m_instance;
std::once_flag NewSingleton::m_flag{};

NewSingleton* NewSingleton::getInstance(const std::string& str) {
    std::call_once(NewSingleton::m_flag,
                    [&str](){ m_instance.emplace(NewSingleton{str}); });
    return &*m_instance;
}

void createString(std::string const& str)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // auto test = Singleton<std::string>::GetInstanceRawPointer(str);
    // auto singleton = Singleton<std::string>::GetInstance(str);
    auto test = NewSingleton::getInstance(str);
    // std::cout << singleton->getValue() << std::endl;
    // std::cout << test->getValue() << std::endl;

}

#endif