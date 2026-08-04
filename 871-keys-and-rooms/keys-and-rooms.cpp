class Solution {
public:
    vector<int>visited;
    bool find(int i,vector<vector<int>>&rooms){
        queue<int>q;
        visited[0]=1;
        for(int j=0;j<rooms[i].size();j++){
            q.push({rooms[i][j]});
            visited[rooms[i][j]]=1;
        }

        while(q.size()>0){
            int currRoom=q.front();
            q.pop();
            for(int j=0;j<rooms[currRoom].size();j++){
                int nextRoom=rooms[currRoom][j];
                if(visited[nextRoom]==0){
                    q.push({rooms[currRoom][j]});
                    visited[nextRoom]=1;
                }
            }
        }
        for(int j=0;j<visited.size();j++){
            if(visited[j]==0) return false;
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n=rooms.size();
        visited.resize(n,0);
        return find(0,rooms);
    }
};