//����1������
//ʱ�临�Ӷ�O(N^2)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for (int i = 0; i<nums.size() - 1; ++i) {
			for (int j = i + 1; j<nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					result = { i,j };
					i = nums.size();
					break;
				}
			}
		}
		return result;
	}
};

//����2������hash

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, vector<int>> hash_map;
		for (int i = 0; i<nums.size(); ++i) {
			hash_map[nums[i]].push_back(i);
		}
		for (auto i : nums) {
			if (hash_map.find(target - i) != hash_map.end()) {
				if (i != target - i) {
					result.push_back(hash_map[i][0]);
					result.push_back(hash_map[target - i][0]);
					break;
				}
				else if (hash_map[i].size() >= 2) {
					result.push_back(hash_map[i][0]);
					result.push_back(hash_map[i][1]);
					break;
				}
			}
		}
		return result;
	}
};

//����3�� һ��hash
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, vector<int>> hash_map;
		for (int i = 0; i<nums.size(); ++i) {
			if (hash_map.find(target - nums[i]) != hash_map.end()) {
				result = { hash_map[target - nums[i]][0],i };
				break;
			}
			hash_map[nums[i]].push_back(i);
		}
		return result;
	}
};