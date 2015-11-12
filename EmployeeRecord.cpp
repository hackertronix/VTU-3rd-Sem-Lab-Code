#include"iostream"
using namespace std;

// MAINTIAIN EMPOYEE RECORD

class Employee
{
private:

    int employeeNumber,basicSalary,incomeTax,netSalary,allowance;
    char name[20];

public:
    void accept();
    void calculate();
    void display();

};

void Employee::accept()
{
    cout<<"Enter the Employee's name, number & Basic Salary\n";
    cin>>name>>employeeNumber>>basicSalary;
}


void Employee::calculate()
{
    int grossSalary;

    allowance=1.23*basicSalary;
    grossSalary=basicSalary+allowance;

    incomeTax=0.3*grossSalary;
    netSalary=basicSalary+allowance-incomeTax;

}

void Employee::display()
{
    cout<<"Employee Name :"<<name<<endl;
    cout<<"Employee number :"<<employeeNumber<<endl;
    cout<<"Basic salary :"<<basicSalary<<endl;
    cout<<"Allowance :"<<allowance<<endl
    <<"Income tax :"<<incomeTax<<endl<<"Net Salary :"<<netSalary<<endl;

}

int main()
{
    Employee emp;
    emp.accept();
    emp.calculate();
    emp.display();

    return 0;
}
