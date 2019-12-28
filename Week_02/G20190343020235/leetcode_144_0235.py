# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def preorder(root):
            if not root:
                return
            res.append(root.val)
            preorder(root.left)
            
            preorder(root.right)
        preorder(root)
        return res