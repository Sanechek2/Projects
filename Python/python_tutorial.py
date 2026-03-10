
# ---------- Path and directory ---------
# from pathlib import Path
#
# # Absolute path
# # /usr/local/bin
# # Relative path
#
# path = Path("ecommerce")
# print(path)
# print(path.exists())
#
# pathkee = Path("emails")
# print(path) #mkdir
#
# path = Path()
# for file in path.glob('*.py'):
#     print(file)


# #  ------------ Random numbers ------
# import random
#
# for i in range(10):
#     print(random.randint(33, 69))
#
# members = ['john', 'michael', 'peter']
# leader = random.choice(members)
# print(leader)
#
# class Dice:
#     def roll(self):
#         x = random.randint(1, 6)
#         y = random.randint(1, 6)
#         return x, y
#
#
# dice = Dice()
# print(dice.roll())

# # ------------- Packages -----------
# from ecommerce.shipping import calc_shipping
#
# calc_shipping()



## ------------- Modules -----------
# import module
# from module import kg_to_lbs
# from module import max
#
# numbers = [0, 2, 45, 546, 244, 34 , 643567]
#
# print(max(numbers))
#
# kg_to_lbs(100)
#
# print(module.kg_to_lbs(69))
# print(module.lbs_to_kg(69))




# -------------- Classes -----------
# class Mammal:
#     def walk(self):
#         print("walk")
#
#
# class Dog(Mammal):
#     def bark(self):
#         print("bark")
#
# class Cat(Mammal):
#     def pspsps(self):
#         print("pspsps")
#
# dog1 = Dog()
# dog1.walk()
# dog1.bark()
# cat1 = Cat()
# cat1.walk()
# cat1.pspsps()
#
#
# class Point: #old Pascal names
#     def __init__(self, x, y):
#         self.x = x
#         self.y = y
#
#     def move(self):
#         print("move")
#
#     def draw(self):
#         print("draw")
#
# point1 = Point(10, 39)
# point1.x = 13
# print(point1.x)
#
# class Person:
#     def __init__(self, name):
#         self.name = name
#
#     def talk(self):
#         print("talk", self.name)
#
# john = Person("John")
# john.talk()
#
# bob = Person("Bob")
# bob.talk()
# print(bob.name)



# -------------- Errors ------------
# try:
#     age = int(input())
#     print(age)
# except ValueError:
#     print("Please enter an integer")


# -------------- emoji --------------
# message = input(">")
# words = message.split(" ")
#
# def emofu_converter (message):
#     emoji = {
#         ":)": "😄",
#         ":(": "😖"
#     }
#     output = ""
#     words = message.split()
#     for word in words:
#         output += emoji.get(word, word) + " "
#     return output
#
# print(emofu_converter(message))

#--------------- Matrix ------------
# matrix = [
#     [1, 2, 3],
#     [4, 5, 6],
#     [7, 8, 9]
# ]
#
# for row in matrix:
#     print(*row)
#