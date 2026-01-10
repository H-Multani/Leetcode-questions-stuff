class Solution {
public:
    int m, n;

    int memo[1001][1001];

    // recursive funcn likh do
    int solve(int i, int j, string& s1, string& s2) {
        // edge case
        if (i >= m && j >= n) {
            // reached end of both strings return 0
            return 0;
        }

        // agar iss (i,j) ka ans pehle se hai toh return kardo
        if (memo[i][j] != -1)
            return memo[i][j];
        // neeche nai check kiya kyuki vapas kon baar baar exploration karega ek
        // baar karke done karo

        if (i >= m) {
            // reached end of one string(s1), s2 se abhi characters nikal sakte
            // hai nikal lo jitne nikal sakte
            memo[i][j] = s2[j] + solve(i, j + 1, s1, s2);
             return memo[i][j];
            // solve me j+1 since current character remove kar diya, agar j+1
            // par aur character honge toh nikalte jaenge, yaha loop laga kar
            // same ascii values add kar sakte the s2 ki lekin ab funcn call me
            // aata hi jayega toh why make separate logic here

            // ans bhejne se pehle memo update kar dena
        }
        if (j >= n) {
            // reached end of one string(s2), s1 se abhi characters nikal sakte
            // hai nikal lo jitne nikal sakte
            memo[i][j] = s1[i] + solve(i + 1, j, s1, s2);
            return memo[i][j];
            // solve me i+1 since current character remove kar diya, agar i+1
            // par aur character honge toh nikalte jaenge, yaha loop laga kar
            // same ascii values add kar sakte the s1 ki lekin ab funcn call me
            // aata hi jayega toh why make separate logic here

            // ans bhejne se pehle memo update kar dena
        }

        // we here means dono strings ke end par nai pahuche hai apan

        // here we have 2 options,

        // agar i and j th char same hai ie s1[i]==s2[j] means common hai string
        // nothing to delete no ascii to add here, in such case i+1 and j+1
        // explore karlo and bhej dena ans
        if (s1[i] == s2[j]) {

            // ans bhejne se pehle memo update
            memo[i][j] = solve(i + 1, j + 1, s1, s2);
            return memo[i][j];
        }

        // we here means same characters nahi hai here we have 2 options, first
        // is to remove i th character from s1 and explore aage (i+1,j), other
        // option is remove j th character from s2 and explore (i,j+1) wala path

        // i th wala remove kardo
        int remove_i = s1[i] + solve(i + 1, j, s1, s2);
        // j th wala remove kardo
        int remove_j = s2[j] + solve(i, j + 1, s1, s2);

        // ab dono paths se jo bhi minm ans dene wala path mila hai bhej do

        // ans bhejne se pehle memo update
        memo[i][j] = min(remove_i, remove_j);
        return min(remove_i, remove_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        // TLE de dega memo laga do, (i,j) change hora bass 2D dp is sufficient,
        // max size can be 1000, toh 1001 size ka array lelo

        // memo me start me saare -1 bhar do
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, s1, s2);
    }
};