class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        // make a queue store the pairs which have the value same as the color
        queue<pair<int, int>> q;
        // store the original target value and then change it to the color value
        int original_value = image[sr][sc];

        if (original_value == color) return image;

        image[sr][sc] = color;
        q.push({sr, sc});
        

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            int size = q.size();

            for(int k = 0; k < size; ++k){
                // take out the front ele from the queue
                auto [i, j] = q.front();
                q.pop();

                for(auto [di, dj] : directions){
                    int ni = i + di, nj = j + dj;

                    // now we can check for the adjacent ones
                    if(ni >=0 && ni < n && nj >= 0 && nj < m && image[ni][nj] == original_value){
                        // then change the value to color
                        image[ni][nj] = color;
                        // then push that into the queue
                        q.push({ni, nj});
                    }
                }
            }
        }

        // now the image should be ready 
        return image;
    }
};