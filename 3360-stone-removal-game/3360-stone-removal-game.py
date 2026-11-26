class Solution:
    def canAliceWin(self, n: int) -> bool:
        num = 10

        if n < 10:
            return False
        
        while n >= num:
            n -= num
            num -= 1
            if n >= num:
                n -= num
                num -= 1
            else:
                return True
        

        return False