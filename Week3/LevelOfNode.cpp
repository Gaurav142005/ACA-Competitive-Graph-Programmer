//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    if(X >= V)
	        return -1;
	    if(X == 0)
	        return 0;
	    queue <int>q;
	    queue <int>temp;
	    int vis[V] = {0};
	    int level = 0;
	    vis[0] = 1;
	    q.push(0);
	    int flag = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        if(node == X){
	            flag = 1;
	            break;
	        }
	        for(auto v: adj[node]){
	            if(!vis[v]){
	                temp.push(v);
	                vis[v] = 1;
	            }
	        }
	        if(q.empty()){
    	        level++;
    	        q = temp;
    	        temp = queue<int>();
	        }
	    }
	    if(flag ==  1)
    	    return level;
    	else
    	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
