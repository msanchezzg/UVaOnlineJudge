
lista = []

while True:
    n = input()
    if n != '':
        n = int(n)
        lista.append(n)
    if n == 0:
        break

print(sum(lista))