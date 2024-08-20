class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int gi=0,si=0;
        int cnt=0;

        while(gi<g.length && si<s.length){
            int need=g[gi];
            int cookie=s[si];
            if(need<=cookie){
                cnt++;
                gi++;
                si++;
            }
            else{
                si++;
            }
        }

        return cnt;

    }
}