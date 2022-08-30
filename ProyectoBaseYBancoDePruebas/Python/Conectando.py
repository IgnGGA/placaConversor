from tokenize import Name
import os,datetime,sys#importe de librerias
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

def DetectandoBancoDePruebas():
    import serial
    try:
        bancoDePruebas=serial.Serial('COM{}'.format(conexionPC()),baudrate=9600,timeout=5)
        def Lectura():
            mensajeBDPSMA=bancoDePruebas.readline()
            mensajeBDPSMA=str(mensajeBDPSMA.decode('utf-8')).strip()
            return mensajeBDPSMA
        if Lectura()==msj.mensajesEsperados("sincronizadorUno"):
            msj.mensajesConectando(2)
            bancoDePruebas.write(msj.mensajesEsperados("sincronizadorDos"))
            print (Lectura())
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