# EGL

An interface between rendering APIs such as OpenCL, OpenGL, OpenGL ES or OpenVG (referred to collectively as client APIs) and one or more underlying platforms (typically window systems such as X11). 

*EGL provides mechanisms for creating rendering surfaces onto which client APIs* can draw, creating graphics contexts for client APIs, and synchronizing drawing by client APIs as well as platform rendering APIs. EGL does not explicitly support remote or indirect rendering, unlike the similar GLX API.

Specification referred  
https://registry.khronos.org/EGL/specs/eglspec.1.5.pdf


#  General Q&A
## 1. What is display, sufrase, context

It depends on the system these are general terms and are often interchanged. But in general

A DisplaySurface is a surface you'd perform operations on i.e. draw a line, circle etc on. A display surface is the physical screen surface you are writing on.

But, although you'd write on a display surface in many cases you'd have a display buffer so that when you draw on the surface, you actually draw on the display buffer so that the user doesn't see the drawing happening and when you've finished drawing you flip the display buffer onto the surface so that the drawing appears instantaneously

A display context is the description of the physical charecteristics of the drawing surface e.g. width, height, color depth and so on. In win32 for example you obtain a device context for a particular piece of hardware - a printer or screen, but then you draw on this device context so it is also the display surface. Likewise you can obtain a device context for an offscreen bitmap (a display buffer). So the terms can blur a bit.

https://stackoverflow.com/questions/5076257/difference-between-displaycontext-displaysurface-displaybuffer




Functions: to look

eglGetCurrentDisplay
 
eglBindAPI
eglCreateContext
 
eglMakeCurrent

eglDestroySurface

eglGetConfigAttrib

eglGetDisplay

eglChooseConfig

eglInitialize
eglGetProcAddress
eglCreatePbufferSurface
eglQueryString
eglDestroyContext
eglGetError
eglTerminate
p_eglCreateImageKHR
p_eglDestroyImageKHR
 
Read what these egl APIs do 
 