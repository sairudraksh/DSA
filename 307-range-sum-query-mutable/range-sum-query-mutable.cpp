class NumArray {
public:
    vector<int>arr;
    vector<int>st;
    void buildTree(vector<int>&arr,int i,int lo,int hi){
        if(lo==hi){
            st[i]=arr[lo];
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(arr,2*i+1,lo,mid);
        buildTree(arr,2*i+2,mid+1,hi);
        st[i]=st[2*i+1]+st[2*i+2];
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        int n=nums.size();
        st.resize(4*n);
        buildTree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        int n=arr.size();
        updateValue(0,0,n-1,index,val);
    }
    void updateValue(int i,int lo,int hi,int &index,int &val){
        if(lo==hi){
            st[i]=val;
            return;
        }

        int mid=lo+(hi-lo)/2;

        if(index<=mid) updateValue(2*i+1,lo,mid,index,val);
        else updateValue(2*i+2,mid+1,hi,index,val);
        st[i]=st[2*i+1]+st[2*i+2];
    }
    int find(int l,int r,int i,int lo,int hi){
        if(l<=lo && hi<=r) return st[i];

        if(r<lo || l>hi) return 0;
        
        int mid=lo+(hi-lo)/2;

        int a=find(l,r,2*i+1,lo,mid);
        int b=find(l,r,2*i+2,mid+1,hi);

        return a+b;
    }

    int sumRange(int left, int right) {
        return find(left,right,0,0,arr.size()-1);
    }
};