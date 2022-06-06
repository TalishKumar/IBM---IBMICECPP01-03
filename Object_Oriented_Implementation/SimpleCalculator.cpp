#include<iostream>
using namespace std;

template <class T, class U>
class Calculator
{
private:
    T x;
    U y;
public:
    Calculator(T x, U y)
    {
        if (x > y)
        {
            this->x = x;
            this->y = y;
        }
        else
        {
            this->y = x;
            this->x = y;
        }
    }
    U add()
    {
        return x + y;
    }
    U multiply()
    {
        return x * y;
    }
    U subtract()
    {
        return x - y;
    }
    U divide()
    {
        return x / y;
    }

    void displayResult()
    {
        cout << "Numbers are: " << x << " and " << y << '\n';
        cout << "Addition is: " << add() << '\n';
        cout << "Subtraction is: " << subtract() << '\n';
        cout << "Product is: " << multiply() << '\n';
        cout << "Division is: " << divide() << '\n';
    }
};

int main()
{
    cout << "Int results: \n";
    Calculator<int, int> first(1, 2);
    first.displayResult();

    cout << "Float results: \n";
    Calculator<float, float> second(2.4, 1.2);
    second.displayResult();

    cout << "Combination of Int Float results: \n";
    Calculator<int, float> third(2, 1.2);
    third.displayResult();

    return 0;
}
