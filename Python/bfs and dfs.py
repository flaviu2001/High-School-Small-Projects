fin = open("dfs.in", "r")
fout = open("dfs.out", "w")
v = []
ok = []
st = ''

def dfs(x):
    global ok
    global st
    global v
    ok[x] = 1
    fout.write(str(x) + " ")
    for i in v[x]:
        if ok[i] == 0:
            dfs(i)

def bfs(home):
    global ok
    global st
    global v
    queue = []
    queue.append(home)
    ok[home] = 1
    p = -1
    f = 0
    while p < f:
        p += 1
        fout.write(str(queue[p]) + " ")
        for i in v[queue[p]]:
            if ok[i] == 0:
                ok[i] = 1
                queue.append(i)
                f += 1

x = fin.readline().split(" ")
n = int(x[0])
m = int(x[1])
home = int(x[2])
for i in range(0, n + 2):
    v.append([])
while m > 0:
    m -= 1
    st = fin.readline().split(" ")
    x = int(st[0])
    y = int(st[1])
    v[x].append(y)
    v[y].append(x)
for i in range(0, n + 2):
    ok.append(0)
    v[i].sort()

dfs(home)
fin.close()
fout.close()

