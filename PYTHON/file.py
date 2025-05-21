with open('info.txt', 'w') as file : 
    file.write('This is a test file.')

with open('info.txt', 'r') as file :
    a = file.read()
    print(a)

with open('info.txt', 'a') as file :
    file.write('This is again a test file.')

with open('info.txt', 'r') as file :
    a = file.read()
    print(a)

with open('plot.png', 'rb') as file : 
    a = file.read()
    print(a[:10])

with open('plot2.png', 'wb') as file :
    file.write(a)