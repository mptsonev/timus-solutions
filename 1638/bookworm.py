volume, cover, start, end = [int(x) for x in input().split(' ')]

if start < end:
	print((end - start - 1) * volume + (end - start) * 2 * cover)
elif start > end:
	print ((start - end + 1) * volume + (start - end) * 2 * cover)
else:
	print(0)