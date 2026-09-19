class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx,ny;
        if(x1>xCenter) nx = x1;
        else if(x2<xCenter) nx = x2;
        else nx = xCenter;

        if(y1>yCenter) ny = y1;
        else if(y2<yCenter) ny = y2;
        else ny = yCenter;

        long long d2 = (nx - xCenter)*(nx - xCenter)+(ny - yCenter)*(ny - yCenter);
        long long r2 = radius*radius;

        if(d2<=r2) return true;
        else return false;
    }
};