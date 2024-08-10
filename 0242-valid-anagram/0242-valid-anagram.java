class Solution {
    public boolean isAnagram(String s, String t) {
        char [] arrs=s.toCharArray();
        char [] arrt=t.toCharArray();

        int[] fors=new int[26];
        int[] fort=new int[26];

        for(char it:arrs){
            int val=it-'a';
            fors[val]++;
        }
        for(char it:arrt){
            int val=it-'a';
            fort[val]++;
        }

        for(int i=0;i<26;i++){
            if(fors[i]!=fort[i]){
                return false;
            }
        }

        return true;
    }
}