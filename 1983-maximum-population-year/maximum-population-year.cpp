class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>diff(2051,0);

        int n=logs.size();
        for(int i=0;i<n;i++){
            int birth=logs[i][0];
            int death=logs[i][1];

            diff[birth]+=1;
            diff[death]-=1;
        }

        int minyear=2050;
        int currpop=0;
        int maxpop=0;

        for(int i=1950;i<2051;i++){
            currpop+=diff[i];

            if(currpop>maxpop){
                maxpop=currpop;
                minyear=i;
            }
        }
        return minyear;
    }
};