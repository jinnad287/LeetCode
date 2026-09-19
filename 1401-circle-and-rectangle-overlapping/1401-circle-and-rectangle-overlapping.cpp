class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX, closestY;
        // finding the closest point of the square to the circle

        // find closest x
        if(xCenter - x1 < 0 && xCenter - x2 < 0){
            closestX = x1;
        }
        else if(xCenter - x1 > 0 && xCenter - x2 > 0){
            closestX = x2;
        }
        else{
            closestX = xCenter;

        }

        // find closest y
        if(yCenter - y1 < 0 && yCenter - y2 < 0){
            closestY = y1;
        }
        else if(yCenter - y1 > 0 && yCenter - y2 > 0){
            closestY = y2;
        }
        else{
            closestY = yCenter;
        }


        return hypot(xCenter - closestX, yCenter - closestY)  <= radius;

    }
};