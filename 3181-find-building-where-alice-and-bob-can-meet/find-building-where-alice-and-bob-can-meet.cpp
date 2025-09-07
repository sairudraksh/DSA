class Solution {
public:
    vector<int>st;
    void buildTree(int i,int lo,int hi,vector<int>&arr){
        if(lo==hi){
            st[i]=lo;
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(2*i+1,lo,mid,arr);
        buildTree(2*i+2,mid+1,hi,arr);
        if(arr[st[2*i+1]]>arr[st[2*i+2]]){
            st[i]=st[2*i+1];
        }
        else st[i]=st[2*i+2];
    }

    int find(int i,int l,int r,int lo,int hi,vector<int>&arr){
        if(r<lo || hi<l) return -1;
        else if(lo>=l && r>=hi) return st[i];

        int mid=lo+(hi-lo)/2;

        int left=find(2*i+1,l,r,lo,mid,arr);
        int right=find(2*i+2,l,r,mid+1,hi,arr);
        if(left==-1) return right;
        if(right==-1) return left;
        if(arr[left]>arr[right]){
            return left;
        }
        else return right;
    }
    vector<int> leftmostBuildingQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
        int m=arr.size();
        vector<int>ans;
        st.resize(4*m);
        buildTree(0,0,m-1,arr);
        for(int i=0;i<n;i++){
            int max_idx=max(queries[i][0],queries[i][1]);
            int min_idx=min(queries[i][0],queries[i][1]);

            if(max_idx==min_idx){
                ans.push_back(max_idx);
                continue;
            }

            if(arr[max_idx]>arr[min_idx]){
                ans.push_back(max_idx);
                continue;
            }


            int l=max_idx+1;
            int r=m-1;
            int result=-1;
            while(l<=r){
                int mid=l+(r-l)/2;

                int maximum=find(0,l,mid,0,m-1,arr);
                if(maximum!=-1 && arr[maximum]>max(arr[max_idx],arr[min_idx])){
                    r=mid-1;
                    result=maximum;
                }
                else l=mid+1;
            }
            ans.push_back(result);
        }
        return ans;
    }
};