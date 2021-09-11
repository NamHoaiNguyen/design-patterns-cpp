#ifndef INCLUDE_EMPLOYEE_COMPONENT_H
#define INCLUDE_EMPLOYEE_COMPONENT_H

#include <iostream>
#include <string>

template<typename T>
class EmployeeComponent {
public:
    virtual std::string getName() = 0;
    
    virtual void doTask() = 0;
   
    // virtual void joinDate(const T& joinDate) = 0;
   
    // virtual void terminateDate(const T& terminateDate) = 0;

    void showBasicInfo();
};

template<typename T>
void EmployeeComponent<T>::showBasicInfo() {
    std::cout << "-----------" << std::endl;
    std::cout << "The basic information " << getName() << std::endl;
   
}

#endif