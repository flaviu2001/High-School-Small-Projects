print("Using backtracking we will generate all combinations of n choose k.")
n = int(input("n: "))
k = int(input("k: "))
v = [0]

def bkt(t):
    if t == k+1:
        print(v[1:])
        return
    for i in range(v[t-1]+1, n-(k-t)+1):
        v.append(i)
        bkt(t+1)
        v.pop()

bkt(1)
