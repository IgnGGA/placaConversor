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
    elif a==4:
        mensaje=print('Imposible Comunicar con Banco de Pruebas SMA')

def mensajesConectando(a):
    if a==1:
        mensaje=print('Ingrese numero de puerto COM\ndonde esta conectado el banco de pruebas.\n\n')
        return mensaje
    elif a==2:
        mensaje=print("Iniciando Banco De Pruebas SMA")
        return mensaje

def mensajesEsperados(a):
    if a=="sincronizadorUno":
        mensaje=('$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr')
        return mensaje
    elif a=="sincronizadorDos":
        mensaje=('01000010 01100001 01101110 01100011 01101111 01000100 01100101 01010000 01110010 01110101 01100101 01100010 01100001 01110011 01010011 01001101 01000001')
        return mensaje