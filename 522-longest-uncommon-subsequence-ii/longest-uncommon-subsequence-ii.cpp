class Solution {
public:
    bool isTrue(string &s1,string &s2){
        if(s2.length()<s1.length()) return false;
        
        int i=0;
        int j=0;
        while(i<=s1.length() && j<=s2.length()){
            if(s2[j]==s1[i]){
                i++;
                j++;
            }
            else j++;
        }
        if(i>=s1.length()) return true;
        return false;
    }
    int findLUSlength(vector<string>& s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            bool found=true;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isTrue(s[i],s[j])){
                    found=false;
                    break;
                }
            }
            int num=s[i].length();
            if(found==true) {
                count=max(count,num);
            }
        }
        if(count==0) return -1;
        return count;
    }
};