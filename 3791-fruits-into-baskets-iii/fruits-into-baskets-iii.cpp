class Solution {
public:
    vector<int>st;
    void buildTree(int i,int lo, int hi,vector<int>& arr){// tree of index builded
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
    int findRange(int i,int lo,int hi,int l, int r,vector<int>&arr){

        if(l>hi || r<lo) return -1;
        if(lo>=l && hi<=r) return st[i];

        int mid=lo+(hi-lo)/2;

        int leftMax=findRange(2*i+1,lo,mid,l,r,arr);
        int rightMax=findRange(2*i+2,mid+1,hi,l,r,arr);
        if(leftMax==-1) return rightMax;
        if(rightMax==-1) return leftMax;

        if(arr[leftMax]>=arr[rightMax]){
            return leftMax;
        }
        else return rightMax;
    }
    void update(int i,int lo,int hi,int index,int value,vector<int>&arr){
        if(lo==hi){
            arr[index] = value;
            st[i] =value;
            return;
        }
        int mid=lo+(hi-lo)/2;
        if(index<=mid) update(2*i+1,lo,mid,index,value,arr);
        else update(2*i+2,mid+1,hi,index,value,arr);

        if(st[2*i+1]==-1){
            st[i]=st[2*i+2];
            return;
        }
        if(st[2*i+2]==-1){
            st[i]=st[2*i+1];
            return;
        }

        if(arr[st[2*i+1]]>=arr[st[2*i+2]]){
            st[i]=st[2*i+1];
        }
        else st[i]=st[2*i+2];
        
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        st.resize(4*n);
        buildTree(0,0,n-1,baskets);
        int count=0;
        for(int i=0;i<n;i++){
            int x=fruits[i];

            int l=0;
            int hi=n-1;
            int result=-1;
            while(l<=hi){
                int mid=l+(hi-l)/2;
                int maximum=findRange(0,0,n-1,l,mid,baskets);
                if(maximum==-1 || baskets[maximum]<x){
                    l=mid+1;
                }
                else{
                    result=maximum;
                    hi=mid-1;
                }
            }
            if(result!=-1){
                count++;
                update(0,0,n-1,result,-1,baskets);
            }
        }
        return n-count;
    }
};