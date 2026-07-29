class Solution {
public:
    bool find(int x,int y,int target){
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>visited;
        visited.resize(x+1,vector<int>(y+1,0));
        visited[0][0]=1;

        while(q.size()>0){
            auto p=q.front();
            int i=p.first;
            int j=p.second;
            q.pop();
            if(i+j==target) return true;

            // fill either jug completely with water
            if(visited[x][j]==0){
                q.push({x,j});
                visited[x][j]=1;
            }
            if(visited[i][y]==0){
                q.push({i,y});
                visited[i][y]=1;
            }

            // empty either jug

            if(visited[0][j]==0){
                q.push({0,j});
                visited[0][j]=1;
            }

            if(visited[i][0]==0){
                q.push({i,0});
                visited[i][0]=1;
            }

            // pour water from one jug to another

            int fir=x-i;
            int sec=j;

            int num=min(fir,sec);

            int nj=j-num;
            int ni=i+num;

            if(visited[ni][nj]==0){
                q.push({ni,nj});
                visited[ni][nj]=1;
            }
            
            fir=y-j;
            sec=i;
            num=min(fir,sec);

            ni=i-num;
            nj=j+num;
        

            if(visited[ni][nj]==0){
                q.push({ni,nj});
                visited[ni][nj]=1;
            }
        }
        return false;
    }
    bool canMeasureWater(int x, int y, int target) {
        return find(x,y,target);
    }
};