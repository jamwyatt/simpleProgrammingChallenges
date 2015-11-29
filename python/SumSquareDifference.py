
import sys


def sumOfSquares(number):
    sum = 0
    for x in range(number):
        sum += pow(x+1,2)
    return sum


def squareOfSum(number):
    sum = 0
    for x in range(number):
        sum += x+1
    return pow(sum,2)



if len(sys.argv) != 2:
    print "Missing target max number"
    sys.exit(-1)

squares = sumOfSquares(int(sys.argv[1]))
print "Sum of Squares: ", squares

summedSquares = squareOfSum(int(sys.argv[1]))
print "Square of Sum: ", summedSquares

print "Difference: ", summedSquares - squares
