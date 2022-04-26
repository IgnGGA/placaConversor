import serial
import os
import datetime
import sys


def proyectoConvertidor():
    print("Seleccionar puerto de conección de tarjeta para pruebas Arduino")
    while True:
        try:
            numPort=input("Numero de Puerto:\t")
            intNumPort=int(numPort)
            if (intNumPort==int(numPort)):
                pulsos = serial.Serial('COM{}'.format(intNumPort), baudrate=9600, timeout=1)
                print("\nFrecuencia = 1Hz por sistema, su moidificacion es directamente en el codigo fuente de la placa Arduino\n")
                print("\n\t\tSeleccione que señal desea generar:\nSeñal 1:\tPWM1==PMW3!=PWM5\nSeñal 2:\tPWM5==PMW3!=PWM1\nSeñal 3:\tPWM3=Cte y PMW1!=PWM5\nSeñal 4:\tPWM1==PWM3==PWM5\nSeñal 5:\tPWM1==PWM5 y PWM3==Cte")
                def signalsArduino():
                    selector = input("Numero de Señal:\t")
                    listSignals=('0','1','2','3','4','5')
                    if (selector in listSignals and selector == '1'):
                        print("\nSeñal 1:\nPWM1 y PWM5 complementarios,\nY PWM3 == PWM1\n")
                    elif (selector in listSignals and selector == '2'):
                        print("\nSeñal 2:\nPWM1 y PWM5 complementarios,\nY PWM3 == PWM5\n")
                    elif (selector in listSignals and selector == '3'):
                        print("\nSeñal 3:\nPWM1 y PWM5 complementarios,\nY PWM3 == HIGH\n")
                    elif (selector in listSignals and selector == '4'):
                        print("\nSeñal 4:\nPWM1==PWM3==PWM5")
                    elif (selector in listSignals and selector == '5'):
                        print("\nSeñal 4:\nPWM1==PWM5 y PWM3==Cte")
                    elif (selector in listSignals and selector == '0'):
                        print("\n\t\tStop\n")
                    while(True):
                        if (selector in listSignals):
                            pulsos.write(selector.encode("utf-8"))
                            mensajeARD = pulsos.readline()
                            converMsj = str(mensajeARD.decode("utf-8"))
                            confirmacion = converMsj.strip()
                            print("{}".format(confirmacion))
                            print("\n\tPara seleccionar otro pulso, REINICIAR placa manualmente\n\tcon boton RESET\n\n")
                            signalsArduino()
                            break
                        elif (selector not in listSignals):
                            print("Señal seleccionada INVALIDA, favor de seleccionar OTRA señal.\n")
                            signalsArduino()
                            break
                        break
                signalsArduino()
                break
        except ValueError:
            print('Ingrese un puerto valido')

proyectoConvertidor()