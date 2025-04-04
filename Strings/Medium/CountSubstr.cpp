// Problem link: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include<string>
using namespace std;

// Brute Force Approach
// T.C : O(n^3) , S.C : O(n)
// int countSubstrings(string s, int k) {
//     int n = s.length(); // Length of the input string
//     int ans = 0; // Initialize the answer to 0

//     // Iterate over all possible start indices
//     for (int i = 0; i < n; i++) {
        
//         // Iterate over all possible end indices starting from i
//         for (int j = i; j < n; j++) {
//             // Initialize a set to store unique characters in the current substring
//             unordered_set<char> st;
//             //Traverse the substring from index i to j
//             for (int m = i; m<=j;m++) {
//                 // Insert the character into the set
//                 st.insert(s[m]);
//             }
//             // If the size of the set is equal to k, increment the answer
//             if (st.size() == k) {
//                 ans++;
//             }
//         }
//     }
//     return ans; // Return the final count of substrings with exactly k unique characters
// }

// Better Solution
// T.C : O(n^2) , S.C : O(n)
// int countSubstrings(string s, int k) {
//     int n = s.length(); // Length of the input string
//     int count = 0; // Initialize the answer to 0

//     // Iterate over all possible start indices
//     for (int i = 0; i < n; i++) {
//         unordered_map<char, int> freq;
//         int distinct_count = 0; 

//         //Expand the window by increasing the end index
//         for(int j = i; j < n; j++) {
//             if (freq[s[j]] == 0) distinct_count++;
//             freq[s[j]]++;

//             if (distinct_count == k) count++; // Count valid substrings
//             if (distinct_count > k) break; // Stop early if more than k distinct characters
//         }
//     }
//     return count; 
// }
int atMostK(string &s, int k) {
    if (k == 0) return 0;
    
    unordered_map<char, int> freq;
    int left = 0, count = 0;
    
    //Expand the right pointer to include characters
    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;
        
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

//Optimal Approach 
// T.C : O(n) , S.C : O(n)
int countSubstrings(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1); 
}

int main() {
    string s;
    int k;
    cout << "Enter the string: ";
    cin >> s; // Read the input string
    cout << "Enter the value of k: ";
    cin >> k; // Read the value of k
    cout << "Count of substrings with exactly " << k << " unique characters: " << countSubstrings(s, k) << endl; // Call the function and print the result
    return 0;
}