/**********************************************************************************************
         Number of Operations to Make Network Connected
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming
a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
Any computer can reach any other computer directly or indirectly through the network.
You are given an initial computer network connections. You can extract certain cables between 
two directly connected computers,and place them between any pair of disconnected computers to 
make them directly connected.Return the minimum number of times you need to do this in order 
to make all the computers connected. If it is not possible, return -1.
*/


/*Sol1 is based on DFS.
Compute the dfs and count the number of components while dfs computation.
The final answer will be components-1
*/

    void dfs(int node,vector<vector<int> >&edge_list,vector<int> &vis)
    {
        vis[node] = 1;
        for(auto edge:edge_list[node])
        {
            if(!vis[edge])
                dfs(edge,edge_list,vis);
        }
    }
     int makeConnected(int n, vector<vector<int>>& connections) {
         if(connections.size()<n-1)
             return -1;
         vector<vector<int> >edge_list(n);
         vector<int>vis(n,0);
         for(auto edge:connections)
         {
             edge_list[edge[0]].push_back(edge[1]);
             edge_list[edge[1]].push_back(edge[0]);
         }
         int count = 0;
         for(int i=0;i<n;i++)
         {
             if(!vis[i])
             {
                 dfs(i,edge_list,vis);
                 count++;
             }
         }
         
         return count-1;
     }
/*
Sol2: Is based on using DSU datastructure to compute the total number of components.
Start creating a spanning tree from the edges given.
Towards the end go through the parent arrauy and check how many of the elements
have itself as the parent.(i.e total number of connected components)
The output will be this value -1*/
         
    
    int find(int x,vector<int>&parent)
    {   
          if(parent[x]!=x)
            parent[x] = find(parent[x],parent);
        return parent[x];
    }
    
    void find_union(int x,int y,vector<int> & rank,vector<int>&parent)
    {
        int par1 = find(x,parent);
        int par2 = find(y,parent);
        if(par1==par2)
           return;
        else
        {
            if(rank[par1]>rank[par2])
                parent[par2] = par1;
            else
            {
                parent[par1] = par2;
                if(rank[par1] == rank[par2])
                    rank[par2]++;
            } 
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<int>parent(n);
        for(int i=0;i<n;i++)
            parent[i] = i;
        vector<int>rank(n,0);
        for(auto edge:connections)
        {
            find_union(edge[0],edge[1],rank,parent);
        }
        int un_conn = 0;
      for(int i=0;i<n;i++)
        {
          if(parent[i]==i)
               un_conn++;
        }
        return un_conn-1;
        
       
    }
    
