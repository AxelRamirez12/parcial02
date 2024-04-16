from tkinter import *

ventana = Tk()
ventana.title("Calculadora")

i = 0

#Entrada
e_texto = Entry(ventana, font= ("Calibri 20"))
e_texto.grid(row = 0, column = 0, columnspan = 4, padx = 5, pady = 5)

#Funciones
def click_boton(valor):
    global i
    e_texto.inser

def borrar():
    e_texto.delete(0, END)
    i = 0

def hacer_operacion():
    ecuacion = e_texto.get()
    resultado = eval(ecuacion)
    e_texto.delete(0, END)
    e_texto.insert(0,resultado)
    i = 0


#Botones
boton1 = Button(ventana, text = "1", width = 5, height = 2, command = lambda: click_boton(1))
boton2 = Button(ventana, text = "2", width = 5, height = 2, command = lambda: click_boton(2))
boton3 = Button(ventana, text = "3", width = 5, height = 2, command = lambda: click_boton(3))
boton4 = Button(ventana, text = "4", width = 5, height = 2, command = lambda: click_boton(4))
boton5 = Button(ventana, text = "5", width = 5, height = 2, command = lambda: click_boton(5))
boton6 = Button(ventana, text = "6", width = 5, height = 2, command = lambda: click_boton(6))
boton7 = Button(ventana, text = "7", width = 5, height = 2, command = lambda: click_boton(7))
boton8 = Button(ventana, text = "8", width = 5, height = 2, command = lambda: click_boton(8))
boton9 = Button(ventana, text = "9", width = 5, height = 2, command = lambda: click_boton(9))
boton0 = Button(ventana, text = "0", width = 13, height = 2, command = lambda: click_boton(0))

boton_borrar = Button(ventana, text = "AC", width = 5, height = 2,command = lambda: borrar())
boton_parentesis1 = Button(ventana, text = "(", width = 5, height = 2,command = lambda: click_boton("("))
boton_parentesis2 = Button(ventana, text = ")", width = 5, height = 2,command = lambda: click_boton(")"))
boton_punto = Button(ventana, text = ".", width = 5, height = 2,command = lambda: click_boton("."))

boton_div = Button(ventana, text = "/", width = 5, height = 2,command = lambda: click_boton("/"))
boton_mult = Button(ventana, text = "x", width = 5, height = 2,command = lambda: click_boton("*"))
boton_sum = Button(ventana, text = "+", width = 5, height = 2,command = lambda: click_boton("+"))
boton_rest = Button(ventana, text = "-", width = 5, height = 2,command = lambda: click_boton("-"))
boton_igual = Button(ventana, text = "=", width = 5, height = 2,command = lambda: hacer_operacion("="))

#Agregar botones en pantalla.
boton_borrar.grid(row = 1, column = 0, padx = 5, pady = 5)
boton_parentesis1.grid(row = 1, column = 1, padx = 5, pady = 5)