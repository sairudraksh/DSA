class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string s) {
        int n=queries.size();
        int m=s.length();
        int count=0;
        for(int i=0;i<s.length();i++){
            int ch=int(s[i]);
            if(ch>=65 && ch<=93) count++;
        }
        vector<bool>v;
        for(int i=0;i<n;i++){
            string t=queries[i];
            int l=0;
            int j=0;
            int upCount=0;
            while(l<t.length() && j<s.length()){
                if(t[l]==s[j]){
                    j++;
                }
                if(int(t[l])>=65  && int(t[l])<=93) upCount++;
                l++;
            }
            while(l<t.length()){
                int ch=int(t[l]);
                if(ch>=65 && ch<=93) upCount++;
                l++;
            }
            if(j>=s.length() && count==upCount) v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};