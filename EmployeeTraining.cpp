#include <iostream>
using namespace std;

class Employee 
{
    private:
        int associateId;
        string associateName;
        string workStatus;
    public:
        void setAssociateId(int id)
        {
            associateId = id;
        }
        void setAssociateName(string name)
        {
            associateName = name;
        }
        void setWorkStatus(string workStatus)
        {
            workStatus = workStatus;
        }
        
        void updateStatusDetails(int workDays)
        {
            if (workDays <= 20)
            {
                workStatus = "Core skills";
                setWorkStatus(workStatus);
            }
            else if (workDays > 20 && workDays <= 40)
            {
                workStatus = "Advanced skills";
                setWorkStatus(workStatus);
            }
            else
            {
                workStatus = "Project phase";
                setWorkStatus(workStatus);
            }
        }
        
        int getAssociateId()
        {
            return associateId;
        }
        string getAssociateName()
        {
            return associateName;
        }
        string getWorkStatus()
        {
            return workStatus;
        }
};

int main()
{
    int id{};
	string name{};
	int days{};
	
	cout<<"Enter the associate id:\n";
	cin>>id;
	cout<<"Enter the associate name:\n";
	cin>>name;
	cout<<"Enter the number of days:\n";
	cin>>days;
	
	Employee emp;
	
	emp.setAssociateId(id);
	emp.setAssociateName(name);
	emp.updateStatusDetails(days);
	
	cout << "The associate " << emp.getAssociateName() << " work status: " << emp.getWorkStatus();
	
    return 0;
}
