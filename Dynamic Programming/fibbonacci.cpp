#include<bits/stdc++.h>
using namespace std;

//Memoization
//T.C--O(N)
//S.C -- O(N{Recursion Stack Space})+O(N{Array})
// int f(int n, vector<int> &dp) {
//     if(n<=1)
//     return n;

//     if(dp[n] != -1)
//     return dp[n];

//     return dp[n] = f(n-1, dp) + f(n-2, dp);
// }

// int main() {
//     int n ;
//     cin >>n;
//     vector<int> dp(n+1, -1);
//     cout << f(n, dp);
//     return 0;
// }

//Tabulation App
//T.C--O(N)...S.C--O(N)
// int main() {
//     int n = 5;
//     vector<int> dp(n+1, -1);

//     dp[0] = 0;
//     dp[1] = 1;

//     for(int i=2; i <=n; i++) {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     cout<<dp[n];
//     return 0;
// }

//Space Optimization
int main() {
    int n = 5;

    int prev2 = 0;
    int prev = 1;

    for(int i=2;i<=n;i++) {//O(N) simple iterative loop
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    } //S.C -- O(1) no xtra space used 
    cout<<prev;
    return 0;
}

//Problem Link : https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

class Solution {
    public:
      const int MOD = 1e9 + 7;
    
      long long f(int n, vector<long long int> &dp) {
      if(n<=1)
      return n;
  
      if(dp[n] != -1)
      return dp[n];
  
      return dp[n] = (f(n-1, dp) + f(n-2, dp)) % MOD;
  }
      long long int topDown(int n) {
          // code here
          vector<long long int> dp(n+1, -1);
          return  f(n, dp);
      }
      long long int bottomUp(int n) {
          
               if (n == 0) return 0;
               if (n == 1) return 1;
          // code here
               vector<long long> dp(n+1);
  
              dp[0] = 0;
              dp[1] = 1;
  
              for(int i=2; i <=n; i++) {
                  dp[i] = (dp[i-1] + dp[i-2])%MOD;
              }
              return dp[n];
          
      
      
      }
  };