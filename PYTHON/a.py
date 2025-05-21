"""




with open('example.txt', 'r') as file:
	contents = file.read()

print(contents)




f = open("a.txt","w")
f.write("Testing to Write using Python.\n")
f.write("Again Check!")
f.close()
g = open("a.txt","r")
a = g.read()
g.close()
print(a)



"""


"""
#good in goods 

goods = [10,80,60,45,90]
for good in goods:
	print(good)




for i in range(5):
	print(i*10)




a = list(range(100))
print(a)

b = list((10,20,30,40))
print(b)



n=int(input("Enter iteration : "))
for i in range(n):
	for j in range(i+1):
		print("*",end=' ')
	print(' ')




n=int(input("Enter iteration : "))
for i in range(n):
	for j in range(i+1):
		print("*",end=' ')





a = int(input("Enter a no. "))

if a>0:
	print("Number is positive")
elif a==0:
	print("Number is zero")
else:
	print("Number is negative")




a = (input("Enter a char. "))

if len(a)!=1:
	print("!!!!!!!!!Please enter only 1 char.!!!!!!!!!")
	exit()

if a=='A' or a=='E' or a=='I' or a=='O' or a=='U' or a=='a' or a=='e' or a=='i' or a=='o' or a=='u':
	print("Character is Vowel")
elif  (a>='A' and a<='Z') or (a>='a' and a<='z'):
	print("Character is Consonant")




a= input("Enter a String to Reverse : ")

print("Reversed String is :"+a[::-1])



import math

a = int(input("Enter Coefficient of x^2 : "))

b = int(input("Enter Coefficient of x : "))

c = int(input("Enter Constant : "))

d = math.sqrt((b*b)-4*a*c)

x = (-b+d)/(2*a)

y = (-b-d)/(2*a)

print(x,y)







def fact(n):
	if n==1 or n==0:
		return 1
	else:
		return n*fact(n-1)

i=0
n=5
a=0
while n>0:
	a += fact(i)
	i+=1
	n-=1

print(a)




a = -1

n = int(input())

c=0
for i in range(n):
	b = 1/(i+1)
	if i%2==0:
		b*=a
	c+=b

print(c)





import array as arr

a = input("Enter Elements of array : ")

b = list(map(int,a.split()))

c = arr.array('i',b)

l = len(c)

t=c[0];
for i in range(l):
	if c[i]>t:
		t=c[i]

print(t)




s=0
p=5
q=15
for i in range(p,q,1):
	if i%2==0:
		s=s+i
print(s)




x=0
y=1
k=0

n=int(input())

for i in range(n):
	for j in range(x+y):
		print('*',end='')
		k=k+1
	print('\n')
	x=y
	y=k
	k=0

"""

