import os, sys, math


def isTriple(a,b,c, target):
    aSquared = a ** 2
    bSquared = b ** 2
    cSquared = c ** 2

    if (aSquared + bSquared == cSquared) and (a+b+c == target):
        return True
    return False


target = 1000
midPoint = target/2
print "Midpoint:", midPoint

for n in range(2, midPoint):
    for m in range(n+1, int(math.sqrt((target-(n**2))))):
            a = (m**2) - (n**2)
            b = 2*m*n
            c = (m**2) + (n**2)
            print "Testing:",m,n, a,b,c
            if(isTriple(a,b,c,target)):
                print "a,b,c:", a,b,c, a*b*c
                sys.exit(0)

print "Failure"
