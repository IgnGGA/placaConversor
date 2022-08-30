from tokenize import Name
import Mensajes as msj

def conexionPC():
    numeroPuerto=int()
    try:
        msj.mensajesConectando(1)
        numeroPuerto=eval(input('Puerto COM: '))
        if type(numeroPuerto)==int:
            return numeroPuerto
        else:
            msj.mensajeErrorConectando(1)
            msj.mensajeErrorConectando(3)
    except ValueError:
        msj.mensajeErrorConectando(1)
        msj.mensajeErrorConectando(3)
    except NameError:
        msj.mensajeErrorConectando(2)