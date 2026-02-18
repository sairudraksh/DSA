class Solution {
public:
    int n;
    int m;
    vector<int>visited;
    void find(vector<vector<int>>&grid){
        queue<int>q;
        auto v=grid[0];
        for(int i=0;i<v.size();i++){
            q.push(v[i]);
            visited[v[i]]=1;
        }
        visited[0]=1;

        while(q.size()>0){
            int val=q.front();
            q.pop();

            auto v1=grid[val];

            for(int i=0;i<v1.size();i++){
                if(visited[v1[i]]==0){
                    q.push(v1[i]);
                    visited[v1[i]]=1;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,0);
        find(grid);
        for(int i=0;i<grid.size();i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};