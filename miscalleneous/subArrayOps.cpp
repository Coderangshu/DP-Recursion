#include <bits/stdc++.h>
using namespace std;

int minEl(vector<int> arr, int i, int j){
	int ans = INT_MAX;
	for(int k=i;k<=j;k++) if(arr[k]<ans) ans = arr[k];
	return ans;
}

int recursion(vector<int> arr, int i, int j){
	if(i>j) return 0;
	if(i==j) return arr[i]*arr[i];
	else{
		int sum = 0;
		for(int k=i;k<=j;k++) sum+=arr[k];
		int ans = sum*minEl(arr,i,j);
		int temp = max(recursion(arr,i+1,j-1),max(recursion(arr,i+1,j),recursion(arr,i,j-1)));
		return max(ans,temp);
	}
}

int memo[1001][1001];
int memoization(vector<int> arr, int i, int j){
    if(i>j) return memo[i][j] = 0;
    if(i==j) return memo[i][j] = arr[i]*arr[i];
    if(memo[i][j]!=-1) return memo[i][j];
	else{
		int sum = 0;
		for(int k=i;k<=j;k++) sum+=arr[k];
		int ans = sum*minEl(arr,i,j);
		int temp = max(memoization(arr,i+1,j-1),max(memoization(arr,i+1,j),memoization(arr,i,j-1)));
	    return memo[i][j] = max(ans,temp);	
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int e;
		cin>>e;
		arr.push_back(e);
	}
	int ans;
	// ans = recursion(arr,0,n-1);
	memset(memo,-1,sizeof(memo));
	ans = memoization(arr,0,n-1);
	cout<<ans<<endl;
	return 0;
}
