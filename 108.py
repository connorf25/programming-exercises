import numpy as np

contents = []
while True:
	try:
			line = list(map(lambda x: int(x), input().split()))
	except EOFError:
			break
	contents.append(line)

# Load file
arrays = []
while(len(contents) > 1):
	size = contents.pop(0)[0]
	finalArray = []
	while len(finalArray) < size ** 2:
		finalArray = finalArray + contents.pop(0)
	finalArray = np.array(finalArray).reshape(size, size)
	arrays.append(finalArray)

def kadane(array):
	size = len(array)
	max_so_far = -9999999
	max_ending_here = 0

	for i in range(size):
		max_ending_here = max_ending_here + array[i]
		max_so_far = max(max_ending_here, max_so_far)
		if max_ending_here < 0:
			max_ending_here = 0
	return max_so_far

def max_sum(array, size):
	maximum = -9999999
	for l in range(size):
		for r in range(l, size):
			temp = array[l:r+1]
			temp = np.sum(temp, axis=0)
			maximum = max(maximum, kadane(temp))
	return maximum

for array in arrays:
	print(max_sum(array, len(array)))