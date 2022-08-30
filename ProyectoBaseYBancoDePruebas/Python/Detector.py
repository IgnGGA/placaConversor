def DetectandoBancoDePruebas():
    import serial
    import Mensajes as msj
    from Mensajes import mensajesConectando as conexion
    from Mensajes import mensajeErrorConectando as errorConexion
    import Conectando as conect
    try:
        bancoDePruebas=serial.Serial('COM{}'.format(conect.conexionPC()),baudrate=9600,timeout=5)
        def Lectura():
            mensajeBDPSMA=bancoDePruebas.readline()
            mensajeBDPSMA=str(mensajeBDPSMA.decode('utf-8')).strip()
            return mensajeBDPSMA
        if Lectura()==msj.mensajesEsperados("sincronizadorUno"):
            conexion(2)
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