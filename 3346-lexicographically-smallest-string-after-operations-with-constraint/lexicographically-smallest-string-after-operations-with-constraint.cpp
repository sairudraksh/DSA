class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch1=s[i];
            bool found=false;
            for(int i=0;i<26;i++){
                int num=i+97;
                char ch2=char(num);
                int diff=abs(ch1-ch2);
                int cost=min(diff,26-diff);
                if(cost<=k){
                    ans+=ch2;
                    found=true;
                    k-=cost;
                    break;
                }
            }
            if(found==false) return s;
        }
        return ans;
    }
};