# Image-processing-Pixora
Overview
This project is a C++ command-line application designed for applying various graphical filters and transformations to images. It supports loading, manipulating, and saving images in multiple popular formats.

Technologies Used
C++: The core language used for all image processing logic.
stb_image.h & stb_image_write.h: Lightweight single-file header libraries used to handle decoding (loading) and encoding (saving) of image files without depending on heavy external libraries.
Object-Oriented Programming (OOP) Design
The project leverages the principles of Object-Oriented Programming to encapsulate image data and operations.

Encapsulation & Data Hiding: The Image class isolates the actual raw image buffer (imageData), width, height, and color channels, preventing arbitrary and unsafe manipulation of memory outside of defined methods.
Resource Management: Uses RAII (Resource Acquisition Is Initialization), intelligently managing dynamic memory via constructors and a destructor which automatically frees the imageData using stbi_image_free when an Image object goes out of scope.
Overloaded Operators & Rule-of-Three: Includes a custom copy constructor and assignment operator (operator=) to guarantee safe deep copying of the dynamically allocated image buffers, allowing intuitive usage like image1 = image2. The function call operator operator() is also overloaded for easy and semantic access/modification of pixel channels: image(x, y, channel).
Exception Handling: Validations such as checking image boundaries during pixel access or confirming allowed filename extensions throw exceptions (e.g., std::invalid_argument, std::out_of_range) to handle errors gracefully.
Features & Supported Filters
The application features an interactive menu that lets users apply the following modifications to an image:

Invert Filter: Produces a negative effect by inverting the color channels.
Rotate Filter: Rotates the image by 90, 180, or 270 degrees.
Grayscale: Converts a color image into shades of grey.
Darken / Lighten: Adjusts the brightness of the image (0.5x for darken, 1.5x for lighten).
Black and White: Reduces the image to pure black and white (no grey) based on a threshold.
Flip Image: Mirrors the original image either horizontally or vertically.
Add Frame: Adds a decorative border (either a solid blue simple frame or a red & white fancy striped frame).
Crop Image: Slices the image to keep a specific rectangular segment.
Blur Filter: Softens the image by averaging neighboring pixels, tunable across three intensity levels (low, medium, high).
Merge Images: Combines two images by taking the average of their pixel values. Matches dimensions by resizing or taking the common overlap.
Detect Edges: Highlights sharp color changes between neighboring pixels to trace figure outlines.
Sunlight: Imbues the image with a bright, warm yellowish tone.
Resize: Rescales the image dimensions by a given ratio or to absolute custom width/height values.
Infrared Filter: Simulates infrared photography by significantly boosting the red channel while inverting greens and blues.
Purple Filter: Adjusts color blends to give the image a distinct purple hue.
Horizontal Shearing: Skews the image horizontally.
Supported Formats
Supports reading and writing:

.JPG / .JPEG
.PNG
.BMP
.TGA
Team Members
Lojain mohammed
Nadine Khaled
Farida Amr
How to Compile & Run
Simply compile the main .cpp file. Ensure that stb_image.h and stb_image_write.h and Image_Class.h are located in the include directory for successful compilation.
