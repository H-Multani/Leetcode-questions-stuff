class Solution {
    public static int[][] multiply(int[][] a,int[][] b){
        int[][] c=new int[2][2];

        c[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0]);
        c[0][1]=(a[0][0]*b[0][1])+(a[0][1]*b[1][1]);
        c[1][0]=(a[1][0]*b[0][0])+(a[1][1]*b[1][0]);
        c[1][1]=(a[1][0]*b[0][1])+(a[1][1]*b[1][1]);
        return c;
    }
    public static int[][] pow(int[][] M, int exp){
        if(exp==0){
            // return identity matrix
            int[][] I={{1,0},{0,1}};
            return I;
        }
        int[][] half=pow(M,exp/2);
        int[][] res=multiply(half,half);


        if(exp%2==1){
            res=multiply(M,res);
        }

        return res;

    }
    public static int solvematrix(int n){

        if(n==0 || n==1) return n;

        int[][] T={{1,1},{1,0}};
        int[][] F={{1,0},{0,0}};
        int[][] res=pow(T,n-1);

        res= multiply(res,F);

        return res[0][0];
    }
    public int fib(int n) {
        return solvematrix(n);
    }
}