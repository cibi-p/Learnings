# Image Processing
## Intensity Transformations and Spatial Filtering

**Spatial filtering Formula**  
$g( x,y ) = T[f( x,y )]$

where f(x,y) is an input image,  
g(x,y) is an output image  
T is an operator  

for uderstanding g(x,y) is represented as s  
f(x,y) is represented as r

**Transformation**
- Image Negative  
    s = Max_Possible_Val - r

- Log Transformation  
    s = constant * log(1+r)

- Power Law ( GAMMA ) Transformations  
    $s = cr^\gamma$  ( for many monitor and divice gamma correction is needed)

- Piecewice Linear Transformation Function  
    Contrast Stretching  
    Intensity-Level Slicing
    Bit-Plane Slicing

**Histogram Processing**  
$r_k$ -> denotes intensity ( ex: 0 to 255 for 8bit )  
$n_k$ -> is the number of pixels in image f(x,y)  with the intensity $r_k$  

sub division of the intensity scale are called *histogram bins*.  

Normalized histogram of f is defined as  
$p(r_k)=\frac{h(r_k)}{MN} =\frac{n_k}{MN}$  
where as M and N are the number of image rows and columns

## MATH FORMULAS (EXPLANATION/LINK)




