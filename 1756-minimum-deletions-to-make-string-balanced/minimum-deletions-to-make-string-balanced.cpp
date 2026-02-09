class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int acount=0;
        int bcount=0;

        
        for(int i=0;i<n;i++){
            left[i]=bcount;
            if(s[i]=='b') bcount++;
            
        }
        for(int i=s.length()-1;i>=0;i--){
            right[i]=acount;
            if(s[i]=='a') acount++;
        }
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
            minimum=min(minimum,left[i]+right[i]);
        }
        return minimum;
    }
};