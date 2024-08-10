class Solution {
    public int firstUniqChar(String s) {
        char[] snew=s.toCharArray();

        int len=snew.length;
        int[] freq=new int[26];

        for(char it:snew){
            int val=it-'a';
            freq[val]++;
        }

        for(int i=0;i<len;i++){
            int val=snew[i]-'a';
            if(freq[val]==1){
                return i;
            }
        }

        return -1;
    }
}