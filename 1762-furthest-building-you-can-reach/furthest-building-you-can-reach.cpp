class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=nums.size();
        int k=ladders;
        for(int i=0;i<nums.size()-1;i++){
            int curr=nums[i+1]-nums[i];
            if(curr<=0) continue;
            pq.push(curr);

            if(pq.size()>ladders){
                int x=pq.top();
                pq.pop();
                bricks-=x;
            }

            if(bricks<0) return i;
        }
        return nums.size()-1;
    }
};