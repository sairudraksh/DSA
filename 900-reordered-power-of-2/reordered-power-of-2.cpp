class Solution {
public:
    bool isPower(int n) {
        return n>0 && (n & (n-1))==0;
    }
    bool find(string &s,string &ans,vector<int>&visited){
        if(ans.length()==s.length()){
            int t=stoi(ans);
            if(isPower(t)){
                return true;
            }
            return false;
        }

        for(int i=0;i<s.length();i++){
            if(visited[i]) continue;
            if(ans.length()==0 && s[i]=='0') continue;

            char org=s[i];
            ans+=s[i];
            visited[i]=true;

            bool a=find(s,ans,visited);

            if(a==true) return true;

            ans.pop_back();
            visited[i]=false;
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        string ans="";
        vector<int>visited(s.length(),false);
        return find(s,ans,visited);
    }
};