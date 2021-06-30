#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int n,vector<int> adj[]){
    vector<int> ans;
    vector<int> vis(n+1,0);
    
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for(auto it : adj[node]){
                    if(vis[it]==0){
                        vis[it] =1;
                        q.push(it);
                        
                    }
            
                }
            }
        }
    }
    return ans;
}
void dfs(int node,vector<int> &vis, vector<int> adj[], vector<int> &ans){
    ans.push_back(node);
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            dfs(it,vis,adj,ans);
        }
    }
}
vector<int> dfsOfGraph(int v,vector<int> adj[]){
    
    vector<int> ans;
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(vis[i]==0){
           dfs(i,vis,adj,ans);
        }
    return ans;
   }
}

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int> adj[n+1];
   for(int i=0;i<m;i++){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   /*  BFS Traversal OUTPUT */
   cout<<"BFS Traversal OUTPUT"<<endl;
   vector<int> ans = bfs(n,adj);
   for(auto i : ans){
       cout<<i<<endl;
   }
   /* DFS Traversal OUTPUT */
   cout<<"DFS Traversal OUTPUT"<<endl;
   vector<int> ans2 = dfsOfGraph(n,adj);
   for(auto i : ans2){
       cout<<i<<endl;
   }
   
   return 0;
}
