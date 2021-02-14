# https://www.w3schools.com/python/ref_file_read.asp
f = open("day13.in", "r")
wanted_time = int(f.readline()) # not needed here
buses_str = f.readline().split(',')

remainders = {}
every_working_bus = []

curr_remainder = 0
for b in buses_str:
	if b != 'x':
		every_working_bus.append(b)
		remainders[b] = curr_remainder
	curr_remainder += 1

first_bus = every_working_bus[0]
ans = remainders[first_bus]

while(1):
	temp_works = True
	for bus in every_working_bus:
		if(ans % bus == remainders[bus]):
			temp_works = False
			break
	if(temp_works):
		break
	else:
		ans += first_bus

print(ans)
