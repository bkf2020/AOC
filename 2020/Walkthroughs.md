Walkthroughs for 2020
=====================

Available days:
---------------
- [Day 13](#day-13)

Day 13
------

### Part 1:

You want a bus that leaves at `wanted_time`. For the bus with id `i`, it leaves at multiples of `i`. To find the nearest multiple of `i` to `wanted_time`, you take `ceil(wanted_time / i) * i`.

Here, `ceil` computes the smallest integer greater than or equal `wanted_time / i`, and you need at least `wanted_time / i` multiples of `i` to get `wanted_time`. However, since `wanted_time / i` is not always an integer, you need to take the ceiling.

Now, reading in `wanted_time` is straightforward, but reading in the buses may be more difficult. You can read in the line with the id of the buses, and then use the `split` function to turn it into a list. Then you can go through each bus, and do what we did in the last paragraph, as long as the id isn't an 'x'.

My code:
```py
# https://www.w3schools.com/python/ref_file_read.asp
f = open("day13.in", "r")
wanted_time = int(f.readline())
buses_str = f.readline().split(',')

min_waiting = 2147483647
min_id = 0

for b in buses_str:
	if b != 'x':
		bus_id = int(b)
	closest = bus_id * ((wanted_time + bus_id - 1) // (bus_id))
	# (wanted_time + bus_id - 1) // (bus_id) gives the ceiling
	waiting_time = closest - wanted_time

	if waiting_time < min_waiting:
		min_waiting = waiting_time
		min_id = bus_id
		
print(min_waiting * min_id)
```

### Part 2:

My method is explained [here](https://github.com/mebeim/aoc/blob/master/2020/README.md#part-2-12). This is probably a better explanation than any I can offer. I basically used Chinese Remainder Theorem, as outlined there.

I think an interesting thing I did was using a power function from page 202 of https://cses.fi/book.pdf. This computes a power in `log n` time, and is pretty clever. However, I think the default python power function is fine.

Also to take the inverse of a number `n` modulo `m`, I did `n ^ (m - 2)` as the inverse since `n * n ^ (m - 2)` is congruent to `1` modulo `m` by Fermat's Little Theorem.

**NOTE:** `n` and `m` above are **prime numbers!!** With composite numbers, Euler's Totient function is needed.

However, simple solutions are always great! I think this is a good solution from mebeim (probably should credit him!): https://github.com/mebeim/aoc/blob/master/2020/README.md#part-1-12. Also check out Errichto's code for this problem: https://github.com/Errichto/youtube/blob/master/AOC-2020/13-search/shuttle2.cpp.

Code:
```py
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

```
