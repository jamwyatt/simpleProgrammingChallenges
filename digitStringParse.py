import os, sys

completed = []


def digitMatch(dynamic, prefix, index, digits):
    global array
    # print "Prefix:", prefix, "    digits:", digits

    if len(digits) == 0:
        # print prefix
        return 1

    if dynamic and completed[index] != -1:
        return completed[index]

    count=0
    check = digits[0]
    if check != '0':
        # print "Check1", check
        characters = chr(int(check) + ord('a')-1)
        count += digitMatch(dynamic, prefix + characters, index+1, digits[1:])

        if len(digits) > 1:
            check += digits[1]
            # print "Check2", check
            if int(check) < 27:
                characters = chr(int(check) + ord('a'))
                count += digitMatch(dynamic, prefix + characters, index+2, digits[2:])

    # print "Returning count:", count
    completed[index] = count
    return count


if len(sys.argv) != 3:
    print "Missing args    dynamic(true/false) parseString"
    sys.exit(-1)

for a in range(0,len(sys.argv[2])+1):
    completed.append(-1)

try:
    if sys.argv[1].lower() == "true": 
        total = digitMatch(True, "",0, sys.argv[2])
    else:
        total = digitMatch(False, "",0, sys.argv[2])
    print "Total:",total
except KeyboardInterrupt as e:
    print "Interrupted ...."

# for a in range(0,len(sys.argv[1])+1):
#     sys.stdout.write(str(completed[a]) + ' ')
# print
