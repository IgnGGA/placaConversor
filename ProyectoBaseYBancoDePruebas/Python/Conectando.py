def conexionPC():
    from tokenize import Name
    from turtle import delay#importe de librerias
    import Mensajes as msj
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