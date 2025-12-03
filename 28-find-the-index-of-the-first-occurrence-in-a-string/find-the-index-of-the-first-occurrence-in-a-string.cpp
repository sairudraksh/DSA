class Solution {
public:
    int strStr(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        for(int i=0;i<n1;i++){
            if(s1[i]==s2[0]){
                int k=i;
                int j=0;
                for(j=0;j<n2;j++){
                    if(s1[k]!=s2[j]){
                        break;
                    }
                    k++;
                }
                if(j==n2) return i;
            }
        }
        return -1;
    }
};