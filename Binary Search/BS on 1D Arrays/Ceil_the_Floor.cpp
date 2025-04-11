//Problem Link: https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

class Solution {
    public:
       
       int findFloor(int x, vector<int> &arr) {
        int l=0; r = arr.size()-1;
        int floor = -1;

        while(l<=r) {
            int mid = l + (r-l)/2;

            if(arr[mid] <= x) {
                floor = arr[mid];
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }
        return floor;
       }

       int findCeil(int x, vector<int> &arr) {
        int l = 0, r = arr.size()-1;
        int ceil = -1;

        while(l<=r) {
            int mid = l + (r-l)/2;

            if (arr[mid]>=x){
                ceil = arr[mid];
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }
        return ceil;
       }
       
       vector<int> getFloorAndCeil(int x, vector<int> &arr) {

        // code here 
        // int floor = -1, ceil = -1;

        // int maxFloor = INT_MIN, minCeil = INT_MAX;

        // for(int num : arr) {
        //     if (num <= x && num >= maxFloor) {
        //         maxFloor = num;
        //         floor = num;
        //     }

        //     if(num >= x && num < minCeil) {
        //         minCeil = num;
        //         ceil = num;
        //     }
        // }

        sort(arr.begin(), arr.end());
        int floor = findFloor(x, arr);
        int ceil = findCeil(x, arr);
        return {floor, ceil};
    }
};