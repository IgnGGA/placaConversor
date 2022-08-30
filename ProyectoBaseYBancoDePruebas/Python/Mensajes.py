def mensajeErrorConectando(a):
    if a==1:
        mensaje=print('Error de Puerto.')
        return mensaje
    elif a==2:
        mensaje=print('Debe ingresar un numero,\nreintente.')
        return mensaje
    elif a==3:
        mensaje=print('Puerto Invalido.')
        return mensaje

def mensajesConectando(a):
    if a==1:
        mensaje=print('Ingrese numero de puerto COM\ndonde esta conectado el banco de pruebas.\n\n')
        return mensaje 