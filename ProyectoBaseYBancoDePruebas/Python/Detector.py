def DetectandoBancoDePruebas():
    import serial
    import Mensajes as msj
    import Conectando as conect
    try:
        bancoDePruebas=serial.Serial('COM{}'.format(conect.conexionPC()),baudrate=9600,timeout=5)
        def Lectura():
            mensajeBDPSMA=bancoDePruebas.readline()
            mensajeBDPSMA=str(mensajeBDPSMA.decode('utf-8')).strip()
            return mensajeBDPSMA
        if Lectura()==msj.mensajesEsperados("sincronizadorUno"):
            msj.mensajesConectando(2)
        else:
            msj.mensajeErrorConectando(4)
        bancoDePruebas.close()
    except serial.serialutil.SerialException:
        msj.mensajeErrorConectando(4)
        msj.mensajeErrorConectando(3)
    except FileNotFoundError:
        msj.mensajeErrorConectando(4)
        msj.mensajeErrorConectando(3)

DetectandoBancoDePruebas()  