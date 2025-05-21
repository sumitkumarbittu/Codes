class animals : 
    def sound(self) :
        return "Animal makes a sound"
    
class dog(animals) : 
    def sound(self) :
        return "Dog barks"
    
class german(dog) :
    def sound(self) :
        return "German Shepherd barks"
    
def sounds(ani) : 
    print(ani.sound())

a = animals()
b = dog()
c = german()

sounds(a)
sounds(b)
sounds(c)