class Solution {
public:
    int n;
    int m;
    vector<vector<int>>v={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    bool find(vector<vector<int>>& grid,int l,int r){
        if(grid[l][r]!=0) return false;
        queue<pair<int,int>>q;
        
        int count=0;
   
        q.push({l,r});
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            bool found=false;
            if(grid[i][j]==(n*n)-1) return true;
            for(int t=0;t<v.size();t++){
                int i1=i+v[t][0];
                int j1=j+v[t][1];
                if(i1>=n || i1<0 || j1>=m || j1<0) continue;
                if(grid[i1][j1]==count+1){
                    found=true;
                    q.push({i1,j1});
                    count++;
                    break;
                }
            }
            if(found==false) return false;
        }
        return false;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        return find(grid,0,0);
    }
};