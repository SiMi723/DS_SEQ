#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    //Base case: If target sum is zero, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    //Base case: If the first element is equal to the target sum, we can achieve it by taking that element
    if(arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    //Fill the DP array iteratively
    for(int ind = 1;ind<n;ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTaken = dp[ind-1][target];

            bool taken = false;
            if(arr[ind] <= target) {
                taken = dp[ind-1][target-arr[ind]];
            }

            //Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }
    //Return the result for the full problem
    return dp[n-1][k];
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
