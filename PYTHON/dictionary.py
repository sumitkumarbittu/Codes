d = {   1 : 'a', 2 : 'b', 3 : 'c'   }

print(d.get(2))

print(d.get(3,'Not Found!'))

print(d.get(5,'Not Found!'))

print(d.keys())

print(d.values())

print(d.items())

d.update( {2 : 'e' , 4 : 'f' , 5 : 'g'} )

print(d)

d.pop(3)

print(d)

print(d.popitem())

print(d)

dd = d.copy()

print(dd)

print(d.setdefault(8 , 'h'))

print(d.setdefault(2 , 'b'))

ddd = d.fromkeys(d, 'z')

print(ddd)

d.clear()

print(d)

"""
OUT : 


b
c
Not Found!
dict_keys([1, 2, 3])
dict_values(['a', 'b', 'c'])
dict_items([(1, 'a'), (2, 'b'), (3, 'c')])
{1: 'a', 2: 'e', 3: 'c', 4: 'f', 5: 'g'}
{1: 'a', 2: 'e', 4: 'f', 5: 'g'}
(5, 'g')
{1: 'a', 2: 'e', 4: 'f'}
{1: 'a', 2: 'e', 4: 'f'}
h
e
{1: 'z', 2: 'z', 4: 'z', 8: 'z'}
{}

"""