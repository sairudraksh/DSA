class Solution {
public:
    vector<string>ans;
    void find(int &n,int &k,string &s){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }

        if(s.length()==0){
            s+='a';
            find(n,k,s);
            s.pop_back();

            s+='b';
            find(n,k,s);
            s.pop_back();

            s+='c';
            find(n,k,s);
            s.pop_back();
        }
        else{
            if(s[s.length()-1]=='a'){
                s+='b';
                find(n,k,s);
                s.pop_back();

                s+='c';
                find(n,k,s);
                s.pop_back();
            }

            if(s[s.length()-1]=='b'){
                s+='a';
                find(n,k,s);
                s.pop_back();

                s+='c';
                find(n,k,s);
                s.pop_back();
            }

            if(s[s.length()-1]=='c'){
                s+='a';
                find(n,k,s);
                s.pop_back();

                s+='b';
                find(n,k,s);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s="";
        find(n,k,s);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};