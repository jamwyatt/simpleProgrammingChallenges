
import sys


def findPrimePositional(primePos):
    primeCount = 0
    n = 2
    while True:
        isPrime = True
        max = n/2+1
        if (n>2) and (n%2 == 0):
            # Even above two are not primes
            isPrime = False
        elif n%3 == 0:
            isPrime = False
        else:
            x = 3
            while x < max:
                if n % x == 0:
                    isPrime = False
                    break   # Not prime
                x += 1

        if isPrime:
            primeCount += 1
            if primeCount == primePos:
                return n;
        n += 1

if len(sys.argv) != 2:
    print "Missing target positional prime number"
    sys.exit(-1)

positionalPrime = findPrimePositional(int(sys.argv[1]))
print "Positional Prime for ",sys.argv[1], " is ", positionalPrime
