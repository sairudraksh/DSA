class Solution {
public:

    int secondsToRemoveOccurrences(string s) {
        int count=0;
        int n=s.length();
        while(true){
            bool found=false;
            int i=0;
            while(i<n-1){
                if(s[i]=='0' && s[i+1]=='1'){
                    s[i]='1';
                    s[i+1]='0';
                    found=true;
                    i+=2;
                }
                else i++;
            }
            if(found==false) return count;
            count++;
        }
        return count;
    }
};