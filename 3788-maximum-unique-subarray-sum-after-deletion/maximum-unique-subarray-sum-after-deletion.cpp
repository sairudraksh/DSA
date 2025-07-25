class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        bool flagg=false;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                flagg=true;
                break;
            }
        }
        unordered_map<int,int>map;
        if(flagg==true){
            for(int i=0;i<n;i++){
                if(nums[i]>=0){
                    map[nums[i]]++;
                }
            }
        }
        else{
            int maximum=INT_MIN;
            for(int i=0;i<n;i++){
                maximum=max(maximum,nums[i]);
            }
            return maximum;
        }
        int sum=0;
        for(auto &x:map){
            sum+=x.first;
        }
        return sum;

    }
};