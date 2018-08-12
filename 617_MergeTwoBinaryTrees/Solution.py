# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        
        return self.mergeTreesCore(t1, t2)
        
        
    
    def mergeTreesCore(self, t1, t2):
        if t1 == None:
            return t2
        if t2 == None:
            return t1
        
        t1.val += t2.val
        
        t1.left = self.mergeTreesCore(t1.left, t2.left)
        t1.right = self.mergeTreesCore(t1.right, t2.right)
        
        return t1
            
        
        
        
