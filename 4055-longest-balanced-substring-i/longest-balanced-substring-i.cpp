class Solution {
public:
    bool check(unordered_map<char,int>&map){
        int count=0;
        int val=-1;
        for(auto x:map){
            if(count==0) val=x.second;
            else{
                if(x.second!=val) return false;
            }
            count++;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>map;

            for(int j=i;j<n;j++){
                map[s[j]]++;

                if(j-i+1>maxlen){
                    if(check(map)){
                        maxlen=max(maxlen,j-i+1);
                    }
                }
            }
        }
        return maxlen;
    }
};