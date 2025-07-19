class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;

        vector<long long>leftside(N,0);
        vector<long long>rightside(N,0);

        priority_queue<int>maxheap;
        priority_queue<int,vector<int>,greater<int>> minHeap;


        long long leftsum=0;
        long long rightsum=0;
        for(int i=0;i<=2*n-1;i++){
            leftsum+=nums[i];
            maxheap.push(nums[i]);
            if(maxheap.size()>n){
                int x=maxheap.top();
                leftsum-=x;
                maxheap.pop();
            }
            leftside[i]=leftsum;
        }

        for(int i=N-1;i>=n;i--){
            rightsum+=nums[i];
            minHeap.push(nums[i]);
            if(minHeap.size()>n){
                int x=minHeap.top();
                rightsum-=x;
                minHeap.pop();
            }
            rightside[i]=rightsum;
        }
        long long minans=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            long long diff=leftside[i]-rightside[i+1];
            minans=min(diff,minans);
        }
        return minans;
    }
};