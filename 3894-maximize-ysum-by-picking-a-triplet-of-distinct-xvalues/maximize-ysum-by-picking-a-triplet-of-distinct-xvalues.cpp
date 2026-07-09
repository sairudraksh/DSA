class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,int>>pq;
        int n=x.size();

        for(int i=0;i<n;i++){
            pq.push({y[i],x[i]});
        }

        int ans=0;
        int count=0;
        unordered_map<int,int>map;
        while(pq.size()>0){
            auto p=pq.top();
            pq.pop();
            int x=p.first;
            int y=p.second;
            if(map[y]>0) continue;
            map[y]++;

            ans+=x;
            count++;
            if(count==3) break;
        }
        if(count<3) return -1;
        return ans;;
    }
};