/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//����1 dfs
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		dfs(root, res);
		return res;
	}
	void dfs(TreeNode* root, vector<int> &res) {
		if (root == nullptr)
			return;
		res.push_back(root->val);
		dfs(root->left, res);
		dfs(root->right, res);
		return;
	}
};

//����2 ��ջģ��
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *> node_stack;
		TreeNode * cur = root;
		while (cur != nullptr || !node_stack.empty()) {
			while (cur != nullptr) {
				res.push_back(cur->val);
				node_stack.push(cur);
				cur = cur->left;
			}
			cur = node_stack.top();
			node_stack.pop();
			cur = cur->right;
		}
		return res;
	}
};

//����3 Ī��˹����
//�ó�һ�����ڵ㣬���������Ϊ��������ý��
//�����������Ϊ�գ���ŵ������������ҽ����

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *> node_stack;
		TreeNode *cur = root;
		while (cur != nullptr) {
			if (cur->left == nullptr) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {
				TreeNode *tmp = cur->left;
				while (tmp->right != nullptr && tmp->right != cur) {
					tmp = tmp->right;
				}
				if (tmp->right == nullptr) {
					res.push_back(cur->val);
					tmp->right = cur;
					cur = cur->left;
				}
				else {
					tmp->right = nullptr;
					cur = cur->right;
				}
			}
		}
		return res;
	}
};

//����4 ��ɫģ��

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<pair<int, TreeNode *>> node_stack;
		const int white = 0, green = 1;
		node_stack.push(make_pair(white, root));
		while (!node_stack.empty()) {
			int color = node_stack.top().first;
			TreeNode* cur = node_stack.top().second;
			node_stack.pop();
			if (cur == nullptr) {
				continue;
			}
			else {
				if (color == white) {
					node_stack.push(make_pair(white, cur->right));
					node_stack.push(make_pair(white, cur->left));
					node_stack.push(make_pair(green, cur));
				}
				else {
					res.push_back(cur->val);
				}
			}

		}
		return res;
	}
};