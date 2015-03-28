# Hello World program in Python
    
f = open("topsites.txt", 'r')
f1 = open("urls.txt", 'r+')

for line in f:
    f1.write(line)

for l1 in f:
    l2 = f1.readline()
    if l1 != l2:
        print("Error copying")

f.close()
f1.close()
