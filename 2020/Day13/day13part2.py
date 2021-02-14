import math

# https://www.w3schools.com/python/ref_file_read.asp
f = open("day13.in", "r")
wanted_time = int(f.readline()) # not needed here
buses_str = f.readline().split(',')

remainders = {}
every_working_bus = []

curr_remainder = 0
for b in buses_str:
	if b != 'x':
		every_working_bus.append(int(b))
		remainders[int(b)] = (int(b) - curr_remainder) % int(b)
	curr_remainder += 1

first_bus = every_working_bus[0]

# from https://cses.fi/book.pdf page 202
def power(x, n, m):
	if(n == 0):
		return 1 % m
	u = power(x, math.floor(n/2), m)
	u = (u * u) % m
	if(n % 2 == 1):
		u = (u * x) % m
	return u
"""
we solve x == a (mod m1) and x == b (mod m2) using Chinese Remainder Theorem
all buses are prime numbers (HOPEFULLY!) so we can use Fermat's Little
theroem to find the remainder!

this needs a good explanation probably!
"""

m1 = every_working_bus[0]
m2 = every_working_bus[1]
a = remainders[m1]
b = remainders[m2]

x = (b - a) % m2
x *= power(m1, m2 - 2, m2)
x *= m1
x += a

m1 = m1 * m2
a = x % m1

for i in range(2, len(every_working_bus)):
	m2 = every_working_bus[i]
	b = remainders[m2]
	x = (b - a) % m2
	x *= power(m1, m2 - 2, m2)
	x *= m1
	x += a

	m1 = m1 * m2
	a = x % m1

print(a)
