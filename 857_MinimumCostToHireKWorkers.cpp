class Solution {
public:
    struct FactorCompare {
        bool operator() (const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
        }
    };
    
    struct QualityCompare {
        bool operator() (const pair<int, double>& a, const pair<int, double>& b) {
            return a.first < b. first;
        }
    };
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        // Min heap. Top element has smallest wage per quality unit.
        // Each pair contains quality and wage per quality unit for a worker.
        priority_queue<pair<int, double>, vector<pair<int, double>>, FactorCompare> heap;
        for (int i = 0; i < n; ++i) {
            heap.push({quality[i], (double)wage[i]/quality[i]});
        }
        
        double min_pay = numeric_limits<double>::max();
        int sum_quality = 0;
        // Store the list of current workers. Top one has largest quality.
        priority_queue<pair<int, double>, vector<pair<int, double>>, QualityCompare> max_quality;
        
        while (!heap.empty()) {
            auto p = heap.top();
            heap.pop();
            if (max_quality.size() < K) {
                sum_quality += p.first;
                max_quality.push(p);
                if (max_quality.size() == K) {
                    min_pay = min(min_pay, sum_quality * p.second);
                }
            } else {
                // Remove the worker with largest wage per quality unit.
                sum_quality -= max_quality.top().first;
                sum_quality += p.first;
                max_quality.pop();
                max_quality.push(p);
                min_pay = min(min_pay, sum_quality * p.second);
            }
        }
        
        return min_pay;
    }
    
    
    // Time O(n^2lgn), space O(n) where n is the total number of workers.
    double mincostToHireWorkers1(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<double> pays;
        double min_total = numeric_limits<double>::max();
        int count_num_fail = 0;
        
        for (int i = 0; i < n; ++i) {
            pays.clear();
            pays.push_back(wage[i]);
            count_num_fail = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    double temp = ((double)wage[i] / quality[i]) * quality[j];
                    if (temp < wage[j]) {
                        ++count_num_fail;
                        if (count_num_fail > n - K)
                            break;
                    } else {
                        pays.push_back(temp);
                    }
                }
            }
            
            if (count_num_fail <= n - K) {
                sort(pays.begin()+1, pays.end());
                min_total = min(min_total, accumulate(pays.begin(), pays.begin()+K, 0.0));
            }
        }
        
        return min_total;
    }
};
