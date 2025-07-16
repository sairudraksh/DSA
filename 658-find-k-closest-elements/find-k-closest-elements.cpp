class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int diff=abs(x-arr[i]);
            pq.push({diff,arr[i]});
        }
        while(pq.size()>k){
            pq.pop();
        }
        vector<int>v;
        while(pq.size()!=0){
            auto x=pq.top();
            v.push_back(x.second);
            pq.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};