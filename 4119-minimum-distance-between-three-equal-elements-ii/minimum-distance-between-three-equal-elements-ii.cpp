class Solution {
public:
    int find(vector<int>v){
        int l=0;
        int r=2;
        int minimum=INT_MAX;
        while(r<v.size()){
            int i=v[l];
            int j=v[l+1];
            int k=v[r];

            minimum=min(minimum,abs(i-j)+abs(j-k)+abs(k-i)); 
            l++;
            r++;
        }
        return minimum;
    }
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        int minimum=INT_MAX;
        for(auto &x:map){
            if(x.second.size()<3) continue;

            auto v=x.second;

            int a=find(v);
            minimum=min(minimum,a); 
        }
        if(minimum==INT_MAX) return -1;
        return minimum;

    }
};