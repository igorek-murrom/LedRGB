import serial
import tkinter as tk
from tkinter import ttk
import serial.tools.list_ports


BOUND = 9600
list_port = list(serial.tools.list_ports.comports())


def portSrl():
    P = combobox.get()
    PORT = ""
    for i in P:
        if i == " ": break
        PORT += i
    return PORT
def fix(R):
    if int(R) < 10: R = '0' + R
    if int(R) < 100: R = '0' + R
    return R


def update(event):
    list_port = list(serial.tools.list_ports.comports())
    if (len(list_port) >= 1 and combobox.get() == '') or len(list_port) == 1:combobox.set(list_port[0])
    elif len(list_port) == 0:combobox.set('')
    combobox['values'] = list_port
    label.config(text="")


def send(event):
    update(1)
    try:
        PORT = portSrl()
        label.config(text="")
        srl = serial.Serial(PORT, BOUND)
        R = 255 - Rv.get()
        G = 255 - Gv.get()
        B = 255 - Bv.get()
        R = fix(str(R))
        G = fix(str(G))
        B = fix(str(B))


        srl.write(R.encode())
        srl.write(G.encode())
        srl.write(B.encode())
    except Exception as e:
        print(e)
        combobox.set('')
        label.config(text="нет COM-порта")


root = tk.Tk()
root.title("LedRGB")
root.geometry("400x240")
root.resizable(False, False)


Rv = tk.IntVar()
Gv = tk.IntVar()
Bv = tk.IntVar()

combobox = ttk.Combobox(root, values=list_port, textvariable=list_port, state="readonly")
scaleR = tk.Scale(root, from_=0, to=255, orient=tk.HORIZONTAL, length=350, variable=Rv)
scaleG = tk.Scale(root, from_=0, to=255, orient=tk.HORIZONTAL, length=350, variable=Gv)
scaleB = tk.Scale(root, from_=0, to=255, orient=tk.HORIZONTAL, length=350, variable=Bv)

button = tk.Button(root, text='Применить')
button.bind('<Button-1>', send)
buttonUpdate = tk.Button(root, text='Обновить список')
buttonUpdate.bind('<Button-1>', update)

label = tk.Label(text="", font="Arial 8")
labelR = tk.Label(text="  R  ", font="Arial 8")
labelG = tk.Label(text="  G  ", font="Arial 8")
labelB = tk.Label(text="  B  ", font="Arial 8")
empty = tk.Label(text=" ")


scaleR.grid(row=0, column=1, columnspan=2)
scaleG.grid(row=1, column=1, columnspan=2)
scaleB.grid(row=2, column=1, columnspan=2)
labelR.grid(row=0, column=0)
labelG.grid(row=1, column=0)
labelB.grid(row=2, column=0)
button.grid(row=3, column=0, columnspan=3)
label.grid(row=4, column=0, columnspan=3)
combobox.grid(row=5, column=2, columnspan=1)
buttonUpdate.grid(row=5, column=1, columnspan=1)
empty.grid(row=5, column=3)


update(1)
root.mainloop()
