from subprocess import Popen, PIPE, STDOUT

# p = Popen(["./game","temp"], shell=True)  
p = Popen(["./game","temp"], stdin=PIPE, stdout=PIPE, stderr=STDOUT, encoding='UTF8')  

for i in range(10):
    response = p.stdout.read()
    print('Response', i)
    print(response)