#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"

namespace sdds
{
    struct Employee
    {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    
    void sort();

    
    bool load(Employee& emp);

  
    bool load();

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:
    void display(const Employee& emp);

    // TODO: Declare the prototype for the display function that
    // first sorts the employees then displays all the employees on the screen
    void display();

    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array
    void deallocateMemory();
} 
#endif 