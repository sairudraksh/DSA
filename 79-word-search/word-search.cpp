class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    bool find(vector<vector<char>>& board,string &word,string &s,int i,int j,int idx){
        if(s==word) return true;
        if(i>=n || j>=m || i<0 || j<0) return false;
        if(visited[i][j]!=-1) return false;
        if(board[i][j]!=word[idx]) return false;
        visited[i][j]=1;
        s+=board[i][j];
        bool a={find(board,word,s,i+1,j,idx+1)||find(board,word,s,i,j+1,idx+1)||find(board,word,s,i,j-1,idx+1)||find(board,word,s,i-1,j,idx+1)};
        s.pop_back();
        visited[i][j]=-1;
        return a;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        visited.resize(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s="";
                bool a=find(board,word,s,i,j,0);
                if(a==true) return true;
            }
        }
        return false;
    }
};