class FindSumPairs {
public:
    unordered_map<int,int>map;
    vector<int>n2;
    vector<int>n1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        for(int i=0;i<nums2.size();i++){
            map[nums2[i]]++;
        }
    }
    void add(int index, int val) {
        map[n2[index]]--;
        if(map[val]==0){
            map.erase(val);
        }
        int ans=n2[index]+val;
        n2[index]=ans;
        map[ans]++;
    }
    int count(int tot) {
        int count=0;
        for(int i=0;i<n1.size();i++){
            int rem=tot-n1[i];
            if(map.find(rem)!=map.end()){
                count+=map[rem];
            }
        }
        return count;
    }
};