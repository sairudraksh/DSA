class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n=basket1.size();
        int minEle=basket1[0];

        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[basket1[i]]++;
            minEle=min(minEle,basket1[i]);
        }

        for(int i=0;i<n;i++){
            map[basket2[i]]--;
            minEle=min(minEle,basket2[i]);
        }

        vector<int>v;

        for(auto &x:map){
            if(x.second==0) continue;

            if(x.second%2!=0) return -1;

            else{
                for(int i=0;i<abs(x.second)/2;i++){
                    v.push_back(x.first);
                }
            }
        }

        sort(v.begin(),v.end());

        long long sum=0;

        for(int i=0;i<v.size()/2;i++){
            sum+=min(v[i],minEle*2);
        }

        return sum;
    }
};