class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%k!=0) return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>map;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            map[nums[i]]++;
            st.push(nums[i]);
        }

        while(st.size()!=0){
            int x=st.top();
            st.pop();
            if(map.find(x)==map.end()) continue;
            for(int l=0;l<k;l++){
                if(map.find(x+l)==map.end()) return false;
                else{
                    map[x+l]--;
                    if(map[x+l]==0) map.erase(x+l);
                }
            }
        }


        return true;
    }
};