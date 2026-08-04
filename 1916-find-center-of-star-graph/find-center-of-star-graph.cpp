class Solution {
public:
    vector<vector<int>>graph;
    int n;
    int m;
    int findCenter(vector<vector<int>>& edges) {
        int maximum=0;
        n=edges.size();
        m=edges[0].size();
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[0].size();j++){
                maximum=max(maximum,edges[i][j]);
            }
        }
        graph.resize(maximum+1,vector<int>());
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        int result=0;
        for(int i=0;i<graph.size();i++){
            if(ans<graph[i].size()){
                ans=graph[i].size();
                result=i;
            }
        }
        return result;
    }
};