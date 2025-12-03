class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int>LPS(n,0);
        int length=0;
        int i=1;
        while(i<n){
            if(s[i]==s[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=LPS[length-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }

        return s.substr(0,LPS[n-1]);
    }
};