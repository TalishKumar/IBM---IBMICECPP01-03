#include <iostream>
using namespace std;

struct Employee
{
  int empid{};
  int basicsalary{};
  int pf{};
  int med{};
  float sales{};
  
  int calc_Bonus()
  {
      int bonus{};
      
      if (basicsalary <= 7000 && sales <= 10)
      {
          bonus = 1500;
      }
      else if (basicsalary <= 7000 && sales >= 10)
      {
          bonus = 3000;
      }
      else if (basicsalary > 7000 && basicsalary <= 15000 && sales <= 10)
      {
          bonus = 2000;
      }
      else if (basicsalary > 7000 && basicsalary <= 15000 && sales >= 10)
      {
          bonus = 4000;
      }
      else if (basicsalary > 15000 && sales <= 10)
      {
          bonus = 2500;
      }
      else if (basicsalary > 15000 && sales >= 10)
      {
          bonus = 4500;
      }
      
      return bonus;
  }
  int calc_NetSalary()
  {
      int netSalary{basicsalary - pf - med};
      
      return netSalary;
  }
};

int main()
{
    struct Employee emp;
    
    cout << "Enter the employee id\n";
    cin >> emp.empid;
    
    cout << "Enter the basic salary\n";
    cin >> emp.basicsalary;
    
    cout << "Enter the PF amount\n";
    cin >> emp.pf;
    
    cout << "Enter the mediclaim amount\n";
    cin >> emp.med;
    
    cout << "Enter the sales percentage\n";
    cin >> emp.sales;
    
    if (emp.empid <= 0 || emp.basicsalary <= 0 || emp.pf <= 0 || emp.med <= 0 || emp.sales <= 0)
    {
        cout << "Unable to Calculate Salary";
    }
    else
    {
        int bonus{emp.calc_Bonus()};
        int netSalary{emp.calc_NetSalary()};
        int totalSalary{netSalary + bonus};
        
        cout << "Total Salary with Bonus is $" << totalSalary;
    }
    
    return 0;
}
