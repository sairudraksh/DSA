class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,long long>map1;
        unordered_map<int,long long>map2;
        vector<long long>arr1;
        for(int i=0;i<n;i++){
            long long no_of_idx=map2[nums[i]];
            long long sum=map1[nums[i]];

            arr1.push_back(no_of_idx*i-sum);

            map2[nums[i]]++;
            map1[nums[i]]+=i;
        }
        map1.clear();
        map2.clear();

        vector<long long>arr2;

        for(int i=n-1;i>=0;i--){
            long long no_of_idx=map2[nums[i]];
            long long sum=map1[nums[i]];

            arr1[i]+=sum-no_of_idx*i;
            map2[nums[i]]++;
            map1[nums[i]]+=i;
        }
        return arr1;
    }
};