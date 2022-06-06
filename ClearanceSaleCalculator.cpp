//IMPLEMENT CLASS IN A SEPERATE FILE
#include<iostream>
using namespace std;
class Product
{
private:
    int productId;
    string productName;
    double quantity;
    double unitPrice;
public:
    Product() {}
    Product(int productId, string productName, double quantity, double unitPrice)
    {
        setProductId(productId);
        setProductName(productName);
        setQuantity(quantity);
        setUnitPrice(unitPrice);
    }
    friend void setDiscount(Product &product, double discount);
    double calculateBillAmount()
    {
        return quantity * unitPrice;
    }
    void setProductId(int productId)
    {
        this->productId = productId;
    }
    void setProductName(string productName)
    {
        this->productName = productName;
    }
    void setQuantity(double quantity)
    {
        this->quantity = quantity;
    }
    void setUnitPrice(double unitPrice)
    {
        this->unitPrice = unitPrice;
    }
    int getProductId()
    {
        return productId;
    }
    string getProductName()
    {
        return productName;
    }
    double getQuantity()
    {
        return quantity;
    }
    double getUnitPrice()
    {
        return unitPrice;
    }
};

//IMPLEMENT METHOD 'setDiscount' and 'main' IN A SEPERATE FILE
#include<iostream>
#include "Product.cpp"
using namespace std;

void setDiscount(Product &product, double discount)
{
    double newUnitPrice = product.unitPrice * (discount / 100);
    product.unitPrice = product.unitPrice - newUnitPrice;
}

int main()
{
    int productId;
    string productName;
    double quantity, unitPrice, discount;
    cout << "Enter the product Id" << endl;
    cin >> productId;
    cout << "Enter the product Name" << endl;
    cin >> productName;
    cout << "Enter the quantity in kgs" << endl;
    cin >> quantity;
    cout << "Enter the unit price per kg (in US Dollars)" << endl;
    cin >> unitPrice;
    Product p(productId, productName, quantity, unitPrice);
    cout << "Enter the discount percentage" << endl;
    cin >> discount;
    setDiscount(p, discount);
    cout << "After discount, bill amount of Product id " << p.getProductId() << " is " << p.calculateBillAmount() << " US Dollars";

    return 0;
}
