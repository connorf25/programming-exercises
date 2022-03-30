import numpy as np

contents = []
while True:
	try:
			line = list(map(lambda x: int(x), input().split()))
	except EOFError:
			break
	contents.append(line)

print(contents)
size = contents.pop(0)[0]
finalArray = []
while len(finalArray) < size ** 2:
	finalArray = finalArray + contents.pop(0)
finalArray = np.array(finalArray).reshape(size, size)
print(finalArray)