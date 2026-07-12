class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>map;
        int n=nums.size();
        int count=1;
        for(int i=0;i<n;i++){
            if(map[arr[i]]==0){
                map[arr[i]]=count;
                count++;
            }

        }
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(map[nums[i]]);
        }
        return v;
    }
};