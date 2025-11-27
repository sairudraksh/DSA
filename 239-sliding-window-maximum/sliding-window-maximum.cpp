class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        deque<int>q;
        for(int i=0;i<k;i++){
            while(q.size()>0 && q.back()<nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        j=k-1;
        vector<int>ans;
        while(j<n){
            ans.push_back(q.front());
            if(nums[i]==q.front()){
                q.pop_front();
            }
            i++;
            j++;
            if(j<n){
                while(q.size()>0 && q.back()<nums[j]){
                    q.pop_back();
                }
                q.push_back(nums[j]);
            }
        }
        return ans;
    }
};