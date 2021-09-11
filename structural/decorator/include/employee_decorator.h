#ifndef INCLUDE_EMPLOYEE_DECORATOR_H
#define INCLUDE_EMPLOYEE_DECORATOR_H

#include "employee_component.h"

#include <memory>

template<typename T>
class EmployeeDecorator : public EmployeeComponent<T> {
protected:
    std::shared_ptr<EmployeeComponent<T>> employee_;

    explicit EmployeeDecorator(std::shared_ptr<EmployeeComponent<T>> employee) : employee_(employee) {

    }

public:
    std::string getName() override {
        return employee_->getName();
    }

    // void joinDate(const T& joinDate) override {
    //     employee_->joinDate(joinDate);
    // }

    // void terminateDate(const T& termindateDate) override {
    //     employee_->terminateDate(termindateDate);
    // }
};

#endif