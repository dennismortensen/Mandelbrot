# Mandelbrot Fun! - Dennis@VR
# z(n+1) = z(n+1)^2 + c
# OR z = z*z + c

from Tkinter import *
from datetime import datetime

mwidth = 800
mheight = 600

t = Tk()

pic = PhotoImage(width=mwidth,height=mheight)
pic.put('#000000',(mwidth-1,mheight-1)) 

canv = Canvas(t, width=mwidth, height=mheight)
canv.pack()

mtime = datetime.now()

for x in range(0,mwidth):
    real = x / 300.0 - 2.0
    
    for y in range(0,mheight):
        imaginary = y / 300.0 - 1.0

        c = complex(real, imaginary)
        z = 0

        for h in range(0,25):
            z = z*z + c

            if abs(z) > 2:
                pic.put('#%02x%02x%02x' % (h*10, h*5, h*2),(x,y))
                break
            

canv.create_image(0, 0, image=pic, anchor=NW)
print datetime.now() - mtime
t.mainloop()

