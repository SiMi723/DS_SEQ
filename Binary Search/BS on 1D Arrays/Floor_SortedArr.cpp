//Problem link: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

//Implement Lower Bound
#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int k) {
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] <= k) {
            ans = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return ans;

}