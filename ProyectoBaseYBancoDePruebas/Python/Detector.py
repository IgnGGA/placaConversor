def DetectandoBancoDePruebas():
    import serial
    from pruebaLogica import pruebaLogica as PL
    from Mensajes import mensajesConectando as conexion
    from Mensajes import mensajeErrorConectando as errorConexion
    from Mensajes import mensajesEsperados as sincro
    from Mensajes import cierresDePrograma as cierre
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
                cierre(3)
                bancoDePruebas.close()
        else:
            errorConexion(4)
            cierre(2)
            bancoDePruebas.close()
        bancoDePruebas.close()
    except serial.serialutil.SerialException:
        errorConexion(4)
        errorConexion(3)
    except FileNotFoundError:
        errorConexion(4)
        errorConexion(3)

DetectandoBancoDePruebas()