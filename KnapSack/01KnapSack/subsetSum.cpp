#include <bits/stdc++.h>
using namespace std;

void prntArr(int arr[], int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int DP(int arr[],int n){
// COMMENT BELOW LINE AND UNCOMMENT NEXT LINE AND PUT SUM TO CHECK FOR
  int sum = accumulate(arr,arr+n,0);
  // int sum = YOUR_CHOICE;
  int dp[n+1][sum+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(j==0) dp[i][j] = 1;
      else if(i==0) dp[i][j] = 0;
      else if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
      else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
    }
  }
  // UNCOMMENT BELOW LINES TO VIEW THE COMPLETE DP ARRAY
  // cout<<"  ";
  // for(int j=0;j<sum+1;j++){
  //   cout<<j<<" ";
  // }
  // cout<<endl;
  // for(int i=0;i<n+1;i++){
  //   cout<<i<<" ";
  //   for(int j=0;j<sum+1;j++){
  //     if(j>9) cout<<" ";
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  return dp[n][sum];
}

int main(){
  int arr[] = {10,9,10,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  // UNCOMMENT BELOW LINE TO VIEW THE COMPLETE DP ARRAY
  // prntArr(arr,n);

  cout<<DP(arr,n);
  return 0;
}
