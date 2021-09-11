#ifndef INCLUDE_TEAM_LEADER_H
#define INCLUDE_TEAM_LEADER_H

template<typename T>
class TeamLeader : public EmployeeDecorator<T>{
public:
    explicit TeamLeader(std::shared_ptr<EmployeeComponent<T>> employee) : EmployeeDecorator<T>(employee) {

    }
    void planning() {
        std::cout << this->employee_->getName() << " plans " << std::endl;
    }

    void motivate() {
        std::cout << this->employee_->getName() << " motivate team members " << std::endl;
    }

    void monitor() {
        std::cout << this->employee_->getName() << " monitor team members " << std::endl;
    }

    void doTask() override {
        this->employee_->doTask();
        planning();
        motivate();
        monitor();
    }  
};

#endif