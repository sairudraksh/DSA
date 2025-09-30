class Solution {
public:
    int find(string str){
        for(int i=0;i<str.length();i++){
            if(str[i]=='0') return i;
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,vector<int>>map;

        map[0]={1,3};
        map[1]={0,2,4};
        map[2]={1,5};
        map[3]={0,4};
        map[4]={1,3,5};
        map[5]={2,4};


        string s="";
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                s+=board[i][j]+'0';
            }
        }
        string ans="123450";
        queue<string>que;
        unordered_set<string>visited;


        que.push(s);    
        int levels=0;

        while(que.size()>0){
            int n=que.size();

            while(n--){
                string str=que.front();
                if(str==ans) return levels;
                que.pop();
                int curridx=find(str);
                vector<int>v=map[curridx];
                for(int i=0;i<v.size();i++){
                    string newstr=str;
                    swap(newstr[curridx],newstr[v[i]]);
                    if(visited.find(newstr)==visited.end()){
                        que.push(newstr);
                        visited.insert(newstr);
                    }
                }
            }
            levels++;
        }
        return -1;
    }
};      