class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        dq.push_front({nums[0],0});

        for(int i=1;i<nums.size();i++){
            while(dq.size()>0 && dq.front().second+k<i){
                dq.pop_front();
            }

            int cost=dq.front().first+nums[i];

            while(dq.size()>0 && dq.back().first<=cost){
                dq.pop_back();
            }
            dq.push_back({cost,i});
        }
        return dq.back().first;
    }
};