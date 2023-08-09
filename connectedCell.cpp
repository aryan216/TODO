vector<vector<int>> deltas = {{1,1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int r, int c, vector<vector<int>>& matrix) {
    matrix[r][c] = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    int out = 1;
    for (auto delta:deltas) {
        int R = r + delta[0];
        int C = c + delta[1];
        if (R >= 0 and R < n and C >= 0 and C < m) {
            if (matrix[R][C] == 1) {
                out += dfs(R, C, matrix);
            }
        }
    }
    return out;
}

int connectedCell(vector<vector<int>> matrix) {
    int out = 0;
    for (unsigned int r = 0; r < matrix.size(); r++) {
        for (unsigned int c = 0; c < matrix[0].size(); c++) {
            if (matrix[r][c] == 1) {
                out = std::max(dfs(r, c, matrix), out);
            }
        }
    }
    return out;
}
