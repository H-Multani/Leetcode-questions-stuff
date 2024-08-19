class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        boolean[] gbool=new boolean[g.length];
        int gi=0,si=0;
        while(gi<g.length && si<s.length){
            if(g[gi]<=s[si]){
                gbool[gi]=true;
                gi++;
                si++;
            }
            else{
                si++;
            }
        }

        int truecnt=0;
        for(boolean it:gbool){
            if(it){
                truecnt++;
            }
        }

        return truecnt;

    }
}