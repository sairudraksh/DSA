class Solution {
public:
    map<vector<int>, int> dp;
    int find(vector<int>&price,vector<vector<int>>&special,vector<int>needs){
        if(dp.count(needs)) return dp[needs];
        bool tag=true;
        for(int i=0;i<needs.size();i++){
            if(needs[i]!=0){
                tag=false;
            }
        }
        if(tag==true) return 0;
        vector<int>v=needs;
        int b=INT_MAX;
        for(int i=0;i<special.size();i++){
            bool flagg=true;
            for(int j=0;j<needs.size();j++){
                if(needs[j]<special[i][j]){
                    flagg=false;
                    break;
                }
            }
            if(flagg==true){
                for(int l=0;l<needs.size();l++){
                    needs[l]-=special[i][l];
                }
                b=min(b,special[i][special[i].size()-1]+find(price,special,needs));
                needs=v;
            }
        }
        int ans=0;
        for(int i=0;i<needs.size();i++){
            ans+=needs[i]*price[i];
        }
        return dp[needs]=min(ans,b);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return find(price,special,needs);
    }
};