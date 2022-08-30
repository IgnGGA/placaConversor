import serial,os,datetime,sys#importe de librerias

def conexionPC():
    numeroPuerto=int()
    try:
        numeroPuerto=eval(input)
        print(numeroPuerto,'+',type(numeroPuerto))
    except ValueError:
        print('Error')
