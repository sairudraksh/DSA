class Solution {
public:
    int find(vector<int>&nums,int i,int j){
        unordered_map<int,int>map;

        for(int k=i;k<=j;k++){
            map[nums[k]]++;
        }
        return map.size();
    }   
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int num=find(nums,i,j);

                sum+=(num*num);
            }
        }
        return sum;
    }
};