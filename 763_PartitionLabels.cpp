class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        vector<int> partitions; // Starting index of each partition.
        
        int in_partition[26] = {-1}; // Partitions corresponding to characters.
        fill(in_partition, in_partition + 26, -1);
        int start = 0; // Starting index of the current partition.
        int partition = 0; // Current partition.
        
        for (int i = 0; i < S.size(); ++i) {
            if (i == start) {
                in_partition[S[i] - 'a'] = partition;
                partitions.push_back(start);
            } else {
                if (in_partition[S[i] - 'a'] == -1) {
                    start = i;
                    ++partition;
                    in_partition[S[i] - 'a'] = partition;
                    partitions.push_back(start);
                } else {
                    int par = in_partition[S[i] - 'a'];
                    start = partitions[par];
                    while (par < partition) {
                        partitions.pop_back();
                        --partition;
                    }
                    
                    for (int j = i; j > start; --j) {
                        in_partition[S[j] - 'a'] = par;
                    }
                }
            }
        }
        
        partitions.push_back(S.size());
        for (int i = 1; i < partitions.size(); ++i) {
            ret.push_back(partitions[i] - partitions[i-1]);
        }
        return ret;
    }
};
