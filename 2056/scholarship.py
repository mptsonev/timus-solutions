marksCount = int(input())

marksSum = 0
hasSatisfactoryMarks = False
onlyExcellentMarks = True

for i in range(marksCount):
	mark = int(input())
	marksSum += mark
	if mark == 3:
		hasSatisfactoryMarks = True
	if mark != 5:
		onlyExcellentMarks = False

if hasSatisfactoryMarks:
	print("None")
elif onlyExcellentMarks:
	print("Named")
elif marksSum / marksCount >= 4.5:
	print("High")
else:
	print("Common")