#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
            + knapSack(W - wt[n - 1],
                wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    cout << "Enter the number of items: ";
    int n{};
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input";
    }
    else
    {
        int val[n]{0};
        int wt[n]{0};

        for (int i{ 0 }; i < n; ++i)
        {
            cin >> wt[i];
            cin >> val[i];
        }
        
        cout << "\nEnter the size of knapsack: ";
        int W{};
        cin >> W;
        
        cout << "The total value is: " << knapSack(W, wt, val, n);
    }

    return 0;
}
