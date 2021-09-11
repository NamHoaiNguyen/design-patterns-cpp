#ifndef INCLUDE_TEAM_MEMBER_H
#define INCLUDE_TEAM_MEMBER_H

template<typename T>
class TeamMember : public EmployeeDecorator<T>{
public:
    explicit TeamMember(std::shared_ptr<EmployeeComponent<T>> employee) : EmployeeDecorator<T>(employee) {

    }
    void reportTask() {
        std::cout << this->employee_->getName() << " report tasks " << std::endl;
    }

    void coordinateWithOthers() {
        std::cout << this->employee_->getName() << " coordinate with others " << std::endl;
    }

    void doTask() override {
        this->employee_->doTask();
        reportTask();
        coordinateWithOthers();
    }  
};

#endif