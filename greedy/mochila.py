def mochila_greedy(elementos, capacidad):
    # Calcular la relación valor/peso para cada elemento
    for elemento in elementos:
        elemento['relacion'] = elemento['valor'] / elemento['peso']

    # Ordenar los elementos en orden descendente según la relación valor/peso
    elementos.sort(key=lambda x: x['relacion'], reverse=True)

    capacidad_restante = capacidad
    valor_total = 0

    for elemento in elementos:
        if elemento['peso'] <= capacidad_restante:
            valor_total += elemento['valor']
            capacidad_restante -= elemento['peso']
        else:
            fraccion = capacidad_restante / elemento['peso']
            valor_total += fraccion * elemento['valor']
            capacidad_restante = 0
            break

    return valor_total

