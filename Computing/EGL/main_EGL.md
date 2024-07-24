# EGL

An interface between rendering APIs such as OpenCL, OpenGL, OpenGL ES or OpenVG (referred to collectively as client APIs) and one or more underlying platforms (typically window systems such as X11). 

*EGL provides mechanisms for creating rendering surfaces onto which client APIs* can draw, creating graphics contexts for client APIs, and synchronizing drawing by client APIs as well as platform rendering APIs. EGL does not explicitly support remote or indirect rendering, unlike the similar GLX API.

Specification referred  
https://registry.khronos.org/EGL/specs/eglspec.1.5.pdf





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
 