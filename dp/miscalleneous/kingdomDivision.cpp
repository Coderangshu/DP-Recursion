// Question https://www.hackerrank.com/challenges/kingdom-division/problem
#include<bits/stdc++.h>
#define MOD 1000000007
#define llint long long int
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)
using namespace std;
 
vector<int> graph[100001];
llint dp[100001][2][2],N,u,v,parent[100001];
bool visited[100001];
 
void addEdge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
 
void DFS(int node){
	visited[node] = true;
	for(int i=0;i<graph[node].size();i++){
		if(!visited[graph[node][i]]){
			parent[graph[node][i]] = node;
			DFS(graph[node][i]);
		}
	}
	return;
}
 
bool isLeaf(int node){
    bool ans = true;
    for(int i=0;i<graph[node].size();i++) if(graph[node][i]!=parent[node])
        ans = false;
    return ans;
}

llint memoization(int root, int color, int streak){
    if(dp[root][color][streak]!=-1) return dp[root][color][streak];
    if(isLeaf(root)){
        // streak = 0 means parent node and current node have different color
        if(streak==0) return dp[root][color][streak] = 0;
        // streak = 1 means parent node and current node have same color
        if(streak==1) return dp[root][color][streak] = 1;
    }
    llint ans=1,valid=0,invalid=1;
    for(int i=0;i<graph[root].size();i++){
        int node = graph[root][i];
        if(node!=parent[root]){
            valid = 0;
            llint not_same = 0,same = 0;
            // not_same contains the number of configurations wherein
            // the current node has different color than its parent node
            not_same=(dp[node][!color][0]==-1)?
                memoization(node,!color,0):dp[node][!color][0];
            // same contains the number of configurations wherein the
            // current node has same color as its parent node 
            same=(dp[node][color][1]==-1)?
                memoization(node,color,1):dp[node][color][1];
            valid+=same+not_same;
            invalid=(invalid*not_same)%MOD;
            ans=(ans*valid)%MOD;
        }
    }
    if(streak==0) ans = (ans-invalid+MOD)%MOD;
    return dp[root][color][streak] = ans;
} 

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>N;
   for(int i=1;i<N;i++)
   {
       cin>>u>>v;
       addEdge(u,v);
   }
   memset(dp,-1,sizeof(dp));
   DFS(1);
   llint ans=(memoization(1,0,0)*2)%MOD;
   cout<<ans<<endl;
   return 0;
}
