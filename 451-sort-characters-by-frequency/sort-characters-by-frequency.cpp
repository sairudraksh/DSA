class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>v(123);

        for(char &ch:s){
            int freq=v[ch].second;// here ch will automativallly be converted to  its asciivalue
            v[ch]={ch,freq+1};// make vector of character wrt to their frequency
        }// here in pair of vector like this it  by default set its value to 0; 

        auto lambda=[&](pair<char,int> &p1,pair<char,int> &p2){
            return p1.second>p2.second;// it will sort on the basic of frequency with the help of custom comparator
        };
        sort(v.begin(),v.end(),lambda);

        string result="";
        for(int i=0;i<=122;i++){
            if(v[i].second>0){
                int freq=v[i].second;
                char ch=v[i].first;
                string s=string(freq,ch);// this will directly make the string
                result+=s;
            }
        }
        return result;
    }
};