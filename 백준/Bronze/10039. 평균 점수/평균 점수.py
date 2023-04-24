tmp = []
for i in range(5):
    a = int(input(""))
    if a < 40:
        a = 40

    tmp.append(a)

avg = sum(tmp) // 5

print(avg)
