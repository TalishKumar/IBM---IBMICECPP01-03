#include <iostream>
using namespace std;

class Train
{
    private:
        long passengerPhone;
        string passengerName;
        char gender;
        int age;
        double ticketPrice;
    public:
        long getPassengerPhone()
        {
            return passengerPhone;
        }
        string getPassengerName()
        {
            return passengerName;
        }
        char getGender()
        {
            return gender;
        }
        int getAge()
        {
            return age;
        }
        double getTicketPrice()
        {
            return ticketPrice;
        }
        void setPassengerPhone(long pPhone)
        {
            passengerPhone = pPhone;
        }
        void setPassengerName(string pName)
        {
            passengerName = pName;
        }
        void setGender(char pGender)
        {
            gender = pGender;
        }
        void setAge(int pAge)
        {
            age = pAge;
        }
        void setTicketPrice(double tPrice)
        {
            ticketPrice = tPrice;
        }
        
        double calculateAmount()
        {
            if (gender == 'F')
            {
                ticketPrice = ticketPrice * 0.90;
                return ticketPrice;
            }
            else if (age < 16)
            {
                ticketPrice = ticketPrice/2;
                return ticketPrice;
            }
            else if (age >= 60)
            {
                ticketPrice = ticketPrice * 0.75;
                return ticketPrice;
            }
            else
            {
                return ticketPrice;
            }
        }
};

int main()
{
    long phone;
    string name;
    char gender;
    int age;
    double ticketPrice;
    cout<<"Enter the Passenger phone no : \n";
    cin>>phone;
    cout<<"Enter the Passenger name : \n";
    cin>>name;
    cout<<"Enter the Passenger Age : \n";
    cin>>age;
    cout<<"Enter the Gender(M/F): \n";
    cin>>gender;
    cout<<"Enter the Ticket Price: \n";
    cin>>ticketPrice;
    
    Train t;
    t.setPassengerPhone(phone);
    t.setPassengerName(name);
    t.setGender(gender);
    t.setAge(age);
    t.setTicketPrice(ticketPrice);
    cout << "Total Amount(In dollars): " << t.calculateAmount();
    
    return 0;
}
