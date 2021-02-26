// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int memo[10002][102];            // The array size causes problem

     int recursion(int N, int arr[], int sum){
         if(sum==0) return 1;
         if(N==0) return 0;
         if(arr[N-1]>sum) return recursion(N-1,arr,sum);
         else return (recursion(N-1,arr,sum-arr[N-1]) + recursion(N-1,arr,sum));
     }

     int memoization(int N, int arr[], int sum){
         if(sum==0) return memo[sum][N] = 1;
         if(N==0) return memo[sum][N] = 0;
         if(memo[sum][N]!= -1) return memo[sum][N];
         if(arr[N-1]>sum) return memo[sum][N] = memoization(N-1,arr,sum);
         else return memo[sum][N] = (memoization(N-1,arr,sum-arr[N-1]) + memoization(N-1,arr,sum));
     }

    int bottomUp(int N, int arr[], int sum){
        int dp[sum+1][N+1];
        for(int i=0;i<sum+1;i++){
            for(int j=0;j<N+1;j++){
                if(i==0) dp[i][j] = 1;
                else if(j==0) dp[i][j] = 0;
                else if(arr[j-1]>i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = (dp[i-arr[j-1]][j-1] + dp[i][j-1]);
            }
        }
        return dp[sum][N];
    }
    
     int countNoOfSubsetwGivenSum(int N, int arr[], int sum)
{
          // code here
          // Recursion
        //   return recursion(N,arr,sum);
          // Memoization 
            // memset(memo,-1,sizeof(memo));
            // return memoization(N,arr,sum);
          // bottomUp
         return bottomUp(N,arr,sum);
     }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, sum;
        cin>>N>>sum;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.countNoOfSubsetwGivenSum(N,arr,sum)<<endl;
    }
    return 0;
}  // } Driver Code Ends

