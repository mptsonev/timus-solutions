guests = int(input())
count = 2 + guests

for i in range(0,guests):
	guest = input()
	if "+one" in guest:
		count += 1

if count == 13:
	count += 1

print(count * 100)
