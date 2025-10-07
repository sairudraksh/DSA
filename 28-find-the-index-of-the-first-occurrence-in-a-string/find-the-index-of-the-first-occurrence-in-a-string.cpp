class Solution {
public:
    int strStr(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[0]){
                bool found=true;
                for(int j=0;j<m;j++){
                    if(i+j>=n){
                        found=false;
                        break;
                    }
                    if(s1[i+j]!=s2[j]){
                        found=false;
                    }
                }
                if(found) return i;
            }
        }

        return -1;
    }
};