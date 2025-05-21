



















'''

class Solution:
    def prime(self, n : int) -> bool:
        if n<=1 : 
            return False
        if n==2 :
            return True
        if n%2 == 0 :
            return False
        for i in range(3, int(n ** 0.5)+1, 2) : 
            if n%i == 0 :
                return False
        return True


    def setbit(self, n : int) -> int:
        c = 0
        while n>0 : 
            a = n%2
            n = n//2
            if a == 1 :
                c = c+1
        return c


    def countPrimeSetBits(self, left: int, right: int) -> int :
        c=0
        for i in range(left,right+1) : 
            x = self.setbit(i)
            y = self.prime(x)
            if y == True :
                c = c + 1
        return c


sol = Solution()
result = sol.countPrimeSetBits(10, 50)
print(result)


def binary(self, n) -> str : 
    s = ""
    while n>0 :
        a = n%2
        n = n//2
        if a == 1 : 
            s = "1"+s
        else : 
            s = "0"+s

    return s


a = input()
b = binary(int(a[0:4]))
print(b)


'''