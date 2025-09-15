class Solution {
public:
    int leastInterval(vector<char>& nums, int n) {
        unordered_map<char,int>map;// main thing here is that first do taskes that have more frequency as at end they moght creaate problem
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<int>pq;
        for(auto &x:map){
            pq.push(x.second);
        }
        int time=0;
        while(pq.size()>0){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]!=0) pq.push(temp[i]);
            }

            if(pq.size()<=0){
                time+=temp.size();
            }
            else{// n bercause taht size will be empty
                time+=n+1;
            }
        }
        return time;
    }
};