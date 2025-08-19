class Solution {
public:
    vector<int>finalans;
    void find(vector<int>&ans,int n,int &k){
        if(n==0){
            int a=0;
            for(int i=0;i<ans.size();i++){
                a=(a*10)+ans[i];
            }
            finalans.push_back(a);
            return;
        }

        for(int i=0;i<=9;i++){
            if(ans.size()==0 || abs(ans[ans.size()-1]-i)==k){
                if(i!=0 || ans.size()>=1){
                    ans.push_back(i);
                    find(ans,n-1,k);
                    ans.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        find(ans,n,k);
        return finalans;
    }
};