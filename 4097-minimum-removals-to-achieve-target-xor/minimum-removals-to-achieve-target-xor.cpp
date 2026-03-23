class Solution {
public:
    int n;
    vector<vector<int>>dp;
    unordered_map<string,int>map;
    int find(vector<int>&nums,int i,int &target,int curr){
        if(i>=n){
            if(curr==target) return 0;
            else if(curr==-1 && target==0) return 0;
            else return INT_MIN;
        }
        string s1=to_string(i);
        string s2=to_string(curr);
        string key=s1+'#'+s2;
        if(map.count(key)) return map[key];
        int a=find(nums,i+1,target,curr);
        int b=0;
        if(curr==-1){
            b=find(nums,i+1,target,nums[i]);
            if(b!=INT_MIN) b+=1;

        }
        else{
            int num=curr^nums[i];
            b=find(nums,i+1,target,num);
            if(b!=INT_MIN) b+=1;
        }
        return map[key]=max(a,b);
    }
    int minRemovals(vector<int>& nums, int target) {
        n=nums.size();
        dp.resize(n+1,vector<int>(target+1,-1));
        int a=find(nums,0,target,-1);
        if(a==INT_MIN) return -1;
        else return n-a;
    }
};