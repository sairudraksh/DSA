class Solution {
public:
    int n;
    vector<vector<string>>ans;
    bool isPalindrome(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void find(string &s,int i,string &str,vector<string>&v){
        if(i>=n){
            if(str.length()>0){
                if(isPalindrome(str)){
                    v.push_back(str);
                    ans.push_back(v);
                    v.pop_back();
                }
            }
            return ;
        }
        if(str.length()==0){
            str+=s[i];
            find(s,i+1,str,v);
            str.pop_back();
        }
        else{
            if(isPalindrome(str)){
                v.push_back(str);
                string t=str;
                str="";
                find(s,i,str,v);
                if(v.size()>0) v.pop_back();
                str=t;
            }
            str+=s[i];
            find(s,i+1,str,v);
            str.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.length();
        string t="";
        vector<string>v;
        find(s,0,t,v);
        return ans;
    }
};