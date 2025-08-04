class Solution {
public:
    int leastInterval(vector<char>& nums, int p) {
        int n=nums.size();
        unordered_map<char,int>map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        int time=0;

        priority_queue<int>pq;

        for(auto &x:map){
            pq.push(x.second);
        }

        while(pq.size()>0){
            vector<int>temp;

            for(int i=1;i<=p+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0) pq.push(temp[i]);
            }

            if(pq.size()<=0){
                time+=temp.size();
            }
            else{
                time+=p+1;
            }
        }
        return time;
    }
};