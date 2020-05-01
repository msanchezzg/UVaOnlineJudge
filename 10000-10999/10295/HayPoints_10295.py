
dicc = {}


words, jobs = [int(x) for x in input().split()]

for i in range(words):
    w, v = input().split()
    dicc[w] = int(v)

while jobs > 0:
    total = 0

    line = input()
    while line != '.':

        for w in line.split():
            total += dicc.get(w, 0)

        line = input()
    
    if line == '.':
        print(total)
        jobs -= 1
