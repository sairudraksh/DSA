class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n=strs.length;

        HashMap<String,List<String>>map=new HashMap<>();

        for(int i=0;i<n;i++){
            String s=strs[i];
            char[] arr=s.toCharArray();
            Arrays.sort(arr);
            String ans=new String(arr);

            if(!map.containsKey(ans)){
                map.put(ans,new ArrayList<>());
            }
            map.get(ans).add(strs[i]);
        }
        return new ArrayList<>(map.values());
    }
}