class TicTacToe {
private:
    int n;
    vector<vector<int>> board;
    
    // For the second solution.
    vector<int> player1_rows;
    vector<int> player1_columns;
    vector<int> player1_diagonals;
    vector<int> player2_rows;
    vector<int> player2_columns;
    vector<int> player2_diagonals;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        board.resize(n, vector<int>(n, 0));
        
        // For the second solution.
        player1_rows.resize(n, 0);
        player1_columns.resize(n, 0);
        player1_diagonals.resize(2, 0);
        player2_rows.resize(n, 0);
        player2_columns.resize(n, 0);
        player2_diagonals.resize(2, 0);
    }
    
    enum class CheckType {
        ROW, 
        COLUMN,
        FORWARD_DIA,
        BACKWARD_DIA
    };
    
    int check_rows_columns(CheckType type) {
        for (int i = 0; i < n; ++i) {
            bool player1_win = true, player2_win = true;
            for (int j = 0; j < n; ++j) {
                if ((type == CheckType::ROW? board[i][j] : board[j][i]) == 0) {
                    player1_win = false;
                    player2_win = false;
                } else if ((type == CheckType::ROW? board[i][j] : board[j][i]) == 1) {
                    player2_win = false;
                } else {
                    player1_win = false;
                }
                if (!player1_win && !player2_win) break;
            }
            if (player1_win) return 1;
            if (player2_win) return 2;
        }
        
        return 0;
    }
    
    int check_diagonals(CheckType type) {
        bool player1_win = true, player2_win = true;
        for (int i = 0; i < n; ++i) {
            if ((type == CheckType::FORWARD_DIA? board[i][i] : board[i][n-1-i]) == 0) {
                player1_win = false;
                player2_win = false;
            } else if ((type == CheckType::FORWARD_DIA? board[i][i] :board[i][n-1-i]) == 1) {
                player2_win = false;
            } else {
                player1_win = false;
            }
            if (!player1_win && !player2_win) break;
        }
        if (player1_win) return 1;
        if (player2_win) return 2;
        return 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            if (++player1_rows[row] == n) return 1;
            if (++player1_columns[col] == n) return 1;
            if ((row == col && ++player1_diagonals[0] == n) || 
               (row == n-1-col && ++player1_diagonals[1] == n)) return 1;
        } else {
            if (++player2_rows[row] == n) return 2;
            if (++player2_columns[col] == n) return 2;
            if ((row == col && ++player2_diagonals[0] == n) || 
               (row == n-1-col && ++player2_diagonals[1] == n)) return 2;
        }
        
        return 0;
    }
    
    int move1(int row, int col, int player) {
        board[row][col] = player;
        
        int ret = check_rows_columns(CheckType::ROW);
        if (ret != 0) return ret;
        ret = check_rows_columns(CheckType::COLUMN);
        if (ret != 0) return ret;
        ret = check_diagonals(CheckType::FORWARD_DIA);
        if (ret != 0) return ret;
        ret = check_diagonals(CheckType::BACKWARD_DIA);
        if (ret != 0) return ret;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
