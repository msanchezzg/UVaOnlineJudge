from collections import Counter

keys = {}
keys['A'] = keys['B'] = keys['C'] = '2'
keys['D'] = keys['E'] = keys['F'] = '3'
keys['G'] = keys['H'] = keys['I'] = '4'
keys['J'] = keys['K'] = keys['L'] = '5'
keys['M'] = keys['N'] = keys['O'] = '6'
keys['P'] = keys['R'] = keys['S'] = '7'
keys['T'] = keys['U'] = keys['V'] = '8'
keys['W'] = keys['X'] = keys['Y'] = '9'

cases = int(input())

for i in range(cases):
    #print(i)
    a = input()
    list = []
    lines = int(input())
    for j in range(lines):
        l = input()
        #print(l)
        phone = ''
        for char in l:
            if char in keys:
                phone += keys[char]

            elif char.isdigit():
                phone += char

        phone = phone[:3] + '-' + phone[3:]
        list.append(phone)
        #print(phone)
        #print('----------------')

    counter = Counter(list).items()
    counter = [x for x in counter if x[1] > 1]

    if len(counter) == 0:
        print('No duplicates.')
    else:
        counter = sorted(counter, key=lambda x: (x[0]))
        for phone in counter:
            print(phone[0] + ' ' + str(phone[1]))

    if i != cases-1:
        print()
