class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i=0;
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        while(i<n1 && i<n2 && i<n3 && s1[i]==s2[i] && s2[i]==s3[i]){
            i++;
        }
        if(i==0) return -1;
        return (n1-i)+(n2-i)+(n3-i);
    }
};