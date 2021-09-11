#ifndef INCLUDE_MANAGER_H
#define INCLUDE_MANAGER_H

#include "employee_component.h"
#include "employee_decorator.h"

#include <iostream>
#include <memory>

template<typename T>
class Manager : public EmployeeDecorator<T> {
// protected:
//     explicit Manager(std::shared_ptr<EmployeeComponent<T>> employee) : EmployeeDecorator(employee) {

//     }

public:
explicit Manager(std::shared_ptr<EmployeeComponent<T>> employee) : EmployeeDecorator<T>(employee) {

    }
    void createRequirement() {
        std::cout << this->employee_->getName() << " create requirements " << std::endl;
    }

    void assignTask() {
        std::cout << this->employee_->getName() << " assign tasks " << std::endl;
    }

    void manageProcess() {
        std::cout << this->employee_->getName() << " manage processes " << std::endl;
    }

    void doTask() override {
        this->employee_->doTask();
        createRequirement();
        assignTask();
        manageProcess();
    }
};

#endif