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
    void find(string &s,vector<string>&v,string &str,int i){
        if(i>=s.length()){
            if(str=="") return;
            if(isPalindrome(str)){
                v.push_back(str);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        str+=s[i];
        if(isPalindrome(str)){
            v.push_back(str);
            string neww="";
            find(s,v,neww,i+1);
            v.pop_back();
        }
        find(s,v,str,i+1);
        str.pop_back();
    }
    vector<vector<string>> partition(string s) {
        n=s.length();
        vector<string>v;
        string str="";
        find(s,v,str,0);
        return ans;
    }
};