# https://w3schools.com/python/ref_file_read.asp
f = open("day13.in", "r")
wanted_time = int(f.readline())
buses_str = f.readline().split(',')

min_waiting = 2147483647
min_id = 0

for b in buses_str:
  if b != x:
    bus_id = int(b)
    closest = bus_id * ((wanted_time + bus_id - 1) // (bus_id))
    # (wanted_time + bus_id - 1) // (bus_id) gives the ceiling
    waiting_time = closest - wanted_time
    
    if waiting_time < min_waiting
      min_waiting = waiting_time
      min_id = bus_id

print(min_waiting * min_id)
