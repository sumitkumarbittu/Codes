class vehicle :
    def __init__(self, type) :
        self.type = type

class car(vehicle) :
    def __init__(self, type, brand) :
        super().__init__(type)
        self.brand = brand

class bike(vehicle) :
    def __init__(self, type, brand) :
        super().__init__(type)
        self.brand = brand

class brand(car, bike) :
    def __init__(self, type, brand, model) :
        super().__init__(type, brand)
        self.model = model

class model(brand) :
    def __init__(self, type, brand, model, price) :
        super().__init__(type, brand, model)
        self.price = price


mycar = model("car", "Tata", "Nexon", 900000)
print(mycar.type)
print(mycar.brand)
print(mycar.model)
print(mycar.price)

mybike = model("bike", "Honda", "CBR", 150000)
print(mybike.type)
print(mybike.brand)
print(mybike.model)
print(mybike.price)