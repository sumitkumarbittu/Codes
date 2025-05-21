class animal : 
    __type = "dog"
    _color = "brown"
    def __init__(self,name,age) :
        self.name = name
        self.age = age

    def bark(self) : 
        print(f"{self.name} is barking.")
    
    def type_ani(self) :
        print(self.__type)


class bird(animal) :
    def __init__(self,name,age) :
        super().__init__(name,age)

    color = animal._color


dog = animal("Rocky",5)
eagle = bird("Shera",2)

dog.type_ani()
print(dog.age)
print(dog.name)
dog.bark()

print(eagle.name)
print(eagle.age)
print(eagle.color)
