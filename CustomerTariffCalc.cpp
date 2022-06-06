#include <iostream>
#include <string>
using namespace std;

class Customer
{
protected:
	string name;
	int units;
	string email;
public:
	void setName(string n){
		name = n;
	}
	string getName(){
		return name;
	}
	void setEmail(string e){
		email = e;
	}
	string getEmail(){
		return email;
	}
	void setUnits(int unit){
		units = unit;
	}
	int getUnits(){
		return units;
	}
	int calculateTariff();
};

class NormalCustomer : public Customer
{
    public:
    int calculateTariff()
    {
        return 0;
    }
};
class BrandCustomer : public Customer
{
    public:
    int calculateTariff()
    {
        return 100 + getUnits() * 2;
    }
    
};
class ExecutiveCustomer : public Customer
{
    public:
    int  calculateTariff()
    {
        return getUnits() * 5;
    }
};

int main()
{ 
   string name;
   string email;
   int units;
   int type;
    cout<<"Enter the name:"<<endl;
    cin>>name;
    cout<<"Enter the emailId:"<<endl;
    cin>>email;
    cout<<"Enter the units:"<<endl;
    cin>>units;
    cout<<"Enter customer type:"<<endl;
    cin>>type;
    if(type==1)
    {
        NormalCustomer obj;
        obj.setUnits(units);
        cout << "Calculated Tariff (In US dollars): " << obj.calculateTariff();
    }
    else if (type == 2)
    {
        BrandCustomer obj;
        obj.setUnits(units);
        cout << "Calculated Tariff (In US dollars): " << obj.calculateTariff();
    }
    else if (type == 3)
    {
        ExecutiveCustomer obj;
        obj.setUnits(units);
        cout << "Calculated Tariff (In US dollars): " << obj.calculateTariff();
    }
    
    return 0;
}
