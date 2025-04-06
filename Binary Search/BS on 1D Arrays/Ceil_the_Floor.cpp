//Problem Link: https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

class Solution {
    public:
       vector<int> getFloorAndCeil(int x, vector<int> &arr) {

        // code here 
        int floor = -1, ceil = -1;

        int maxFloor = INT_MIN, minCeil = INT_MAX;

        for(int num : arr) {
            if (num <= x && num >= maxFloor) {
                maxFloor = num;
                floor = num;
            }

            if(num >= x && num < minCeil) {
                minCeil = num;
                ceil = num;
            }
        }

        return {floor, ceil};
    }
};