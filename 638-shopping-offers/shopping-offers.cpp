class Solution {
public:
    map<vector<int>, int> dp;

    int find(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if (dp.count(needs)) return dp[needs];
        bool tag=false;
        for(int i=0;i<needs.size();i++){
            if(needs[i]!=0){
                tag=true;
                break;
            }
        }
        if(tag==false) return 0;
        vector<int>v=needs;
        int ans=INT_MAX;
        for(int i=0;i<special.size();i++){
            bool flagg=false;
            for(int j=0;j<needs.size();j++){
                if(special[i][j]>needs[j]){
                    flagg=true;
                    break;
                }
            }
            if(flagg==false){
                for(int j=0;j<needs.size();j++) {
                    needs[j] -= special[i][j];
                }
                ans=min(ans,special[i][special[0].size()-1]+find(price,special,needs));
                needs=v;
            }
        }
        int ans1=0;
        for(int i=0;i<needs.size();i++){
            ans1+=needs[i]*price[i];// we directly bought all
        }
        return dp[needs]=min(ans1,ans);   
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        return find(price,special,needs);
    }
};