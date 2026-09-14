class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 bottom-left (Ax, Ay) and top-right (Cx, Cy)
        int Ax = rec1[0];   
        int Ay = rec1[1];   
        int Cx = rec1[2];
        int Cy = rec1[3];

        // rec2 bottom-left (Px, Py) and top-right (Rx, Ry)
        int Px = rec2[0];   
        int Py = rec2[1];   
        int Rx = rec2[2];
        int Ry = rec2[3];

        // Overlap occurs if their X-ranges and Y-ranges overlap simultaneously
        bool xOverlap = max(Ax, Px) < min(Cx, Rx);
        bool yOverlap = max(Ay, Py) < min(Cy, Ry);

        return xOverlap && yOverlap;
    }
};