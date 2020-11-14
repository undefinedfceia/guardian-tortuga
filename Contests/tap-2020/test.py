lista = list(map(int, input().split()))
M = lista[0]
N = lista[1]
K = lista[2]
n = list(map(int, input().split()))

E = []

for i in range(K):
    e = list(map(int, input().split()))
    k = e[1]
    e[1] = n[k-1]
    E.append(e)


def primosrepetidos(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
    return(primfac)

#def primos(n):
#    divisors = [ d for d in range(2,n//2+1) if n % d == 0 ]
#    return[ d for d in divisors if \
#             all( d % od != 0 for od in divisors if od != d )]

def primos(numberToFactor, arr=list()):
    i = 2
    maximum = numberToFactor / 2 + 1
    while i < maximum:
        if numberToFactor % i == 0:
            return primos(numberToFactor/i,arr + [int(i)])
        i += 1
    return list(set(arr + [numberToFactor]))


D1 = []
D2 = []
for i in range(K):
    D1.append(primosrepetidos((E[i])[1]))
    D2.append(primos((E[i])[1]))

m = []


for u in range(K):
    for x in range(len(D2[u])):

        if (E[u])[2] == D1[u].count((D2[u])[x]):
            t = 1
            for k in range(u+1,K):
                if ((E[k])[0]==(E[u])[0]) and ((D1[k]).count((D2[u])[x]) != (E[k])[2]):
                    t = 0
        if t == 1:
            m.append(D2[u][x])


m = list(map(int, m))
m.sort()