class Solution {
public:
    void generate(string s,int n,vector<string>&v){
        if(n==0){
            v.push_back(s);
            return;
        }
        generate(s+'1',n-1,v);
        if(s==""||s[s.length()-1]=='1'){
            generate(s+'0',n-1,v);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>v;
        generate("",n,v);
        return v;
    }
};
