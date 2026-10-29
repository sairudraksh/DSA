class Solution {
    public int lengthOfLongestSubstring(String s) {

        HashMap<Character,Integer>map=new HashMap<>();

        int n=s.length();

        int i=0;
        int j=0;
        int len=0;
        int maxlen=0;
        while(j<n){
            int val=map.getOrDefault(s.charAt(j),0);
            map.put(s.charAt(j),val+1);
            while(map.getOrDefault(s.charAt(j),0)>1){
                int val1=map.getOrDefault(s.charAt(i),0);
                map.put(s.charAt(i),val1-1);
                i++;
            }
            len=j-i+1;
            maxlen=Math.max(maxlen,len);
            j++;

        }
        return maxlen;
    }
}