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
    elif a=='COM':
        mensaje='Puerto COM: '
        return mensaje

def mensajesEsperados(a):
    if a=="sincronizadorUno":
        mensaje=('$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr')
        return mensaje
    elif a=="sincronizadorDos":
        mensaje=b'666','utf-8'
        return mensaje
    elif a=="OK":
        mensaje=('Banco De Pruebas Activado')
        return mensaje
    elif a=="Activado":
        mensaje=print('Banco de Pruebas SMA Activado')
        return mensaje