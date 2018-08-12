class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        a_entity, a_virtual = a.split('+')
        b_entity, b_virtual = b.split('+')
        
        ret_entity = int(a_entity) * int(b_entity) - int(a_virtual[0:-1]) * int(b_virtual[0:-1])
        ret_virtual = int(a_virtual[0:-1]) * int(b_entity) + int(b_virtual[0:-1]) * int(a_entity)
        ret = str(ret_entity) + "+" + str(ret_virtual) + "i"
        return ret
    
