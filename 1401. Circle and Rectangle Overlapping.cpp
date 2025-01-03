class Solution {
public:
    int sqr(int x) {
        return x*x;
    }
    
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));
        
        if (sqr(x-xCenter) + sqr(y-yCenter) <= sqr(radius)) return true;
        return false;
    }
};
