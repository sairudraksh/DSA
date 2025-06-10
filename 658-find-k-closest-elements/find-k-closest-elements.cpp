class Solution {
public:
    typedef pair<int,int>pi; 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi>pq;
        for(int i=0;i<arr.size();i++){
            int ele=arr[i];
            int diff=abs(x-ele);
            pq.push({diff,ele});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};