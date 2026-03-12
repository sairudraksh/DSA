class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(i==j) continue;
                double a=(double)arr[i]/arr[j];
                pq.push({a,{arr[i],arr[j]}});
            }
        }
        while(k>1){
            pq.pop();
            k--;
        }
        auto v=pq.top();
        auto x=v.second;
        return {x.first,x.second};
    }
};