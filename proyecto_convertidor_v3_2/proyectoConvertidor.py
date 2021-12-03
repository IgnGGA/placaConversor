import serial
import os
import datetime
import sys


def proyectoConvertidor():
    pulsos = serial.Serial('COM4', baudrate=9600, timeout=1)
    print("\nFrecuencia = 1Hz por sistema, su moidificacion es directamente en el codigo fuente\n")
    print("\n\t\tSeleccione que señal desea generar:\nSeñal 1:\tPWM1==PMW3!=PWM5\nSeñal 2:\tPWM5==PMW3!=PWM1\nSeñal 3:\tPWM3=Cte y PMW1!=PWM5\nSeñal 4:\tPWM1==PWM3==PWM5\nSeñal 5:\tPWM1==PWM5 y PWM3==Cte")
    def signalsArduino():
        selector = input()
        if (selector == '1'):
            print("\nSeñal 1:\nPWM1 y PWM5 complementarios,\nY PWM3 == PWM1\n")
        elif (selector == '2'):
            print("\nSeñal 2:\nPWM1 y PWM5 complementarios,\nY PWM3 == PWM5\n")
        elif (selector == '3'):
            print("\nSeñal 3:\nPWM1 y PWM5 complementarios,\nY PWM3 == HIGH\n")
        elif (selector == '4'):
            print("\nSeñal 4:\nPWM1==PWM3==PWM5")
        elif (selector == '5'):
            print("\nSeñal 4:\nPWM1==PWM5 y PWM3==Cte")
        elif (selector == '0'):
            Serial.print("\n\t\tStop\n")
        while(True):
            pulsos.write(selector.encode("utf-8"))
            mensajeARD = pulsos.readline()
            converMsj = str(mensajeARD.decode("utf-8"))
            confirmacion = converMsj.strip()
            print("{}".format(confirmacion))
            print("\n\tPara seleccionar otro pulso, reiniciar placa manualmente\ncon boton RESET")
            signalsArduino()
            break
    signalsArduino()
proyectoConvertidor()