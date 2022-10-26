#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // method to compute maximum subarray sum
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = -1e9, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};
// driver code 
int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = s.maxSubArray(nums);
    cout << ans << endl;
    return 0;
}
