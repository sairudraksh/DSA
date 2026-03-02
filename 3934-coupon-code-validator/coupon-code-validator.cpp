class Solution {
public:
    bool isTrue(string s){
        if(s.length()==0) return false;
        for(int i=0;i<s.length();i++){
            
            char ch=s[i];
            int num=int(s[i]);

            if((num>=97 && num<=122)  || (num>=65 && num<=90) || (ch>='0' && ch<='9') || s[i]=='_') continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<vector<string>>v;
        for(int i=0;i<n;i++){
            if(isActive[i]==true && (businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy"|| businessLine[i]=="restaurant")){
                v.push_back({businessLine[i],code[i]});
            }
        }
        sort(v.begin(),v.end());

        vector<string>ans;

        for(int i=0;i<v.size();i++){
            string s=v[i][1];

            if(isTrue(s)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};