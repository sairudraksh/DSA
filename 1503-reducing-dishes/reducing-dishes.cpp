class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<int>suf(n);
        suf[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=satisfaction[i]+suf[i+1];
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        int maxsum=0;
        int x=1;
        for(int i=idx;i<n;i++){
            maxsum+=(satisfaction[i]*x);
            x++;
        }
        return maxsum;
    }
};