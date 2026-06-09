class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        priority_queue<int>maxheap;
        priority_queue<int, vector<int>, greater<int>> past;

        int j=0;
        sort(queries.begin(),queries.end());
        int usedcount=0;

        for(int i=0;i<n;i++){

            while(j<queries.size() && queries[j][0]==i){
                maxheap.push(queries[j][1]);
                j++;
            }

            nums[i]-=past.size();

            while(nums[i]>0 && maxheap.size()>0 && maxheap.top()>=i){
                nums[i]-=1;
                past.push(maxheap.top());
                usedcount++;
                maxheap.pop();
            }
            if(nums[i]>0) return -1;

            while(past.size()>0 && past.top()<=i){
                past.pop();
            }
        }

        return queries.size()-usedcount;
    }
};