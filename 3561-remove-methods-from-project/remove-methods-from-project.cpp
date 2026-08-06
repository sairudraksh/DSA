class Solution {
public:
    vector<int>v;
    vector<vector<int>>graph;
    vector<vector<int>>graph2;
    void form_graph(vector<vector<int>>&invocations){
        int n=invocations.size();
        for(int i=0;i<n;i++){
            graph[invocations[i][0]].push_back(invocations[i][1]);
            graph2[invocations[i][1]].push_back(invocations[i][0]);
        }
    }
    vector<int>visited;
    void dfs(int k,vector<int>&v){
        visited[k]=1;
        for(int i=0;i<graph[k].size();i++){
            if(visited[graph[k][i]]==1) continue;
            v.push_back(graph[k][i]);
            dfs(graph[k][i],v);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        visited.resize(n+1,0);
        graph.resize(n,vector<int>());
        graph2.resize(n,vector<int>());
        form_graph(invocations);
        vector<int>v;
        v.push_back(k);
        dfs(k,v);
        unordered_map<int,int>map;
        for(int i=0;i<v.size();i++){
            map[v[i]]++;
        }
        vector<int>original;
        for(int i=0;i<n;i++){
            original.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<graph2[v[i]].size();j++){
                if(map[graph2[v[i]][j]]==0){
                    return original;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(map.find(i)==map.end()) ans.push_back(i);
        }
        return ans;

    }
};