class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long a=hours[i]+hours[j];
                if(a%24==0) count++;
            }
        }

        return count;
    }
};