class Solution {
public:
    //int x = stoi(s);
    int n;
    vector<string>v;
    bool Valid(string &s){
        int count=0;
        int m=s.length();
        for(int i=0;i<m;i++){
            if(s[i]=='.'){
                count++;
            }
        }
        return count==3;
    }
    bool isValid(string &s){
        if (s.empty()) return false;
        if (s.length() > 1 && s[0] == '0') return false;
        if (s.length() > 3) return false;
        int x = stoi(s);
        return x >= 0 && x <= 255;
    }
    void find(string &s,string &str,string &ans,int i){
        if(i>=n){
            if(isValid(str)){
                string org=ans;
                if (!ans.empty()) ans+=".";
                ans+=str;
                if(Valid(ans)){
                    v.push_back(ans);
                }
                ans=org;
            }
            return;
        }
        str+=s[i];
        if(isValid(str)){
            string org=ans;
            string org2=str;

            if (!ans.empty()) ans+=".";
            ans+=str;
            str="";
            find(s,str,ans,i+1);
            
            ans=org;
            str=org2;

            if(str.length()<=3) find(s,str,ans,i+1);
        }
        str.pop_back();
    }
    vector<string> restoreIpAddresses(string s){
        n=s.length();
        string ans="";
        string str="";
        find(s,str,ans,0);
        return v;
    }
};