class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        if(original_color==color){
            return image;
        }
        queue<pair<int , int>>Q;
        Q.push({sr , sc});
        image[sr][sc] = color;
        vector<int>rows = {-1,1,0,0};
        vector<int>cols = {0,0,1,-1};
        while(!Q.empty()){
            auto [r , c] = Q.front();
            Q.pop();
            for (int i = 0 ; i < 4 ; i++){
                int nr = r + rows[i];
                int nc = c + cols[i];
                if (nr>=0 && nr<image.size()&&nc>=0&&nc<image[0].size()&&image[nr][nc]==original_color){
                    image[nr][nc] = color;
                    Q.push({nr , nc});
                }
            }
        }
        return image;
    }
};
