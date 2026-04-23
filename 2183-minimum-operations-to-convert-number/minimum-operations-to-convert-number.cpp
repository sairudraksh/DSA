class Solution {
public:
    int n;
    int bfs(vector<int>&nums,int x,int goal){
        vector<int>visited;
        visited.resize(1001,0);
        visited[x]=1;
        queue<int>q;
        q.push(x);
        int count=0;
        while(q.size()>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int num=q.front();
                if(num==goal) return count;
                q.pop();

                for(int j=0;j<nums.size();j++){
                    int new_num=num+nums[j];
                    if(new_num==goal) return count+1;
                    if(new_num<=1000 && new_num>=0 && visited[new_num]==0){
                        visited[new_num]=1;
                        q.push(new_num);
                    }
                }
                for(int j=0;j<nums.size();j++){
                    int new_num=num-nums[j];
                    if(new_num==goal) return count+1;
                    if(new_num<=1000 && new_num>=0 && visited[new_num]==0){
                        visited[new_num]=1;
                        q.push(new_num);
                    }
                }
                for(int j=0;j<nums.size();j++){
                    int new_num=num^nums[j];
                    if(new_num==goal) return count+1;
                    if(new_num<=1000 && new_num>=0 && visited[new_num]==0){
                        visited[new_num]=1;
                        q.push(new_num);
                    }
                }

            }
            count++;
        }
        return -1;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        n=nums.size();
        return bfs(nums,start,goal);
    }
};