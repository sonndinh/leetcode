class Solution {
public:
    // Transform the cells until it returns back to the original state.
    int days_until_repeat(const vector<int>& copy, vector<int>& cells, int N) {
        int iter = 1;
        while (iter <= N) {
            int prev = cells[0], curr = cells[1];
            cells[0] = 0;
            for (int j = 1; j < 7; ++j) {
                if (prev == cells[j+1])
                    cells[j] = 1;
                else 
                    cells[j] = 0;
                
                prev = curr;
                curr = cells[j+1];
            }
            cells[7] = 0;
            
            if (cells == copy) {
                return iter;
            }
            ++iter;
        }
        return N;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N <= 0) return cells;
        
        int prev = cells[0], curr = cells[1];
        cells[0] = 0;
        for (int i = 1; i < 7; ++i) {
            if (prev == cells[i+1])
                cells[i] = 1;
            else
                cells[i] = 0;
            
            prev = curr;
            curr = cells[i+1];
        }
        cells[7] = 0;
        --N;
        
        vector<int> copy(cells);
        int days = days_until_repeat(copy, cells, N);
        if (days == N)
            return cells;
        
        N -= days;
        N = N % days;
        days_until_repeat(copy, cells, N);
        
        return cells;
    }
};
