class Solution {
public:
    int n;
    int m;
    unordered_map<int,pair<int,int>>map;
    int bfs(vector<vector<int>>& board,vector<vector<int>>&matrix,int l,int m){
        queue<pair<int,int>>q;
        q.push({l,m});

        vector<vector<int>> visited(n, vector<int>(n, 0));


        visited[l][m]=1;
        int count=0;
        while(q.size()>0){
            int size=q.size();

            for(int x=0;x<size;x++){
                auto p=q.front();
                q.pop();

                int i=p.first;
                int j=p.second;
                
                int curr=matrix[i][j];
                if(curr==n*n) return count;// not =0 && j==0 as last number can be at 0,n-1
                for(int k=1;k<=6;k++){
                    int next=curr+k;
                    if(next>n*n) continue;
                   
                        auto pair=map[next];
                        int idx1=pair.first;
                        int idx2=pair.second;

                        if(board[idx1][idx2]!=-1){
                            next=board[idx1][idx2];
                        }

                        pair=map[next];
                        idx1=pair.first;
                        idx2=pair.second;

                        if(visited[idx1][idx2]==0){
                            q.push({idx1,idx2});
                            visited[idx1][idx2]=1;
                        }
                    
                   
                }
            }
            count++;
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();

        vector<vector<int>>matrix(n,vector<int>(m,0));


        int val=1;
        int rev=false;
        for(int i=n-1;i>=0;i--){// tsrt from back side ony and n-1 is assured will from left to right
            if(!rev){
                for(int j=0;j<n;j++){
                    matrix[i][j] = val++;
                }
            } else {
                for(int j=n-1;j>=0;j--){
                    matrix[i][j]=val++;
                }
            }
            rev = !rev;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[matrix[i][j]]={i,j};
            }
        }
        return bfs(board,matrix,n-1,0);
    }
};