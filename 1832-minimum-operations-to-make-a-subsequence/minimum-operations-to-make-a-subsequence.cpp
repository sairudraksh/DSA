class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
       unordered_map<int,int>map;
       for(int i=0;i<target.size();i++){
        map[target[i]]=i;
       } 

       vector<int>v;
       for(int i=0;i<arr.size();i++){
        int num=arr[i];
        if(map.count(num)){
            v.push_back(map[num]);
        }
       }
        if(v.size()==0) return target.size();
       vector<int>temp;

       temp.push_back(v[0]);
       for(int i=1;i<v.size();i++){
        int num=v[i];
        if(num>temp[temp.size()-1]){
            temp.push_back(num);
        }
        else{
            int idx= lower_bound(temp.begin(), temp.end(), num) - temp.begin();
            temp[idx]=num;
        }
       }
       return target.size()-temp.size();
    }
};