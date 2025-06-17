#include<bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of 'arr' with a sum equal to 'target'
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] =curr[0]= true; 

    for(int target = 1; target <= k; target++) {
        bool notTaken = prev[target];

        bool taken = false;
        if (arr[ind] <= target) {
            taken = prev[target - arr[ind]];
        }
        curr[target] = notTaken || taken;
    }
    prev = curr;

    
}
