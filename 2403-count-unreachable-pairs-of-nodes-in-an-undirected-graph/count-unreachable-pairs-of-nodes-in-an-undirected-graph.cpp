class Solution {
public:
    vector<int>visited;
    long long bfs(int j,vector<vector<int>>&graph){
        long long ans=1;


        queue<int>q;

        for(int l=0;l<graph[j].size();l++){
            q.push(graph[j][l]);
            visited[graph[j][l]]=1;
        }

        while(q.size()>0){
            int i=q.front();
            q.pop();
            ans++;

            for(int l=0;l<graph[i].size();l++){
                if(visited[graph[i][l]]==0){
                    visited[graph[i][l]]=1;
                    q.push({graph[i][l]});
                }
            }
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph;
        graph.resize(n,vector<int>());

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        visited.resize(n+1,0);
        long long ans=0;
        long long total=n;
        for(int i=0;i<graph.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                long long a=bfs(i,graph);
                total-=a;
                ans+=total*a*1LL;
            }
        }        
        return ans;

    }
};