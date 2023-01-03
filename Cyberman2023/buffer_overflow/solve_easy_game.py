from pwn import *

p = process("./easy_game")

# p.interactive()
# sh.send(b"Hello"

for _ in range(5):
    print(p.recv().decode("utf-8"))
    p.sendline("Hello\x00")

print(p.recv().decode("utf-8"))

p.sendline(b'CYBER\x00\x00\x00')
print(p.recv().decode("utf-8"))


p.sendline(b'\x00\x00\x00\x00\x00')
print(p.recv().decode("utf-8"))




# for i in range(7):
#     p.sendline(b'\x29\x29\x29\x29\x29')
#     print(p.recv().decode("utf-8"))

# for _ in range(7):
#     p.sendline(b'\x29\x29\x29\x29\x29')
#     print(p.recv().decode("utf-8"))


# p.sendline(b')))))')
# print(p.recv().decode("utf-8"))

# p.sendline(b'\x29\x29\x29\x29\x29')
# print(p.recv().decode("utf-8"))


# p.sendline(b'\x43\x59\x42\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline(b'\x00\x00\x00\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline(b'CYBER')
# print(p.recv().decode("utf-8"))
# p.sendline('\x00\x00\x00\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline('\x00\x00\x00\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline(b'\0\0\0\0\0')
# print(p.recv().decode("utf-8"))


# p.sendline('\x00\x00\x00\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline('\x00\x00\x00\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline('\x00\x00\x00\x00\x00')
# print(p.recv().decode("utf-8"))

# p.sendline(b'\0\0\0\0\0')
# print(p.recv().decode("utf-8"))
# # p.sendline(b'00000')
# print(p.recv().decode("utf-8"))
# p.sendline(b'00000')
# print(p.recv().decode("utf-8"))


# for _ in range(5):
#     data = p.readuntil('\n')
#     p.sendline('Hello')

# out = sh.

# print(out)