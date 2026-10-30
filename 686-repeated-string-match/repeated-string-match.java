class Solution {
    public int repeatedStringMatch(String a, String b) {
        int num=b.length();
        String org=a;
        int count=1;
        while(a.length()<num){
            if(a.contains(b)){
                return count;
            }
            a+=org;
            count++;
        }
        if(a.contains(b)){
            return count;
        }
        a+=org;
        count++;
        if(a.contains(b)){
                return count;
            }
        return -1;
    }
}