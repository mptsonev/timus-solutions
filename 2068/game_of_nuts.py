int(input())
heaps = input()
moves = 0

for heap in heaps.split(' '):
    moves += int(int(heap) / 2)

if moves % 2 != 0:
    print('Daenerys')
else:
    print('Stannis')

