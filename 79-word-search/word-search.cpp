class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    bool find(vector<vector<char>>& board, string &word,int i,int j,int idx){
        if(i>=n || j>=m || i<0 || j<0 || visited[i][j]==1) return false;

        if(board[i][j]!=word[idx]) return false;
        if(idx==word.size()-1) return true;
        else if(idx>=word.size()) return false;
        visited[i][j]=1;

        bool a=find(board,word,i+1,j,idx+1);
        bool b=find(board,word,i,j+1,idx+1);
        bool c=find(board,word,i-1,j,idx+1);
        bool d=find(board,word,i,j-1,idx+1);

        visited[i][j]=0;
        if(a || b || c || d) return true;
        else return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        visited.resize(n,vector<int>(m+1,-1));
        bool a=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool a=find(board,word,i,j,0);
                if(a==true) return true;
            }
        }
        return false;
    }
};