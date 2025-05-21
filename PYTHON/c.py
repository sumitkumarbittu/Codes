
"""
#1b


l = [10,20,30,40,50]

l.append(60)

l.remove(30)

ll = l[1:4]

l.reverse()

print(ll)
print(l)

"""



"""

#2a


def bmi(w,h) : 
    h2 = h**2
    return w/h2

h = float(input("Height : "))
w = int(input("Weight : "))

print(bmi(w,h))

"""


"""

#2bi


def update_grades(student, name, grade) : 
    if name in student : 
        student[name] = grade
    else : 
        print('Not Found!')


#2bii


student_grades = {
    'John' : 85 , 'Jane' : 92 , 'Alice' : 78
}

student_grades['Bob'] = 88

student_grades.pop('Jane' , None)

update_grades(student_grades, 'Bob', 99)

for student,grade in student_grades.items() :
    print(f"Student : {student},    Grade : {grade}")


"""



"""

#3a


def l_input() : 
    l = input().split()
    l = [int(n) for n in l]
    return l

def l_sum(l) :
    s = sum(l)
    a = s/len(l)
    return s,a

def min_max(l) : 
    return min(l), max(l)


l = l_input()
print(l)

print(l_sum(l))

print(min_max(l))

"""




"""


# script.py

# Importing the custom module
import text_utils

# Testing the functions
text = input("Enter a string: ")

# Count vowels
vowel_count = text_utils.count_vowels(text)
print(f"Number of vowels: {vowel_count}")

# Reverse the string
reversed_text = text_utils.reverse_string(text)
print(f"Reversed string: {reversed_text}")

# Check if the string is a palindrome
if text_utils.is_palindrome(text):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

    
"""





def orangecap(d) : 
    i=0
    n = int(input("No of Matches : "))
    for i in range(n) :
        a = {}
        j = 0
        c = input(f"Keys for match {i+1} : ")
        m = int(input(f"No of Players for match {i+1}: "))
        for j in range(m) :
            e = input(f"Key for Player {j+1} : ")
            a[e] = int(input(f"Runs for player {j+1} : "))
        d[c]=a
    print(d)

#main
    

orangecap(d)