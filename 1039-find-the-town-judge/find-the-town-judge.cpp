class Solution {
public:
    vector<vector<int>>graph1;
    vector<vector<int>>graph2;
    int findJudge(int n, vector<vector<int>>& trust) {
        int maximum=0;
        if(n==1) return 1;
        for(int i=0;i<trust.size();i++){
            maximum=max(maximum,trust[i][0]);
            maximum=max(maximum,trust[i][1]);
        }
        graph1.resize(maximum,vector<int>());
        graph2.resize(maximum,vector<int>());
        for(int i=0;i<trust.size();i++){
            graph1[trust[i][1]-1].push_back(trust[i][0]-1);
            graph2[trust[i][0]-1].push_back(trust[i][1]-1);
        }
        for(int i=0;i<graph1.size();i++){
            if(graph1[i].size()==maximum-1 && graph2[i].size()==0) return i+1;
        }
        return -1;
    }
};