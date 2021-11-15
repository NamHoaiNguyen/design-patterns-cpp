#include "employee_component.h"
#include "employee_concrete_component.h"
#include "manager.h"
#include "team_leader.h"
#include "team_member.h"

#include <iostream>
#include <memory>

int main()
{
    std::cout << "\nNORMAL EMPLOYEE " << std::endl;
    std::shared_ptr<EmployeeComponent<std::string>> employee = std::make_shared<EmployeeConcreteComponent<std::string>>("Alex");
    employee->showBasicInfo();
    employee->doTask();

    std::cout << "\nTEAM LEADER " << std::endl;
    std::shared_ptr<EmployeeComponent<std::string>> teamLeader = std::make_shared<TeamLeader<std::string>>(employee);
    teamLeader->showBasicInfo();
    teamLeader->doTask();

    std::cout << "\nMANAGER " << std::endl;
    std::shared_ptr<EmployeeComponent<std::string>> manager = std::make_shared<Manager<std::string>>(employee);
    manager->showBasicInfo();
    manager->doTask();

    std::cout << "\nTEAM LEADER AND MANAGER " << std::endl;
    std::shared_ptr<EmployeeComponent<std::string>> teamLeaderAndManager = std::make_shared<Manager<std::string>>(teamLeader);
    teamLeaderAndManager->showBasicInfo();
    teamLeaderAndManager->doTask();
    return 0;
}