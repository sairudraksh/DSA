class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int ans=0;
        int curr=1;
        while(n>=8){
            n=n-8;
            ans+=(8*curr);
            curr++;
        }
        ans+=(n*curr);
        return ans;
    }
};