//Problem Link : https://leetcode.com/problems/median-of-two-sorted-arrays/

//T.C--O(n1+n2)
//S.C--O(n1+n2)
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> nums3;
            int n1 = nums1.size();
            int n2 = nums2.size();
            int i=0, j=0;
            while(i<n1 && j < n2) {
                if(nums1[i]<nums2[j]){
                    nums3.push_back(nums1[i++]);
                } else {
                    nums3.push_back(nums2[j++]);
                }
            }
            while(i<n1)
            nums3.push_back(nums1[i++]);
            while(j<n2)
            nums3.push_back(nums2[j++]);
            int n = n1+n2;
            if(n%2==1) {
                return nums3[n/2];
            }
            return (nums3[n/2]+nums3[n/2-1])/2.0;
            
        }
    };


    //Better Solution
    //T.C--O(n1+n2)
    //S.C--O(1)

    class Solution {
        public:
            double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
                int n1 = nums1.size(), n2 = nums2.size();
            int n = n1 + n2; //total size
            //required indices:
            int ind2 = n / 2;
            int ind1 = ind2 - 1;
            int cnt = 0;
            int ind1el = -1, ind2el = -1;
        
            //apply the merge step:
            int i = 0, j = 0;
            while (i < n1 && j < n2) {
                if (nums1[i] < nums2[j]) {
                    if (cnt == ind1) ind1el = nums1[i];
                    if (cnt == ind2) ind2el = nums1[i];
                    cnt++;
                    i++;
                }
                else {
                    if (cnt == ind1) ind1el = nums2[j];
                    if (cnt == ind2) ind2el = nums2[j];
                    cnt++;
                    j++;
                }
            }
        
            //copy the left-out elements:
            while (i < n1) {
                if (cnt == ind1) ind1el = nums1[i];
                if (cnt == ind2) ind2el = nums1[i];
                cnt++;
                i++;
            }
            while (j < n2) {
                if (cnt == ind1) ind1el = nums2[j];
                if (cnt == ind2) ind2el = nums2[j];
                cnt++;
                j++;
            }
        
            //Find the median:
            if (n % 2 == 1) {
                return (double)ind2el;
            }
        
            return (double)((double)(ind1el + ind2el)) / 2.0;
        
                
            }
        };


//Optimal Solution
//T.C--O(log(min(n1,n2)))
//S.C--O(1)
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
            int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)
        return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1)/2;
        int n = n1 + n2;
        while(low<=high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left-mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1) {
              if(n % 2 == 1) return max(l1,l2);
              return ((double)(max(l1,l2)+min(r1, r2)))/2.0;
            }
            else if(l1>l2)
            high = mid1 - 1;
            else 
            low = mid1 + 1;
        }
        return 0; 
    
            
        }
    };