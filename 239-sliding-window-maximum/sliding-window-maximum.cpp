class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return {};
        deque<int>dq;
        vector<int>ans;

        for(int i=0;i<n;i++){
            while(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }
            while(dq.size()>0 && nums[dq.back()]<nums[i]){// do from back do dryrun in testcase [1,3,1,2,0,5]
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);

        }

        return ans;

    }
};