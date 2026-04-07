class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>v;
        int sum=0;
        int start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') sum+=-1;
            else sum+=1;

            if(sum==0){
                string str=s.substr(start+1,i-start-1);
                start=i+1;
                string ans="1"+makeLargestSpecial(str)+"0";
                v.push_back(ans);
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        string result="";
        for(int i=0;i<v.size();i++){
            result+=v[i];
        }
        return result;
    }
};