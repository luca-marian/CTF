from subprocess import Popen, PIPE, STDOUT
# import interact
import struct


# p = Popen(["./game","temp"],shell=True ,stdout=PIPE,stdin=PIPE) 
p = Popen(["./game","temp"], stdin=PIPE, stdout=PIPE, stderr=STDOUT)  

# p = interact.Process()

p.stdin.write(b'Hello')
list_of_strings = [x.decode('utf-8').rstrip('\n') for x in iter(p.stdout.readlines())]
print(list_of_strings)

p.stdin.write(b'Paula')
p.stdin.write(b'Hello')
p.stdin.write(b'Hello')
p.stdin.write(b'Hello')
p.stdin.write(b'CYBER')


# out = p.stdout.readline()
# print(out)
# for line in iter(out,''):
# import io
# for line in io.TextIOWrapper(p.stdout, encoding="utf-8"):
#     print(line)

# p.interactive()
# for i in range(10):
#     response = p.stdout.read()
#     print('Response', i)
#     print(response)