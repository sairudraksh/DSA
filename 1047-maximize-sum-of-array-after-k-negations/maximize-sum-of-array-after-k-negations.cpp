class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(k>0){
            if(pq.top()==0) break;
            int x=pq.top();
            pq.pop();
            pq.push(-x);
            k--;
        }
        int sum=0;
        while(pq.size()>0){
            sum=sum+pq.top();
            pq.pop();
        }
        return sum;
    }
};