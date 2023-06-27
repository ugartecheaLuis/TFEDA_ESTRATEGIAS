def cambio(cantidad, denominaciones):
    resultado = []
    while cantidad > 0:
        if cantidad >= denominaciones[0]:
            num = cantidad // denominaciones[0] 
            cantidad = cantidad - (num * denominaciones[0])
            resultado.append([denominaciones[0], num])
        denominaciones = denominaciones[1:]
        print (denominaciones)
    return resultado

print (cambio(4893, [500, 200, 100, 50, 20, 5, 1]))