class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int len=bottomLeft.size();
        long long max_Area=-1;
        // we loop thru the given coordinates using i and j 
        // use 2 coordinates sicne we have to compare the coordinates
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                // to get square we have to get the maximum x and minimum x that we can use
                // we also have to make sure that the rectangles coincide

                // we take min x= maxm since the minm x coordinate we can use for square is the maxm x coordinate of the sqares being compared
                // this is bcoz when we compare the 2 sqaures, the square that has the bigger bottom left x coordinate will dictate the x coordinate of our reqd square
                // this is since the bigger x cood square is more ahead of the smaller x cood square and since our square needs coincide of both hence we do max of the 2 x coordinates of the
                // 2 squares, we compare the bottom left since bottom left is where the square starts, if we were to compare the topright then thats wrong since topright ke x cood ke peeche bhi 
                // square ka hissa hai, lekin bottom left cood ke x ke peeche square ka koi part nahi hai   

                //since we finding the min x therfore agar compared values ke peeche koi bhi square ka prt hai, then what were calculating is clearly not the minm x 
                //since theres part of the square that we havent touched that could be the reason for having a bigger result square, hence we use bottomleft since uske peeche kuch square ka prt nhi hai
                // hence all square areas are taken into consideration 
                int min_x=max(bottomLeft[i][0],bottomLeft[j][0]);
                
                // we take max x= minm since the maxm x coordinate we can use for square is the minm x coordinate of the sqares being compared
                // this is bcoz when we compare the 2 sqaures, the square that has the smaller bottom left x coordinate will dictate the x coordinate of our reqd square
                // this is since the smaller x cood square is more behind of the bigger x cood square and since our square needs coincide of both hence we do minm of the 2 x coordinates of the
                // 2 squares, we compare the top right since top right is where the square ends, if we were to compare the bottomleft then thats wrong since bottomleft ke x cood ke aage bhi 
                // square ka hissa hai, lekin topright cood ke x ke aage square ka koi part nahi hai,

                //since we finding the max x therfore agar compared values ke aage koi bhi square ka prt hai, then what were calculating is clearly not the maxm x 
                //since theres part of the square that we havent touched that could be the reason for having a bigger result square, hence we use topright since uske aage kuch square ka prt nhi hai 
                // hence all square areas are taken into consideration 
                int max_x=min(topRight[i][0],topRight[j][0]);

                //now we have the max value of x we can use,that is dictated by the square thats ahead
                //and we have the min value of x we can use,that is dictated by the square thats behind

                // we do similarly with the y coordinate, but instead of min x we do min y, and insted of checking the 0th index we check 1st index
                int min_y=max(bottomLeft[i][1],bottomLeft[j][1]);
                int max_y=min(topRight[i][1],topRight[j][1]);


                // now we chek if the minm x is less than maxm x, bcoz if not then that means jo minm x le sakte hai apan vo maxm x ke value ke aage hai, so we cant make a square
                // similarly with the y coordinate
                if(min_x<max_x && min_y<max_y){
                    // since we need biggest side for the square
                    // the diff bw the min_x and max_x is the biggest value of square side that we can take in the x axis, since we can start with minm-x and end on maxm-x
                    // hence if we take all the possible values means we will get biggest square side by default
                    // similarly with the y axis
                    // the diff bw the min_y and max_y is the biggest value of square side that we can take in the y axis, since we can start with minm-y and end on maxm-y
                    // hence if we take all the possible values means we will get biggest square side by default

                    // we do this since square is in both axis, we cant just get the max of the 2 differences and get square side since that square will overflow the common area which is wrong

                    // so by this diff we have got the 2 values possible for biggest square on the x and y axis
                    // its like if we have got a rectangle that has its length as the diff of x values and breadth as the diff of y values

                    // and this rectangle is also the common area of both the squares , we have to make s square of max side length in the rectangle
                    // so for eg if maxx-minx=4 and maxy-miny=3 , then thats a rectangle of 4x3, the biggest square that we can make is of side 3, since a square of side 4 will overflow the rectangle
                    // and hence overflow the common area, and hence it will be wrong
                    //hence
                    long long side_length=min(max_x-min_x,max_y-min_y);

                    // compare current area with maxm area and update if greater
                    max_Area=max(max_Area,side_length*side_length);
                }

            }
        }
        if(max_Area==-1) return 0;
        return max_Area;
    }
};