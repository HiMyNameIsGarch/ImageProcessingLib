# Image Processing Library C++
<p style="font-size:20px">
    Implementation of a basic image processing application using C++
</p>

<p style="font-size:18px">
    The building block of the project will be a class that implements the image abstract data type. The
    application will support only grayscale images. A grayscale image is represented by a 2D array of
    pixels, and each pixel can take a value from the interval [0, 255], where the value 0 represents black,
    and the value 255 represents white. Values in between encode different shades of gray (the higher the
    value, the lighter the gray tone is).
</p>

# What can the library do?
#### The library can perform the following operations:
<p style="font-size:18px; color: #E78587">
 - Apply different filters (e.g., mean blur, Gaussian blur, box blur, horizontal Sobel, vertical Sobel). </br>
 - Adjust the brightness</br>
 - Apply gamma correction</br>
 - Draw a circle / line / rectangle</br>
 - Extract a Region Of Interest</br>
 - Return the intersection of 2 rectangles.</br>
 - Return the union of 2 rectangles.</br>
</p>


# Testes images
The project will be tested using the following images:
The images are not mine, they were taken from the following link: https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html

# Image Processing

## Brightness
The brightness operation increases or decreases the brightness of an image.

#### Brightness correction (gain: 1, bias: 35)
The formula for the brightness correction is:
```
output = input * gain + bias
```
where `input` is the pixel value of the input image, `gain` is a floating-point value that is greater than 0, and `bias` is an integer value.

<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-brightness.png" style="width: 30%;">
    </div>
</div>

## Gamma correction
The gamma correction operation adjusts the brightness of an image by using a gamma value. The gamma value is a floating-point value that is greater than 0.

#### Dark gamma correction (gamma: 0.65)
Where the formula for the gamma correction is:
```
output = pow(input, gamma)
```
where `input` is the pixel value of the input image, and `gamma` is a floating-point value that is greater or smaller than 0.

<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-gamma-light.png" style="width: 30%;">
    </div>
</div>

#### Light gamma correction (gamma: 1.35)

<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-gamma-dark.png" style="width: 30%;">
    </div>
</div>

## Convolution
The convolution operation applies a kernel to an image.
The kernel is hardcoded to be exactly 3x3.
Nonetheless, the code can be easily modified to support any kernel size.

### Identiy
The identity operation does not change the image.

### Mean blur
The mean blur operation blurs an image by averaging the pixel values in the
neighborhood of each pixel. (for this kernel, the scaling function should just
multiply the convolution result to 1/9)

<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-mean-blur.png" style="width: 30%;">
    </div>
</div>

### Gaussian Blur
Still a blurring kernel, but in this
case, the central pixel of the kernel has a higher weight in the
mean operation; for this kernel, the scaling function should
just multiply the convolution result to 1/16.0)
<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-gaussian-blur.png" style="width: 30%;">
    </div>
</div>

### Box Blur (optional)
<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-convolution.png" style="width: 30%;">
    </div>
</div>

### Horizontal Sobel
Used to detect horizontal edges.
In this case, the scaling function should be a linear mapping
function that converts the range [-4*255, 4*255] to the range [0, 255]).
<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-horizontal-sobel.png" style="width: 30%;">
    </div>
</div>

### Vertical Sobel
Vertical Sobel kernel. Used to detect vertical edges. In this
case, the scaling function should be a linear mapping
function that converts the range [-4*255, 4*255] to the range
[0, 255]).
<div style="display: flex;">
    <div style="width: 50%; text-align: center;">
        <p>Before</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png" style="width: 30%;">
    </div>
    <div style="width: 50%; text-align: center;">
        <p>After</p>
        <img src="https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/saved/sample-vertical-sobel.png" style="width: 30%;">
    </div>
</div>
