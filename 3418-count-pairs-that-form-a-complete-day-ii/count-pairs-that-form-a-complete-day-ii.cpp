class Solution {
public:
    long long countCompleteDayPairs(vector<int>& nums) {
        unordered_map<long long,long long>map;
        int n=nums.size();
        vector<long long>v(n);
        for(int i=0;i<n;i++){
            v[i]=(1LL*nums[i])%24;
        }
        long long count=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                count+=map[v[i]];
                map[0]++;
                continue;
            }
            long long req=24-v[i];
            long long freq=map[req];
            count+=freq;
            map[v[i]]++;
        }
        return count;
    }
};