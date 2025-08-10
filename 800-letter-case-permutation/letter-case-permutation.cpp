class Solution {
public://97   122   && 65   90
    vector<string>finalans;

    void find(string &s,int i){
        if(i>=s.length()){
            finalans.push_back(s);
            return;
        }

        string orgs=s;

        if(((int)s[i]>=97 && (int)s[i]<=122) || ((int)s[i]>=65 && (int)s[i]<=90)){
            if(s[i]<=122 && s[i]>=97){
                char lower = s[i]; // example lowercase letter
                char upper = lower - 32;
                s[i]=upper;
            }
            else{
                char upper = s[i]; // example uppercase letter
                char lower = upper + 32;
                s[i]=lower;
            }

            find(s,i+1);
            s=orgs;
        }
        find(s,i+1);
    }
    vector<string> letterCasePermutation(string s) {
        find(s,0);
        return finalans;
    }
};