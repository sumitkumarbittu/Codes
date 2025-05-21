class Solution:
    def myPow(self, x: float, n: int) -> float:
        m=0
        if n==0:
            return 1
        elif n<0:
            m=1
            n*=-1
        y=1
        while n>0:
            if n%2==0:
                x*=x
                n=n//2
            else:
                y*=x
                n-=1
            print(str(x)+"  "+str(y))
        if m==0:
            return y
        else:
            return 1/y
        
a = Solution()
print(a.myPow(2,10))