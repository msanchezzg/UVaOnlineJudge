while True:
    s = input()
    if s == 'DONE':
        break
    
    s = [c.upper() for c in s if c.isalpha()]
    s2 = s[::-1]

    if s == s2:
        print('You won\'t be eaten!')
    else:
        print('Uh oh..')
