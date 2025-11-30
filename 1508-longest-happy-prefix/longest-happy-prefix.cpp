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
                    length=LPS[length-1];// we an directly assign and i will not be incremented and it will check again and dont do length-- and go to previous LPS and it is already LPS na dtry to aad it  there
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0, LPS[n-1]);// till n-1 as LPS we want of full string not till particular index

    }
};