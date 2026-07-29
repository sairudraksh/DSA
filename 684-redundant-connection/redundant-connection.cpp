class Solution {
public:
    vector<vector<int>>graph;
    void formGraph(vector<vector<int>>&edges){
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
    bool find(int curr,int parent,int vec1,int vec2,vector<int>&visited){
        visited[curr]=1;
        for(int i=0;i<graph[curr].size();i++){
            int neighbour=graph[curr][i];

            if((curr==vec1 && neighbour==vec2) || (curr==vec2 && neighbour==vec1)) continue;

            if(visited[neighbour]==0){
                bool a=find(neighbour,curr,vec1,vec2,visited);
                if(a==true) return true;
            }
            else if(neighbour!=parent){
                return true;
            }
        }
        return false;
    }
    bool detectCycle(int ver1,int ver2){
        vector<int>visited;
        visited.resize(graph.size()+1,0);

        for(int i=0;i<graph.size();i++){
            if(visited[i]==0){
                bool a=find(i,-1,ver1,ver2,visited);
                if(a==true) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int maximum=0;

        for(int i=0;i<edges.size();i++){
            maximum=max(maximum,edges[i][0]);
            maximum=max(maximum,edges[i][1]);
        }
        graph.resize(maximum+1,vector<int>());
        formGraph(edges);
        for(int i=edges.size()-1;i>=0;i--){
            bool a=detectCycle(edges[i][0],edges[i][1]);
            if(a==false) return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};