class Solution {
public:
    vector<vector<int>> dp;

    bool preceddor(string &curr, string &prev) {
        int j=0;
        for(int i=0;i<curr.length();i++){
            if(j<prev.length() && curr[i]==prev[j]) j++;
        }
        return j==prev.length();
    }

    int find(vector<string>& words, int i, int prevIdx) {
        int n = words.size();
        while(i<n && prevIdx!=-1 && words[i].length()==words[prevIdx].length()){
            i++;
        }
        if(i>=n) return 0;

        if(dp[i][prevIdx+1]!=-1) return dp[i][prevIdx];

        int maximum=0;
        if(prevIdx==-1){
            for(int k=0;k<n;k++){
                maximum=max(maximum, 1+find(words,k+1,k));
            }
        } 
        else {
            int l=i;
            while(l<n && words[l].length()==words[prevIdx].length()+1){
                if(preceddor(words[l],words[prevIdx])){
                    maximum=max(maximum, 1+find(words,l+1,l));
                }
                l++;
            }
        }
        return dp[i][prevIdx+1]=maximum;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a,const string &b){
            return a.size() < b.size();
        });

        int n=words.size();
        dp.assign(n+1, vector<int>(n+1,-1)); 

        return find(words,0,-1); 
    }
};
