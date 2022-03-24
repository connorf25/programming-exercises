print("Enter/Paste your content. Ctrl-D or Ctrl-Z ( windows ) to save it.")
contents = []
while True:
		try:
				line = list(map(lambda x: int(x), input().split()))
		except EOFError:
				break
		contents.append(line)

height_map = []
for building in contents:
	while building[2] > len(height_map):
		height_map.append(0)
	for i in range(building[0], building[2]):
		if height_map[i] < building[1]:
			height_map[i] = building[1]
height_map.append(0)

for i in range(1, len(height_map)):
	if height_map[i-1] != height_map[i]:
		print(i, height_map[i], end=" ")