import cv2
from tkinter import filedialog, Tk, Button, Label
from tkinter import *
from PIL import Image, ImageTk
import numpy as np

image_display_size = 500, 350


def decrypt():
    # load the image and convert it into a numpy array and display on the GUI.
    load = Image.open("./encrypted_image.png")
    load.thumbnail(image_display_size, Image.ANTIALIAS)
    load = np.asarray(load)
    load = Image.fromarray(np.uint8(load))
    render = ImageTk.PhotoImage(load)
    img = Label(app, image=render)
    img.image = render
    img.place(x=100, y=90)

    # Algorithm to decrypt the data from the image
    img = cv2.imread("./encrypted_image.png")
    data = []
    stop = False
    for index_i, i in enumerate(img):
        i.tolist()
        for index_j, j in enumerate(i):
            if((index_j) % 3 == 2):
                # first pixel
                data.append(bin(j[0])[-1])
                # second pixel
                data.append(bin(j[1])[-1])
                # third pixel
                if(bin(j[2])[-1] == '1'):
                    stop = True
                    break
            else:
                # first pixel
                data.append(bin(j[0])[-1])
                # second pixel
                data.append(bin(j[1])[-1])
                # third pixel
                data.append(bin(j[2])[-1])
        if(stop):
            break

    message = []
    # join all the bits to form letters (ASCII Representation)
    for i in range(int((len(data)+1)/8)):
        message.append(data[i*8:(i*8+8)])
    # join all the letters to form the message.
    message = [chr(int(''.join(i), 2)) for i in message]
    message = ''.join(message)
    message_label = Label(app, text=message, bg='lavender', font=("Times New Roman", 10), wraplength=400)
    message_label.place(x=30, y=400)

# Defined the TKinter object app with background lavender, title Decrypt, and app size 600*600 pixels.
app = Tk()
app.configure(background='lavender')
app.title("Reviva'23 - Stegnography / Decrypt")
app.geometry('600x600')
#button
load = Image.open("./encrypted_image.png")
load.thumbnail(image_display_size, Image.ANTIALIAS)
load = np.asarray(load)
load = Image.fromarray(np.uint8(load))
render = ImageTk.PhotoImage(load)
img = Label(app, image=render)
img.image = render
img.place(x=100, y=90)
#founded the encrypted image
user_name = Label(text = "Found the Latest Encrypted image", bg="lavender", font=("Times New Roman", 20)).place(x = 100,y = 10) 
# Add the button to call the function decrypt.
main_button = Button(app, text="Start Program", bg='white', fg='black', command=decrypt)
main_button.place(x=250, y=300)

# credits

user_name = Label(text = "Reviva'23 - Project", bg="lavender", font=("Times New Roman", 10)).place(x = 400,y = 500) 
user_name = Label(text = "Done-by 2nd year ECE students", bg="lavender", font=("Times New Roman", 10)).place(x = 400,y = 520) 
user_name = Label(text = "Arunapriya AG, Kaniga B", bg="lavender", font=("Times New Roman", 10)).place(x = 400,y = 540) 
app.mainloop()
