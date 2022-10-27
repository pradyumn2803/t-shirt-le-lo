#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<int> prev(W + 1, 0);

        for (int i = wt[0]; i <= W; i++)
        {
            prev[i] = val[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int w = W; w >= -0; w--)
            {
                int not_take = prev[w];
                int take = -1e8;
                if (wt[ind] <= w)
                    take = val[ind] + prev[w - wt[ind]];

                prev[w] = max(take, not_take);
            }
        }
        return prev[W];
    }
};

// Driver Code Starts.

int main()
{
    // reading number of elements and weight
    int n, w;
    cin >> n >> w;

    int val[n];
    int wt[n];

    // inserting the values
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // inserting the weights
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    Solution ob;
    // calling method knapSack()
    cout << ob.knapSack(w, wt, val, n) << endl;
    return 0;
}
