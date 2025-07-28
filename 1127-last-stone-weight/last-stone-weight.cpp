class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();

            int ans=abs(x-y);

            pq.push(ans);
            if(pq.top()==0) return 0;
        }
        if(pq.top()!=0) return pq.top();
        return 0;
    }
};