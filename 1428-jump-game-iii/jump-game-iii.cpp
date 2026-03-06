class Solution {
public:
    bool find(vector<int>&arr,int &start){
        int n=arr.size();
        queue<int>q;
        q.push(start);
        vector<int>visited;
        visited.resize(n+1,0);
        visited[start]=1;

        while(q.size()>0){
            int i=q.front();
            q.pop();
            if(arr[i]==0) return true;
            if(i+arr[i]<n && visited[i+arr[i]]==0){
                if(arr[i+arr[i]]==0) return true;
                q.push(i+arr[i]);
                visited[i+arr[i]]=1;
            }

            if(i-arr[i]>=0 && visited[i-arr[i]]==0){
                if(arr[i-arr[i]]==0) return true;
                q.push(i-arr[i]);
                visited[i-arr[i]]=1;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        return find(arr,start);
    }
};