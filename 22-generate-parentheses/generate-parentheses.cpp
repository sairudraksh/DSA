class Solution {
public:
    vector<string>v;
    void find(int &n,string s,int open,int close){
        if(s.length()==2*n){
            if(open==close){
                v.push_back(s);
            }
            return;
        }
        if(close<open){
            find(n,s+')',open,close+1);
        }
        find(n,s+'(',open+1,close);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        find(n,s,0,0);
        return v;
    }
};