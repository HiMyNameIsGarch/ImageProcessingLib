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
<forum style="font-size:18px; color: #E78587">
 - Apply different filters (e.g., mean blur, Gaussian blur, box blur, horizontal Sobel, vertical Sobel). </br>
 - Adjust the brightness</br>
 - Apply gamma correction</br>
 - Draw a circle / line / rectangle</br>
 - Extract a Region Of Interest</br>
 - Return the intersection of 2 rectangles.</br>
 - Return the union of 2 rectangles.</br>
</forum>


# Testes images
The project will be tested using the following images:
The images are not mine, they were taken from the following link: https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html

# Sample images
The sample image is the following: </br>
![Sample image](https://github.com/HiMyNameIsGarch/ImageProcessingLib/blob/convolution/samples/load/sample.png,)

# Image Processing

## Brightness
The brightness operation increases or decreases the brightness of an image. The operation takes an
#### Brightness correction (value: 1 with 35)
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
The gamma correction operation adjusts the brightness of an image by using a gamma value. The gamma value is a floating-point value that is greater than 0. The gamma correction operation is defined as follows:
#### Dark gamma correction (value: 0.65)
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
#### Light gamma correction (value: 1.35)
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

### Identiy
The identity operation does not change the image.

### Mean blur
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
