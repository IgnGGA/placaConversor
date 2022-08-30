def DetectandoBancoDePruebas():
    import serial
    import Mensajes as msj
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
        if Lectura()==sincro("sincronizadorUno"):
            conexion(2)
            bancoDePruebas.write(sincro("sincronizadorDos"))
            if Lectura()==sincro("OK"):
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