def rutas(m,n,memo={}):
    if((m,n) in memo):
        return memo[(m,n)]
    if(m == 1 and n == 1):
        return 1
    if(m == 0 or n == 0):
        return 0
    memo[(m,n)] = rutas(m-1,n,memo) +  rutas(m,n-1,memo)
    return memo[(m,n)]

print(rutas(1,1))
print(rutas(2,3))
print(rutas(3,3))
print(rutas(7,7))
print(rutas(18,18))