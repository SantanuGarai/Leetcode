#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void BFS(vector<int> adj[], int N, int T,int C) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[0] = 0;
	q.push(0); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
    int ans = C;
    int time = T;
	for(int i=1;i<dist[N-1];i++){
         
         if(time<ans){
           while(time<ans){
              time +=T;
           }
           ans += time-ans;
         }
         ans +=C;
    }
    cout<<ans;
	
} 
int main()
{
   int N,M,T,C;
   cin>>N>>M>>T>>C;
   vector<int> adj[N+1];
   for(int i=0;i<M;i++){
       int u,v;
       cin>>u>>v;
       adj[u-1].push_back(v-1);
       adj[v-1].push_back(u-1);
   }
   /*  BFS Traversal OUTPUT */
   //cout<<"BFS Traversal OUTPUT"<<endl;
   
   BFS(adj,N,T,C);
   return 0;
}


5 5 3 5
1 2
1 3
2 4
1 4 
1 5
