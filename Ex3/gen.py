import random
"""
r = random.sample(range(1000), 1000)
# random 1000
file1 = open("random_1000.txt", "w")
file1.write('1000 ')
for i in r:
    s = str(i) + " "
    file1.write(s)
file1.close()

# random 10000
r = random.sample(range(10000), 10000)
file1 = open("random_10000.txt", "w")
file1.write('10000 ')
for i in r:
    s = str(i) + " "
    file1.write(s)
file1.close()
"""
# random 100000
r = random.sample(range(5000), 5000)
file1 = open("random_5000.txt", "w")
file1.write('5000 ')
for i in r:
    s = str(i) + " "
    file1.write(s)
file1.close()

# ascending 1000
file1 = open("ascending_5000.txt", "w")
file1.write('5000 ')
for i in range(5000):
    s = str(i) + " "
    file1.write(s)
file1.close()
"""
# ascending 10000
file1 = open("ascending_10000.txt", "w")
file1.write('10000 ')
for i in range(10000):
    s = str(i) + " "
    file1.write(s)
file1.close()

# ascending 100000
file1 = open("ascending_100000.txt", "w")
file1.write('100000 ')
for i in range(100000):
    s = str(i) + " "
    file1.write(s)
file1.close()

"""
# descending 1000
file1 = open("descending_5000.txt", "w")
file1.write('5000 ')
for i in range(5000):
    s = str(5000 - i) + " "
    file1.write(s)
file1.close()
"""
# descending 10000
file1 = open("descending_10000.txt", "w")
file1.write('10000 ')
for i in range(10000):
    s = str(10000 - i) + " "
    file1.write(s)
file1.close()

# descending 100000
file1 = open("descending_100000.txt", "w")
file1.write('100000 ')
for i in range(100000):
    s = str(100000 - i) + " "
    file1.write(s)
file1.close()

"""