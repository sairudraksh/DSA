class Solution {
public:
    vector<string>v;
    void find(int n,string &s){
        if(s.length()==n){
            v.push_back(s);
            return;
        }
        if(s.length()==0 || s[s.length()-1]=='1'){
            s+='0';
            find(n,s);
            s.pop_back();
            s+='1';
            find(n,s);
            s.pop_back();
        }
        else{
            if(s[s.length()-1]=='0'){
                s+='1';
                find(n,s);
                s.pop_back();
            }
        }
    }
    vector<string> validStrings(int n) {
        string s="";
        find(n,s);
        return v;
    }
};