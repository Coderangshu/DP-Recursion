// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recursion(int arr[], int i, int j){
        if(i>=j) return 0;
        else{
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                int temp = recursion(arr,i,k)+recursion(arr,k+1,j)+arr[i]*arr[k+1]*arr[j+1];
                ans = (temp<ans)?temp:ans;
            }
            return ans;
        }
    }
    
    int memo[101][101];
    int memoization(int arr[], int i, int j){
        if(i>=j) return memo[i][j] = 0;
        else if(memo[i][j]!=-1) return memo[i][j];
        else{
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                int temp = memoization(arr,i,k)+memoization(arr,k+1,j)+arr[i]*arr[k+1]*arr[j+1];
                ans = (temp<ans)?temp:ans;
            }
            return memo[i][j] = ans;
        }
    }
    
    int topDown(int arr[], int N){
		// Uncomment the code lines below to print the parameters and the dp table.

		// Here as consecutive numbers denote the dimensions of an array
		// therefore total possible N-1 matrices, so the dp array is
		// taken with dimensions N-1.
        int dp[N-1][N-1];
        for(int i=0;i<N-1;i++) for(int j=0;j<N-1;j++) if(i>=j) dp[i][j] = 0;
		// Here to maintain the same distance between i and j so as to run 
		// the k in a loop from i to j and find the minimum, a length loop
		// is taken where length(l) varies from 1 to N-1.
        for(int l=1;l<N;l++){
			// Here i loop runs from 0 to N-length-1, here -1 is done so that
			// in case of j which is at its minimum i+1, does not go out of 
			// bound.
            for(int i=0;i<N-l-1;i++){
				// j is taken as i+l in which the k runs in a loop from i to j
				// to check for all possible partitions and find the minimum
				// cost to scalar multiply the chain of matrices.
                int j = i+l;
//                 cout<<"indices "<<i<<" "<<j<<endl;
                int ans = INT_MAX;
                for(int k=i;k<j;k++){
                    int temp = dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1];
                    ans = min(temp,ans);
//                     cout<<dp[i][k]<<" "<<dp[k+1][j]<<" "<<temp<<" "<<ans<<endl;
                }
                dp[i][j] = ans;
            }
        }
//         for(int i=0;i<N-1;i++){
//             for(int j=0;j<N-1;j++) cout<<dp[i][j]<<'\t';
//             cout<<endl;
//         }
        return dp[0][N-2];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
		// Uncomment each line to get the result using each
		// described methods.

        // return recursion(arr,0,N-2);
        // memset(memo,-1,sizeof(memo));
        // return memoization(arr,0,N-2);
        return topDown(arr,N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
