#ifndef INCLUDE_EMPLOYEE_CONCRETE_COMPONENT_H
#define INCLUDE_EMPLOYEE_CONCRETE_COMPONENT_H

#include <string>

template<typename T>
class EmployeeConcreteComponent : public EmployeeComponent<T> {
private:
    std::string name_;

public:
    EmployeeConcreteComponent() = delete;

    explicit EmployeeConcreteComponent(std::string name) : name_(name) {

    }

    std::string getName() {
        return name_;
    }

    void doTask() override {

    }

    // void joinDate(const T& joinDate) override {
    //     std::cout << this->name_ << " joined on " << joinDate << std::endl;
    // }

    // void terminateDate(const T& terminateDate) override {
    //     std::cout << this->name_ << " joined on " << terminateDate << std::endl;
    // }
};

#endif