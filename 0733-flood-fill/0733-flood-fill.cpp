class Solution {
public:
    void FloodFill4(vector<vector<int>>& image, int x, int y,int oldcolor, int newcolor){
        // boundry check
        if(x <0 || y < 0 || x >= image.size() || y >= image[0].size()){
            return;
        }

        // if this pixel is not the oldcolor ---> then return
        if(image[x][y] != oldcolor){
            return;
        }

        // otherwise paint the pixel with newcolor
        image[x][y] = newcolor;

        // go to 4 neighbour
        FloodFill4(image, x+1, y, oldcolor, newcolor);
        FloodFill4(image, x-1, y, oldcolor, newcolor);
        FloodFill4(image, x, y+1, oldcolor, newcolor);
        FloodFill4(image, x, y-1, oldcolor, newcolor);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];

        if(oldcolor == color){
            return image;
        }

        FloodFill4(image, sr, sc, oldcolor, color);

        return image;
    }
};