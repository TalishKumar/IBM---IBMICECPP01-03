#include <iostream>
using namespace std;
 
class Product
{
  protected:
    int markedPrice=1000;
    int discount=40;
    public:
        void setMarkedPrice(int mPrice)
        {
            markedPrice=mPrice;
        }
        void setDiscount(int dis)
        {
            discount=dis;
        }
        int getMarkedPrice()
        {
            return markedPrice;
        }
        int getDiscount()
        {
            return discount;
        }
};
 
class Dress : public Product
{
  public:
    char findSize(int chestSize)
    {
        if (chestSize >= 20 && chestSize <= 30)
        {
            return 'S';
        }
        else if (chestSize >= 31 && chestSize <= 40)
        {
            return 'M';
        }
        else if (chestSize > 40)
        {
            return 'L';
        }
    }

};
 class Shirt : public Dress
 {
  public:
     int calculatePrice(char chestSize)
     {
         if (chestSize == 'S')
         {
             markedPrice = markedPrice - (markedPrice * discount) / 100;
             return markedPrice;
         }
         else if (chestSize == 'M')
         {
             markedPrice = markedPrice - (markedPrice * discount) / 100;
             markedPrice+=500;
             return markedPrice;
         }
         else if (chestSize == 'L')
         {
             markedPrice = markedPrice - (markedPrice * discount) / 100;
             markedPrice+=1000;
             return markedPrice;
         }
     }
};

// main function
int main()
{
    int size;
    cout<<"Enter the chest size : ";
    cin>>size;
   
    Shirt s;
    char sizeupdate = s.findSize(size);
    cout << "Dress Size: " << sizeupdate << '\n';
    cout << "Price (in $): " << s.calculatePrice(sizeupdate);
   
    return 0;
}
