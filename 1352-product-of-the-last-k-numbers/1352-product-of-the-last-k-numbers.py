class ProductOfNumbers:

    def __init__(self):
        self.prod = []

    def add(self, num: int) -> None:
        if num == 0:
            return self.prod.clear()
        elif not self.prod:
            self.prod.append(num)
        else:
            self.prod.append(num * self.prod[-1])

    def getProduct(self, k: int) -> int:
        n = len(self.prod)

        if k > n :
            return 0
        if k == n :
            return self.prod[n-1]
        
        val = self. prod[n-1-k]
        return self.prod[n-1] // val

# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)