class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxlen=0;

        unordered_map<char,int>map;


        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            map[s[j]]++;
            maxlen=max(maxlen,map[s[j]]);

            if((j-i+1)-maxlen>k){
                map[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};