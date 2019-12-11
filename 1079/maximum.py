vals = [None] * 100_000
vals[0] = 0
vals[1] = 1

max_vals = [None] * 100_000

max_vals[0] = 0
max_vals[1] = 1

curr_max = 0

for i in range (2, 100_000):
    if i % 2 == 0:
        first = int(i / 2)
        vals[i] = vals[first]
    else:
        first = int((i - 1) / 2)
        second = int((i - 1) / 2) + 1
        vals[i] = vals[first] + vals[second]
    
    if curr_max < vals[i]:
        curr_max = vals[i]
    
    max_vals[i] = curr_max

n = int(input())
while(n != 0):
    print(max_vals[n])
    n = int(input())