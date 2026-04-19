class Solution {
public:
    int n;
    int m;
    void find(vector<vector<int>>&v,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        vector<vector<int>>visited;
        int t=v.size();
        int c=v[0].size();
        visited.resize(t+1,vector<int>(c+1,0));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]!=0){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        while(q.size()>0){
            int size=q.size();
            map<pair<int,int>,int>mp;
            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i+1<t){
                    if(visited[i+1][j]==0){
                        q.push({i+1,j});
                        visited[i+1][j]=1;
                        v[i+1][j]=v[i][j];
                        mp[{i+1,j}]++;
                    }
                    else if(mp.find({i+1,j})!=mp.end()){
                        if(v[i+1][j]<v[i][j]){
                            v[i+1][j]=v[i][j];
                            q.push({i+1,j});
                        }
                    }
                }
                if(j+1<c){
                    if(visited[i][j+1]==0){
                        q.push({i,j+1});
                        visited[i][j+1]=1;
                        v[i][j+1]=v[i][j];
                        mp[{i,j+1}]++;
                    }
                    else if(mp.find({i,j+1})!=mp.end()){
                        if(v[i][j+1]<v[i][j]){
                            v[i][j+1]=v[i][j];
                            q.push({i,j+1});
                        }
                    }
                }
                if(i-1>=0){
                    if(visited[i-1][j]==0){
                        q.push({i-1,j});
                        visited[i-1][j]=1;
                        v[i-1][j]=v[i][j];
                        mp[{i-1,j}]++;
                    }
                    else if(mp.find({i-1,j})!=mp.end()){
                        if(v[i-1][j]<v[i][j]){
                            v[i-1][j]=v[i][j];
                            q.push({i-1,j});
                        }
                    }
                }
                if(j-1>=0){
                    if(visited[i][j-1]==0){
                        q.push({i,j-1});
                        visited[i][j-1]=1;
                        v[i][j-1]=v[i][j];
                        mp[{i,j-1}]++;
                    }
                    else if(mp.find({i,j-1})!=mp.end()){
                        if(v[i][j-1]<v[i][j]){
                            v[i][j-1]=v[i][j];
                            q.push({i,j-1});
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> colorGrid(int t, int p, vector<vector<int>>& grid) {
     n=grid.size();
        m=grid[0].size();
        vector<vector<int>>v;
        v.resize(t,vector<int>(p,0));
        for(int i=0;i<grid.size();i++){
            int k=grid[i][0];
            int j=grid[i][1];
            int num=grid[i][2];
            v[k][j]=num;
        }
        find(v,grid);
        return v;
    }
};