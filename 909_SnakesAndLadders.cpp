class Solution {
public:
    struct Node {
        int x, y;
        int dist;
    };
    
    // Convert from coordinate to cell number.
    int to_cell(int x, int y, int n) {
        return (n-1-x) % 2 == 1 ? (n-x)*n - y : (n-x-1)*n + y + 1;
    }
    
    // Convert cell number to coordinate.
    pair<int, int> to_coordinate(int cell, int n) {
        int x = (n*n - cell) / n;
        int y = ((n-1) - x) % 2 == 0 ? (cell-1) % n : (n-1 - (cell-1)%n);
        return {x , y};
    }
    
    void test_converter(int n) {
        cout << "Convert from coordinates to cell numbers:" << endl;
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                cout << to_cell(i, j, n) << " ";
            }
            cout << endl;
        }
        
        cout << "Convert from cell numbers to coordinates: " << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto p = to_coordinate(i*n + j + 1, n);
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        //test_converter(n);
        
        queue<Node> frontier;
        unordered_set<int> visited; // Set of visited cells.
        frontier.push(Node{n-1, 0, 0});
        visited.insert(to_cell(n-1, 0, n));
        
        while (!frontier.empty()) {
            Node node = frontier.front();
            frontier.pop();
            int cell = to_cell(node.x, node.y, n);
            
            if (cell == n*n) {
                return node.dist;
            }
            
            // Consider 6 possible moves.
            for (int i = 1; i <= 6; ++i) {
                if (cell + i <= n*n) {
                    pair<int,int> coor = to_coordinate(cell + i, n);
                    int val = board[coor.first][coor.second];
                    
                    if (val >= 1 && val <= n*n) {
                        if (visited.find(val) == visited.cend()) {
                            coor = to_coordinate(val, n);
                            frontier.push(Node{coor.first, coor.second, node.dist + 1});
                            visited.insert(val);
                        } 
                    } else if (visited.find(cell + i) == visited.cend()) {
                        frontier.push(Node{coor.first, coor.second, node.dist + 1});
                        visited.insert(cell + i);
                    }
                }
            }
        }
        
        return -1;
    }
};
