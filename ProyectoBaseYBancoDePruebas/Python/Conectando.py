def conexionPC():
    from Mensajes import mensajesConectando as conexion
    from Mensajes import mensajeErrorConectando as errorConexion
    numeroPuerto=int()
    try:        
        conexion(1)
        numeroPuerto=eval(input('Puerto COM: '))
        if type(numeroPuerto)==int:
            return numeroPuerto
        else:
            errorConexion(1)
            errorConexion(3)
    except ValueError:
        errorConexion(1)
        errorConexion(3)
    except NameError:
        errorConexion(2)