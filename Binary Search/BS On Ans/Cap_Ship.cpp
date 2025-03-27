class Solution {
public:


bool check(int capacity, int days, vector<int>& weights) {
    int n = weights.size(); //no of packages
    int c = capacity; // remaining capacity of the ship
    int dayCount = 1; //Start with the first day
    for(int i=0; i<n; i++) {
        if(c >= weights[i]) {
            c = c- weights[i]; //Load package on the ship
        }else {
            dayCount++;
            c = capacity;
            c -= weights[i];
        }

    }
    if(dayCount <= days) {
        return true;
    }
    return false;
}


int shipWithinDays(vector<int>& weights, int days) {

    int n = weights.size();

    //Find the max weight and sum of all weights
    int sum = 0, max = weights[0];
    for(int i=0; i <n; i++) {
        sum += weights[i];
        if(weights[i]>max) 
          max = weights[i];
    }

    //Applying Binary Search
    int lo = max, hi = sum;
    int mincapacity = sum;
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(check(mid, days, weights)) {
            mincapacity = mid;
            hi = mid-1;
        } else {
            lo = mid + 1;
        }
    }
    return mincapacity;
}
};