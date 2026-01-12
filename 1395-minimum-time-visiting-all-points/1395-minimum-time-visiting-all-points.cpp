class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        // current and aage wala point ek sath lena padega
        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            // points nikal lo
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];

            // x me kitna chalna hai
            int xdist = abs(x1 - x2);
            // y me kitna chalna hai
            int ydist = abs(y1 - y2);

            // ab maan lo x me 4 chalna hai and y me 6 chalna hai,toh best case
            // will be ki 4 diagonal me chale toh usse 4 in x and 4 in y
            // covered, rest x remaining=0, rest y remaining=6-4=2, ye y
            // direction me chal lenge mast, this way we have convered dist the
            // most efficient way

            // isse zyada efficient way nahi hai, since diagonal leta hai 
            int diag=min(xdist,ydist);

            // itna diagonal chal liya toh diag jitne secs add karo ans me
            ans+=diag;

            // ab x and y me remaining
            xdist-=diag;
            ydist-=diag;

            // ab jitna bacha kucha hai x,y direction me chal lo ek ek second leke

            // dono add karre hai since dono me se ek toh 0 ho gaya higa 
            ans+=xdist;
            ans+=ydist;
        }

        return ans;
    }
};