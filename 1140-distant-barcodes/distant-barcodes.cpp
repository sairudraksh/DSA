class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(auto &x:map){
            pq.push({x.second,x.first});
        }

        vector<int>v;
        while(pq.size()>0){
            auto largest=pq.top();
            pq.pop();
            v.push_back(largest.second);

       
            if(pq.size()>0){

                auto Slargest=pq.top();
                v.push_back(Slargest.second);
                pq.pop();

                if(Slargest.first-1>0){
                    pq.push({Slargest.first-1,Slargest.second});
                }
            }
            else break;

            if(largest.first-1>0){
                pq.push({largest.first-1,largest.second});
            }
        }
        return v;
    }
};