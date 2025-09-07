class Solution {
public:
    vector<int>st;
    void buildTree(int i,int lo,int hi,vector<int>&arr){// here we build tree of indexes as we want ans in index
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

    int find(int i,int l,int r,int lo,int hi,vector<int>&arr){//  here we find index that has maximum value in renge of l,r
        if(r<lo || hi<l) return INT_MIN;
        else if(lo>=l && r>=hi) return st[i];

        int mid=lo+(hi-lo)/2;

        int left=find(2*i+1,l,r,lo,mid,arr);
        int right=find(2*i+2,l,r,mid+1,hi,arr);
        if(left==INT_MIN) return right;
        if(right==INT_MIN) return left;
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
        for(int i=0;i<n;i++){// find for every query
            int max_idx=max(queries[i][0],queries[i][1]);// as queries can also be 0,1  and 1,0 both
            int min_idx=min(queries[i][0],queries[i][1]);

            if(max_idx==min_idx){// if same then they already met
                ans.push_back(max_idx);
                continue;
            }

            if(arr[max_idx]>arr[min_idx]){// if greater value has greater index means they can meet there
                ans.push_back(max_idx);
                continue;
            }


            int l=max_idx+1;
            int r=m-1;
            int result=-1;
            while(l<=r){// now between l and r these is no index so start from maxidx+1 ro end and check l to mid maxindex id some elemet is greater if yes be greedy go more left else go right tere might be some value
                int mid=l+(r-l)/2;

                int maximum=find(0,l,mid,0,m-1,arr);
                if(maximum!=INT_MIN && arr[maximum]>max(arr[max_idx],arr[min_idx])){
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