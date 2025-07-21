class Solution {
public:
    map<vector<int>,int>dp;
    int find(vector<int>& price, vector<vector<int>>& special, vector<int>needs){
        if(dp.count(needs)) return dp[needs];
        bool flagg1=false;
        for(int i=0;i<needs.size();i++){
            if(needs[i]!=0){
                flagg1=true;
                break;
            }
        }
        vector<int>v=needs;
        if(flagg1==false) return 0;

        int n=needs.size();
        int result=0;
        for(int i=0;i<n;i++){
            result+=needs[i]*price[i];
        }
        for(int i=0;i<special.size();i++){
            bool flagg=true;
            for(int j=0;j<n;j++){
                if(special[i][j]>needs[j]){
                    flagg=false;
                    break;
                }
                else{
                    needs[j]=needs[j]-special[i][j];
                }
            }
            if(flagg==true){
                int a=special[i][special[0].size()-1]+find(price,special,needs);
                result=min(result,a);
            }
            needs=v;
        }
        return dp[needs]=result;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return find(price,special,needs);
    }
};