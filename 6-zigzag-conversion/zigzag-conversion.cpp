class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>>v;
        for(int i=0;i<n;i++){
            vector<char>v1;
            v.push_back(v1);
        }
        int j=0;
        int curr=true;
        int i=0;
        if(n==1) return s;
        while(j<s.length()){
            v[i].push_back(s[j]);
            if(curr){
                i+=1;
            }
            else i-=1;

            j++;

            if(i>=n){
                i=i-2;
                curr=false;
            }
            else if(i<0){
                curr=true;
                i=i+2;
            }
        }
        string ans="";
        for(int l=0;l<v.size();l++){
            for(int p=0;p<v[l].size();p++){
                ans+=v[l][p];
            }
        }
        return ans;
    }
};