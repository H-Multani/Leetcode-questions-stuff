class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        // prefix product le sakte hai and mod nikalte chalna

        // ek option ye hai ki pure grid ka product lelo and element divide kar
        // lena, lekin fir division me mod lagana is not my piece of cake,
        // fermats theorem lagaega, nai lagana toh prefix lelo,

        // 2 arrays banano left and right of size n*m each, product bhar do

        // left[i] is product of all elements from (0,0) to (x,y) where
        // i=(x*n)+y(this is formula to convert 2d array to id using indexes)

        // right[i] is product of all elements from (x,y) to (m-1,n-1) where
        // i=(x*n)+y (this is formula to convert 2d array to id using indexes)

        // grid[i] ke liye ans hoga left[i-1]*right[i+1], ie start se left tak
        // walo ka product, and right se end tak walo ka product

        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        vector<long long> left(m * n);
        vector<long long> rt(m * n);

        // initial values se bhar do dono prefix arrays ko
        left[0] = grid[0][0];
        rt[(m * n) - 1] = grid[m - 1][n - 1];

        // ab bhar do elements, normal iterate karo and bharte jao, koi complex
        // logic nai lagana index ke liye, bas idx i lete jao and element daalte
        // jao
        int idx = 1;

        // pefle left wala prefix array bhar do
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // left ka first element le chuke toh skip kardo yehi se
                if (i == 0 && j == 0)
                    continue;

                // ab left[idx] me daal do left[idx-1]*grid[i][j]
                left[idx] = (left[idx - 1] * grid[i][j]) % mod;

                // agle idx par chal lo
                idx++;
            }
        }
        // this is much easier than doing (i*m)+j for index of left array
        // lekin agar karna hota toh kuch aisa karta
        // left[(i*n)+j]=left[(i*n)+j-1]*grid[i][j];
        // itna complicated kon banae

        // same logic chal do reverse me for right wala subarray
        idx = (m * n) - 2;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // right ka last element le chuke toh skip kardo yehi se
                if (i == m - 1 && j == n - 1)
                    continue;

                // element bhar do
                rt[idx] = (rt[idx + 1] * grid[i][j]) % mod;

                // idx badha do
                idx--;
            }
        }

        // left is
        // cout<<"left "<<endl; 
        // for(auto it:left){
        //     cout<<it<<" ";
        // }
        // // rt is
        // cout<<"rt "<<endl; 
        // for(auto it:rt){
        //     cout<<it<<" ";
        // }

        // ab dono prefix arrays bhar chuke hai,

        // original array ko hi badal do, by applying the following formula

        // grid[i][j] = left[i*n+j-1]*rt[i*n+j+1]

        // since left[i] represents product of elements from (0,0) to (x,y)
        // where i=(x*n)+y

        // since rt[i] represents product of elements from (x,y) to (m-1,n-1)
        // where i=(x*n)+y

        // toh ans for grid[i][j] will be left[i*n+j-1] * rt[i*n+j+1], ie (i,j)
        // se pehle tak ka product, and (i,j) se end tak ka product not
        // including (i,j) wala element

        // first and last elements ke liye rt[1] and left[m*n-2] laga dena respectively

        // starting values ka mod lena na bhulna
        grid[0][0]=rt[1]%mod;
        grid[m-1][n-1]=left[(m*n)-2]%mod;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // first and last element ke liye case likh chuke, skip here
                if(i==0 && j==0) continue;
                if(i==m-1 && j==n-1) continue;
                grid[i][j]= (left[(i*n) + j -1]*rt[(i*n)+j+1])%mod;
            }
        }

        return grid;
    }
};