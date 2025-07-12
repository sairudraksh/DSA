class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int total=0;
        for(int i=0;i<worker.size();i++){
            int maxprofit=0;
            for(int j=0;j<difficulty.size();j++){
                if(difficulty[j]<=worker[i]){
                    maxprofit=max(profit[j],maxprofit);
                }
            }
            total+=maxprofit;
        }
        return total;
    }
};