#include<bits/stdc++.h>
using namespace std;

//Function to check if there is a subset of 'arr' with a sum equal to 'target'
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) 
{
    if (target == 0) 
    return true; // Found a subset with the required sum

    if(ind == 0)
    return arr[0] == target;

    if (dp[ind][target] != -1)
    return dp[ind][target];

    bool notTaken = subsetSumUtil(ind-1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
    taken = subsetSumUtil(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

bool subsetSumToK(int n, int k, vector<int>& arr) {
    // Initialize a 2D DP array for memoization
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    // Call the recursive subsetSumUtil function
    return subsetSumUtil(n-1, k, arr, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}
