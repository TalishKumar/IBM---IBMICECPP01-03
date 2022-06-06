#include <iostream>
#include<string>
using namespace std;

int calculateTotalReturns(int amount,int interestRate)
{
    return amount + ((amount * interestRate) / 100);
}
int calculateTotalReturns(int depositAmount ,int term,int returnRate)
{
    int totalAmount {depositAmount * 12 * term};
    return totalAmount + ((totalAmount * returnRate) / 100);
}
int calculateTotalReturns(string stockName,double price,int number)
{
    return price * number;
}

int main()   //DO NOT change the 'main' signature
{
    string stockName;
    int numbers,amount,rate,depositAmount,term,rRate;
    double sharePrice;
    cout<<"FD:"<<endl;
    cout<<"Enter Amount : "<<endl;
    cin>>amount;
    cout<<"Enter interest rate : "<<endl;
    cin>>rate;
    cout << "Total Returns (In US dollars): " << calculateTotalReturns(amount, rate) << '\n';
    cout<<"Mutual Funds :"<<endl;
    cout<<"Enter amount for SIP: "<<endl;
    cin>>depositAmount;
    cout<<"Enter term : "<<endl;
    cin>>term;
    cout<<"Enter return rate : "<<endl;
    cin>>rRate;
    cout << "Total Returns (In US dollars): " << calculateTotalReturns(depositAmount, term, rRate) << '\n';
    cout<<"Stock:"<<endl;
    cout<<"Enter stock Name : "<<endl;
    cin>>stockName;
    cout<<"Enter stock price : "<<endl;
    cin>>sharePrice;
    cout<<"Enter number of stocks : "<<endl;
    cin>>numbers;
    cout <<"Total Returns (In US dollars): " << calculateTotalReturns(stockName, sharePrice, numbers);
    
    return 0;
}
