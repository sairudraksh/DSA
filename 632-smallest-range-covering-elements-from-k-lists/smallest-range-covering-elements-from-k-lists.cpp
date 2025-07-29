class Solution {
public:
    typedef pair<int,pair<int,int>>pip;//Traverse in min of all vector and do i++ in that particular vector
    priority_queue<pip,vector<pip>,greater<pip>>pq;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }

        int mn=pq.top().first;
        int diff=mx-mn;
        int st=mn;
        int end=mx;

        while(true){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(nums[row].size()-1==col) break;

            pq.push({nums[row][col+1],{row,col+1}});

            mn=pq.top().first;

            mx=max(mx,nums[row][col+1]);

            if(mx-mn<diff){
                diff=mx-mn;
                st=mn;
                end=mx;
            }
        }
        return {st,end};
        
    }
};