import sys
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly_num = [1]
        primes_index = [0] * len(primes)

        for _ in range(1, n):
            val = sys.maxsize
            for i, p in enumerate(primes):
                if val > p*ugly_num[primes_index[i]]:
                    val = p*ugly_num[primes_index[i]]
            ugly_num.append(val)

            for i, p in enumerate(primes):
                if val == p*ugly_num[primes_index[i]]:
                    primes_index[i] += 1
        
        return ugly_num[-1]