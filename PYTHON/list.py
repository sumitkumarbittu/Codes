l = [1,2,3]

print(l)

l.append(4)

print(l)

l.extend([5,6])

print(l)

l.insert(2,10)

print(l)

l.remove(5)

print(l)

l.pop(3)

print(l)

print(l.index(10))

print(l.count(10))

l.sort()

print(l)

ll = l.copy()

print(ll)

l.reverse()

print(l)

l.clear()

print(l)



squares = [x**2 for x in range(5)]

print(squares)

even = [x for x in range(10) if x%2==0]

print(even)





"""
OUT : 


[1, 2, 3]
[1, 2, 3, 4]
[1, 2, 3, 4, 5, 6]
[1, 2, 10, 3, 4, 5, 6]
[1, 2, 10, 3, 4, 6]
[1, 2, 10, 4, 6]
2
1
[1, 2, 4, 6, 10]
[1, 2, 4, 6, 10]
[10, 6, 4, 2, 1]
[]

"""