#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
using namespace std;


class Solution {
private:
    vector<int> input;
    int n;
	unsigned seed;
	std::mt19937 gen;
    
public:
    Solution(vector<int>& nums) : input{nums} {
		n = nums.size();
		seed = std::chrono::system_clock::now().time_since_epoch().count();
		gen = std::mt19937(seed);		
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return input;
    }
    
    vector<int> shuffle() {
        vector<int> ret(input);

        for (int i = 0; i < n; ++i) {
            int offset = gen() % (n - i);
            swap(ret[i], ret[i + offset]);
        }
        return ret;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle1() {
        vector<int> ret(n);
        vector<int> temp(input);
        int last = n - 1;
        srand(time(NULL));
        int write_idx = 0;
        
        for (int i = 0; i < n; ++i, ++write_idx, --last) {
            // Pick an random number from indexes range [0:last] and insert 
            // to the return array.
            int read_idx = rand() % (last+1);
            ret[write_idx] = temp[read_idx];
            swap(temp[read_idx], temp[last]);
        }
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


int main() {
	vector<int> nums{-6, 10, 184};
	Solution sol(nums);
	fstream fs("input.txt");
	string token;
	vector<string> commands;
	
	while (getline(fs, token, ',')) {
		commands.push_back(token);
	}

	fstream ofs("output.txt");
	string output;
	for (string command : commands) {
		vector<int> ret;
		if (command == "\"shuffle\"") {
			ret = sol.shuffle();
		} else {
			ret = sol.reset();
		}

		output += "[";
		for (int i = 0; i < ret.size(); ++i) {
			output += to_string(ret[i]);
			if (i < ret.size() - 1) {
				output += ",";
			}
		}
		output += "],";
	}
	ofs << output;
	
	return 0;	
}
