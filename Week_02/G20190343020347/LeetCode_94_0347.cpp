/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//����1 �ݹ�

class Solution {
public:
	vector<int> result;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root != nullptr) {
			inorderTraversal(root->left);
			result.push_back(root->val);
			inorderTraversal(root->right);
		}
		return result;
	}
};
//����2 ����ջʵ��
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode *> rootStack;
		vector<int> result;
		TreeNode* cur = root;
		while (cur != nullptr || !rootStack.empty()) {
			while (cur != nullptr) {
				rootStack.push(cur);
				cur = cur->left;
			}
			cur = rootStack.top();
			rootStack.pop();
			result.emplace_back(cur->val);
			cur = cur->right;
		}

		return result;
	}
};

//����3 Ī��˹����
//�ó�һ�����ڵ㣬���������Ϊ��������ý��
//�����������Ϊ�գ���ŵ������������ҽ����
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		TreeNode *cur = root, *tmp;
		while (cur) {
			tmp = cur->left;
			if (tmp == nullptr) {
				result.push_back(cur->val);
				cur = cur->right;
			}
			else {
				while (tmp->right != nullptr && tmp->right != cur) {
					tmp = tmp->right;
				}
				if (tmp->right == nullptr) {
					tmp->right = cur;
					cur = cur->left;
				}
				else {
					result.push_back(cur->val);
					tmp->right = nullptr;
					cur = cur->right;
				}
			}
		}
		return result;
	}
};

//����4 ����ɫ��ǣ���⵽���α�ǵ�Ԫ�أ�ֱ�����

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<pair<int, TreeNode*>> node_stack;
		const int white = 0, green = 1;
		node_stack.push(make_pair(white, root));
		while (!node_stack.empty()) {
			int color = node_stack.top().first;
			TreeNode * tmp = node_stack.top().second;
			node_stack.pop();
			if (tmp == nullptr) {
				continue;
			}
			else {
				if (color == white) {
					node_stack.push(make_pair(white, tmp->right));
					node_stack.push(make_pair(green, tmp));
					node_stack.push(make_pair(white, tmp->left));
				}
				else {
					result.push_back(tmp->val);
				}
			}
		}
		return result;
	}
};