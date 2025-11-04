class Solution {
public:
    int strStr(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();

        int i=0;
        int j=0;
        while(i<n1){
            if(s1[i]==s2[j]){
                int k=i;
                while(k<n1){
                    if(s1[k]!=s2[j]){
                        break;
                    }
                    j++;
                    k++;
                    if(j==n2) return i;
                }
            }
            i++;
            j=0;
        }
        return -1;
    }
};