def DetectandoBancoDePruebas():
    import serial
    from pruebaLogica import pruebaLogica as PL
    from Mensajes import mensajesConectando as conexion
    from Mensajes import mensajeErrorConectando as errorConexion
    from Mensajes import mensajesEsperados as sincro
    import Conectando as conect
    try:
        bancoDePruebas=serial.Serial('COM{}'.format(conect.conexionPC()),baudrate=9600,timeout=5)
        def Lectura():
            mensajeBDPSMA=bancoDePruebas.readline()
            mensajeBDPSMA=str(mensajeBDPSMA.decode('utf-8')).strip()
            return mensajeBDPSMA
        if PL(Lectura(),sincro("sincronizadorUno"))==True:
            conexion(2)
            bancoDePruebas.write(sincro("sincronizadorDos"))
            if PL(Lectura(),sincro("OK"))==True:
                sincro("Activado")
        else:
            errorConexion(4)
        bancoDePruebas.close()
    except serial.serialutil.SerialException:
        errorConexion(4)
        errorConexion(3)
    except FileNotFoundError:
        errorConexion(4)
        errorConexion(3)

DetectandoBancoDePruebas()