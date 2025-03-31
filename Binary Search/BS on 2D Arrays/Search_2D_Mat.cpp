//Problem link : https://leetcode.com/problems/search-a-2d-matrix/description/
#include<bits/stdc++.h>
using namespace std;

// bool binarySearch(vector<int>& nums, int target) {
//     int n = nums.size();//size of array
//     int low = 0, high = n-1;

//     //Perform the steps:
//     while (low <= high) {
//         //Better Solution
//         //T.C--O(N+logM) // S.C--O(1)
//         int mid = (low + high)/2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid-1;
//     }
//     return false;
// }

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    // traverse the matrix:
    // Brute Force--T.C--O(m*n)
    //             ---S.C--O(1)
    // for (int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if (matrix[i][j] == target) 
    //         return true;
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     if (matrix[i][0] <= target && target <= matrix[i][m-1]) {
    //         return binarySearch(matrix[i], target);
    //     }
    // } 
    //Optimal Solution
    //T.C--O(n*m)
    int low = 0, high = n*m-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        int row = mid/m, col = mid%m;
        if(matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() 
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{0,10,11,12}};
    searchMatrix(matrix, 11) == true ? cout << "true\n" : cout << "false\n";
}