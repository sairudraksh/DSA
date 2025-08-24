class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        vector<int>visited(n,0);
        unordered_map<int,vector<int>>map;

        for(int i=0;i<n;i++){
            map[nums[i]].push_back(i);
        }

        queue<int>q;

        q.push(0);
        int steps=0;
        visited[0]=1;

        while(q.size()>0){
            int size=q.size();


            while(size--){
                int curr=q.front();
                q.pop();
                if(curr==n-1) return steps;

                int left=curr-1;
                int right=curr+1;

                if(left>=0 && !visited[left]){
                    q.push(left);
                    visited[left]=1;
                }

                if(right<=n-1 && !visited[right]){
                    q.push(right);
                    visited[right]=1;
                }

                if(map.find(nums[curr])!=map.end()){
                    vector<int>v=map[nums[curr]];
                    for(int i=0;i<v.size();i++){
                        if(!visited[v[i]]){
                            q.push(v[i]);
                            visited[v[i]];
                        }
                    }
                    map.erase(nums[curr]);
                }
            }
            steps++;
        }
        return -1;
    }
};