class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        if(initial == color)
            return image;
        queue <pair<int, int>> q;
        q.push(make_pair(sr, sc));
        image[sr][sc] = color;
        pair<int, int> p;
        while(!q.empty()){
            p = q.front();
            int r = p.first, c = p.second;
            q.pop();
            
            if(r > 0 && image[r-1][c] == initial){
                q.push(make_pair(r-1, c));
                image[r-1][c] = color;
            }

            if(c > 0 && image[r][c - 1] == initial){
                q.push(make_pair(r, c-1));
                image[r][c-1] = color;
            }


            if(r < image.size()-1 && image[r+1][c] == initial){
                q.push(make_pair(r+1, c));
                image[r+1][c] = color;
            }

            if(c < image[0].size()-1 && image[r][c+1] == initial){
                q.push(make_pair(r, c+1));
                image[r][c+1] = color;
            }
        }
        return image;
    }
};
