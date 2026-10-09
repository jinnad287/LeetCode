class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        // already at the target
        if(sr == tr && sc == tc){
            return 0;
        }

        // same row or same column
        if(sr == tr || sc == tc){
            return 1;
        }

        // same diagonal
        if(abs(sr - tr) == abs(sc - tc)){
            return 1;
        }

        // otherwise, reach the target in two moves
        return 2;
    }
};