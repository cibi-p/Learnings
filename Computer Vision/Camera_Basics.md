# Camera
## Defination
A device which captures the ambient light and converts it to an image or video. The term camera comes from the word camera obscura (Latin for "dark chamber"), an early mechanism for projecting images.
Types –  
- Analog Cameras
- Digital Cameras

### Analog Cameras
Analog cameras use films which are exposed for a period defined by opening of the shutter to produce images.
![image](https://github.com/cibi-p/Learnings/assets/57592824/a3792e0c-f646-49aa-86c0-4f3438d45c52)

<sub> **REFER**:  
[ Working ](https://dustygrain.com/how-does-a-film-camera-work/#Basic_operation_of_a_camera)  
[ PinHole Camera Making ](https://byjus.com/physics/pinhole-camera/)  
</sub>
![image](https://github.com/cibi-p/Learnings/assets/57592824/bdebbfbb-1f53-4469-a41b-394dbaf95b2b)
image 1  

![image](https://github.com/cibi-p/Learnings/assets/57592824/5ebafcf8-23fb-4a10-9572-9552d0bc6e89)
image 2  

<sub> **LENS REFER.:**
[ focus Working ](https://www.videomaker.com/how-to/technology/lenses-how-does-focus-work/)  
[ (V) focus Expl. ](https://www.youtube.com/watch?v=Aio8rn7lkY0)  
[ Conved and Concave lenses, focus ( for image 2 ) ](https://www.youtube.com/watch?v=CJ6aB5ULqa0)

**Field of View**  
![image](https://github.com/cibi-p/Learnings/assets/57592824/db7d3cd0-0f41-4e72-83c1-0c909bf99af8)
![image](https://github.com/cibi-p/Learnings/assets/57592824/4f2f3bee-a882-45dd-a2b2-e5c3a0fc4e55)
![image](https://github.com/cibi-p/Learnings/assets/57592824/ec820175-1bcd-4fdf-ad97-d2201961392c)

</sub>

<sub> **SHUTTER**  
[ Shutter ](https://www.youtube.com/watch?v=xX9w98dHVLg)  
[ Mechanical, Electronic Shutter ](https://www.youtube.com/watch?v=FNScFNl4Jro)  
</sub>  
<sub> **APERTURE**  
Aperture = focal Length / diaprame size  
example ( f/1.4, f/2.8, f/5.6, f/16 )  
f/1.4  -> More light, less depth of field ( backgroud blur with clear subject )  
.  
.  
f/16   -> Less Light, more depth of field ( clear background with clear subject )  \

it works similar to the working of human eye pupils

[ Aperture ](https://www.youtube.com/watch?v=-INjs9tIfkE)

![image](https://github.com/cibi-p/Learnings/assets/57592824/66bb651f-de02-4280-b089-7ce61868b3d9)
</sub>

<sub> **ISO**  
[ ISO DEF. Camera ](https://www.youtube.com/watch?v=fBxsCNF5ims)

Iso deside the light sensitivity of the sensor...  
If it is low, sensor will be less sensitive to the light and vise versa.  

most common ISO values are 100 200 400 800 1600 3000

we can use it whith sutter speed to take the image in low light... condition... etc...

Higher the ISO Lower the dynamic range...

<details><summary>Why Noise is produced when increasing the ISO?</summary>
Noise is caused by the random variation of the electrical signals that your sensor converts from light. When there is not enough light, your sensor has to amplify the signals to create an image, but this also amplifies the noise. The higher the ISO, the more amplification your sensor needs, and the more noise you will see in your image. Noise is more noticeable in dark areas, where there is less signal and more amplification
</details>

<details><summary>What is dynamic range?</summary>
 Essentially, dynamic range is how far the brightest spots in your image can vary from the darkest spots in your image and still maintain proper details in a single exposure. The more you have, the more you can capture scenes with a great contrast between lights and darks. This often comes into play when shooting sunsets and sunrises since the sky is usually bright and the foreground is usually dark.

If you’ve ever had to take a photograph on a bright sunny day, chances are pretty high that you would have lost detail, possibly in the shadows or in the highlights, perhaps even both. This is not an exposure problem on your part. It’s more likely a limitation of the dynamic range of your camera. Almost all cameras will come up against this problem at some time.

Dynamic range is one of the most important, yet least understood features to keep in mind when buying a camera. If you’ve ever gotten home to realize that you’ve lost the details in the bright sky in your image and the foreground seems to be too dark, you’ve experienced dynamic range

**REG.**  
[Dynamic Range Expla.](https://www.adorama.com/alc/dynamic-range-photography-explained/)

</details>
</sub>

### Digital Camera
![digital camera diagram ](https://github.com/cibi-p/Learnings/assets/57592824/4a23b5ae-b12b-4908-98c4-2d3bc6f6fbc0)

**Image Sensor**  
An image sensor is a solid-state electrical device that converts light (photons) to electronic signal form. 
The sensor has many tiny wells known as pixels, and in each pixel there will be a light sensitive element which can sense how many photons have arrived at that particular location. The charge output from each location is proportional to the intensity of light falling onto it.
This charge has to be converted into a signal, amplified and then converted to digital form.
The first digital camera used a charge-coupled device was invented by Steven Sasson, an engineer at Kodak Company.

![anatomy of a sensor](https://github.com/cibi-p/Learnings/assets/57592824/806d82d3-6cc2-4759-b579-a40555abd242)

**Color filter Array (CFA) or Color Filter Mosaic (CFM)**  
In digital imaging, a color filter array (CFA), or color filter mosaic (CFM), is a mosaic of tiny color filters placed over the pixel sensors of an image sensor to capture color information.

![Image color filter](https://github.com/cibi-p/Learnings/assets/57592824/49a978d7-b95a-4fd9-b29a-e38b2ceb150a)

Color filters are needed because the typical photosensors detect light intensity with little or no wavelength specificity and therefore cannot separate color information.[1] Since sensors are made of semiconductors, they obey solid-state physics.

The color filters filter the light by wavelength range, such that the separate filtered intensities include information about the color of light. For example, the Bayer filter (shown by the image) gives information about the intensity of light in red, green, and blue (RGB) wavelength regions. The raw image data captured by the image sensor is then converted to a full-color image (with intensities of all three primary colors represented at each pixel) by a demosaicing algorithm which is tailored for each type of color filter. The spectral transmittance of the CFA elements along with the demosaicing algorithm jointly determine the color rendition. The sensor's passband quantum efficiency and span of the CFA's spectral responses are typically wider than the visible spectrum, thus all visible colors can be distinguished. The responses of the filters do not generally correspond to the CIE color matching functions, so a color translation is required to convert the tristimulus values into a common, absolute color space.

Types of Color Filter array

![Types of CFA](https://github.com/cibi-p/Learnings/assets/57592824/11fda6cf-adeb-4262-9d3a-8ac17d8d2406)  
[more in wikipedia](https://en.wikipedia.org/wiki/Color_filter_array#:~:text=7%20References-,Image%20sensor%20overview,they%20obey%20solid%2Dstate%20physics.)

**BayerFilter**  
-> 1 pixel containt 1 blue, 1 red, and 2 green filter  
-> denoted as RGBG or BGGR or GRBG or RGGB

<details>
<summary>Why green is twice ?</summary>

An experiment shows that under normal light, rods cells are highly sensitive at or above 500nm which is sort of the border of blue moving into green in the visible spectrum.   
There are 10millions of the rod cell, and 6 million of cone cells. and rods see green best.  

![image](https://github.com/cibi-p/Learnings/assets/57592824/ce235fa9-2cd3-4a05-be26-ee2f08debfed) 

Human eye is more sensitive to the light present and less sensitive to the range of color.
When the light levels drop to near total darkness, the response of the eye changes significantly as shown by the scotopic response curve on the left.  At this level of light, the rods are most active and the human eye is more sensitive to the light present, and less sensitive to the range of color

To see saturated colour, the brain does more or less the same sort of processing that has to happen in a Bayer-sensor camera in order to recover full-colour information. The reason this gives us best acuity in green is simply that there's really a lot of overlap between the medium and long (green and red) cones. This happens to the point where the medium-length cones can see everything from a greenish turquoise all the way through to, well, a fairly orange yellow, while the red cones can see from mid-green to the borders of infra-red. The result is an overall peak of sensitivity at a place which really looks pretty green, despite the fact that we can also see red using the same anatomy.

The retina is a mosaic of two basic types of photoreceptors: rods, and cones. Rods are sensitive to blue-green light with peak sensitivity at a wavelength of 498 nm, and are used for vision under dark or dim conditions. There are three types of cones that give us our basic color vision: L-cones (red) with a peak sensitivity of 564 nm, M-cones (green) with a peak sensitivity of 533 nm, and S-cones (blue) with a peak sensitivity of 437 nm.  
[![image](https://github.com/cibi-p/Learnings/assets/57592824/a605349c-47c2-465a-9a90-3c28ba71bc54)](https://courses.cs.washington.edu/courses/cse467/08au/labs/l5/whiteBalance.pdf)

**REF.**  
[ important article ](https://www.nde-ed.org/NDETechniques/PenetrantTest/Introduction/visualacuity.xhtml)  
[ article * ](https://www.redsharknews.com/technology-computing/item/4741-human-vision-and-why-the-colour-green-is-so-important)
 [ signal snesor imaging ](https://courses.cs.washington.edu/courses/cse467/08au/labs/l5/whiteBalance.pdf)

</details>

-> Bayer ( who invented ) called the grenn photosensor luminance-sensitive element and the red and blue ones are chroinance-sensitive elements. he used twice as many green elements compared to blue one to mimic human eye

<sub> Luminance is the brightness information, chrominance is the color information </sub>

Ref.: [ Bayer Filter ](https://youtu.be/lyf5jGIrwQE?si=qQ1NddQ7hJUQdErH)

Color filter Reconstruction algorithm - demosaicing  

Other  
color correction

**demosaicing Algorithm**  
- nearest-neighbor interpolation
- bilinear interpolation
- bicubic interpolation
- spline interpolation
- Lanczos resampling

<sup>interpolation is a type of  estimation, a method of constructing (finding ) new data points based on the range of discrete set of know data points</sup>

![nearest-neighbor](https://github.com/cibi-p/Learnings/assets/57592824/1954aca5-062d-4286-89a7-0fa8e857133a)

![bilinear](https://github.com/cibi-p/Learnings/assets/57592824/cff0c5c4-da7f-44e5-8778-5e7cee31e438)  
[ bilinear expl. with math ](https://en.wikipedia.org/wiki/Bilinear_interpolation)


**Types of Sensors**
- CCD
- CMOS

  
![image](https://github.com/cibi-p/Learnings/assets/57592824/72680052-30c2-4860-8450-365626259e66)  
![image](https://github.com/cibi-p/Learnings/assets/57592824/07041ac7-025b-4474-ae3f-538c1d705cbb)  

[ CDD , CMOS (V) ](https://www.youtube.com/watch?v=FKJFIzDfUNE)


# ISP ( Image Signal Processing )

## White Balancing  
When the image is taken in low light the image will have red or orange shade, if the image in taken in high light condition the image will apper in blue color. the aim of this balancing is to make white ( and other colors ) same as white in all lightening conition.

![white balance image](https://github.com/cibi-p/Learnings/assets/57592824/3abcd446-8683-4bf0-acf3-db4b5643acc1)

**How to solve white balance issue?**  
**Manual Method**  
use the color cords to take the sample image and find how the color is differentiate from the actual value of the particular color, use those information to get the original color...
![color cards](https://github.com/cibi-p/Learnings/assets/57592824/a8976afe-4b28-4c2e-acde-75f4bc431ced)

### Algorithm
1. White Patch Algorithm
2. Gray-world Algorithm
3. Iterative White Balancing
4. Illuminant voting
5. Color by Correlation

<sub>[Ref. Book](https://last.hit.bme.hu/download/firtha/video/Sensors/Rastislav_Lukac_Single-Sensor_Imaging_Methods_and_Applications_for_Digital_Cameras__2009.pdf)</sub>

**White Patch Algorithm:**  
     This approach is typical of the Color Constancy adaptation where it searches for the lightest patch to use as a white reference similar to how the human visual system does. Note that for white to be observed in the image, each channel in you RGB color space should be at its maximum value.

![Expla-1](https://github.com/cibi-p/Learnings/assets/57592824/df1edb77-0078-4d0a-b2db-c9877228ba0d)
![Expla-2](https://github.com/cibi-p/Learnings/assets/57592824/7d235c23-e940-4a9f-9384-c6063a20bc3d)


----

**Gray-world Algorithm:**  
![Gray World Explanation](https://github.com/cibi-p/Learnings/assets/57592824/0ddbed8c-7be4-4890-b177-46f08518d282)

This is not effective if the certain color may dominate, such as blue hue for the sky or when a object with a susstantial amount of a certain color occupies the manority of the view.


**Iterative White Balancing**  
![IWB-expla-1](https://github.com/cibi-p/Learnings/assets/57592824/109eec3e-e3ff-4828-95fa-80273defb10c)
![IWB-expla-2](https://github.com/cibi-p/Learnings/assets/57592824/2aee50d3-315f-410b-b786-6607c6f1201f)

**Illuminannt Voting and Color by Correlation**  
found [here (Book: single-Sensor Imaging: Methods and Applications for Digital Cameras)](https://last.hit.bme.hu/download/firtha/video/Sensors/Rastislav_Lukac_Single-Sensor_Imaging_Methods_and_Applications_for_Digital_Cameras__2009.pdf)

## Image Contrast
Contrast is really just a measure of the difference between the maximum and minimum pixel intensities in an image. So, in order to increase the contrast in an image, we need to increase the distance between the maximum and minimum pixel intensities.

**Algorithm**
1. Contrast Stretching/Histogram Stretching
2. Histogram Equalization
3. NonLinear Stretching
4. Histogram specifiaction
5. Adaptive Histogram Modification

**Ref.**  
[ Contrast algo. ](https://aryamansharda.medium.com/understanding-image-contrast-algorithms-8636723a0f05)  


**Contrast Stretching/Histogram Stretching**  
![image](https://github.com/cibi-p/Learnings/assets/57592824/6e18b97c-903a-42d6-af2a-3cf997222b53)






     






