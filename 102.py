import math

contents = []
while True:
	try:
			line = list(map(lambda x: int(x), input().split()))
	except EOFError:
			break
	contents.append(line)

def calculateSum(bins, binNumber, offset):
	sum = 0
	for x in bins:
		sum += binNumber[x * 3 + offset]
	return sum


def calculateMovements(binOrder, binNumbers):
	sum = 0
	for i, color in enumerate(binOrder):
		# Different bin index, remove whichever one we are looking at
		bins = [0, 1, 2]
		del bins[i]
		if color == 'B':
			sum += calculateSum(bins, binNumbers, 0)
		if color == 'G':
			sum += calculateSum(bins, binNumbers, 1)
		if color == 'C':
			sum += calculateSum(bins, binNumbers, 2)
	return sum

for line in contents:
	colors = ["B", "G", "C"]
	minimumSum = math.inf
	minimumOrder = None
	for color1 in colors:
		for color2 in colors:
			if color1 == color2:
				continue
			for color3 in colors:
				if color3 == color1 or color3 == color2:
					continue
				binOrder = [color1, color2, color3]
				sum = calculateMovements(binOrder, line)
				if sum < minimumSum:
					minimumSum = sum
					minimumOrder = "".join(binOrder)
				if sum == minimumSum:
					newOrder = "".join(binOrder)
					if newOrder < minimumOrder:
						minimumOrder = newOrder
	print(minimumOrder, minimumSum)