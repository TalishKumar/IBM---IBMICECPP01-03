#include <iostream>
using namespace std;

string voltageTracker(float v1, float v2, float v3)
{
    if ((v1 <= 250) && (v2 <= 250) && (v3 <= 250))
    {
        return "Safe voltage limit";
    }
    else if ((v1 >= 251 && v1 <= 275) || (v2 >= 251 && v2 <= 275) || (v3 >= 251 && v3 <= 275))
    {
        if (v1 <= 275 && v2 <= 275 && v3 <= 275)
        {
            return "Warning voltage limit";   
        }
        else
        {
            throw "Danger Detected Over Voltage";
        }
    }
}

int main()
{
    float v1;
    float v2;
    float v3;
    cout << "Enter Line Voltage value" << endl;
    cin >> v1;
    cin >> v2;
    cin >> v3;

    try
    {
        cout << voltageTracker(v1, v2, v3);

    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }

    return 0;
}
