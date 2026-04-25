/*
==============================================================================
The team members are:
-Farida Ahmed (ID: 20240411) - Section 22
-Lojain Mohamed (ID: 20240435) - Section 24
-Nadine Khaled (ID: 20240625) - Section 22

1-Farida did filters 1,4,7,10 (Grayscale conversion, Merge images, Darken and lighten image, Detect image edges)
2-Lojain did filters 2,5,8,11 (Black and White conversion, Flip image, Crop image, Resize image)
3-Nadine did filters 3,6,9,12 (Invert image, Rotate image, Add frame to image, Blur image) + the menu + bonus filter 17

Our link to the demo of the program:
https://drive.google.com/drive/folders/1rmk8Zt7k7nZ5Af-kQi2LKPsN6QGcPf1c?usp=sharing

Our link to the shared document:
https://docs.google.com/document/d/1_KUnnx78CxNAdGXnNewyp3ITH8jLw2FBhgw99G83w0M/edit?usp=sharing

Our link to the GitHub repo:
https://github.com/nadine265/my-oop-assignment.git

==============================================================================
*/


#include "Image_Class.h"
#include <iostream>
#include <string>

using namespace std;
void InvertedImage(const string& filename,const string& extension) {
    Image image(filename);
    for(int i=0;i<image.width;i++) {
        for(int j=0;j<image.height;j++) {
            for(int k=0;k<3;k++) {
                image(i,j,k)=255-image(i,j,k);
            }
        }
    }
    cout << "Do you want to save the image with its current name or rename it ?" << endl;
    cout << "1. current name" << endl;
    cout << "2. rename it" << endl;
    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            image.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            image.saveImage(newname +"." + extension);
            break;
        }
    }
}

void BlackandWhiteImage(const string &filename, const string &extension) {
    Image image(filename);

for (int i=0; i<image.width;  i++) {
        for (int j=0; j<image.height; j++) {
            unsigned int average = 0;
            for (int k=0; k<image.channels; k++) {
                average +=image(i,j,k);
            }
            average /=3;
            for (int k=0; k<image.channels; k++) {
                image(i,j,k) = average;
            }
        }
    };

    int threshold = 128;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned char value = image(i, j, 0);
            unsigned char bw = (value > threshold) ? 255 : 0;
            image(i, j, 0) = image(i, j, 1) = image(i, j, 2) = bw;
        }
    }

    cout << "Black and White filter applied successfully!\n";

    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";

    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            image.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            image.saveImage(newname +"." + extension);
            break;
        }
    }
}



void FlipImage(const string &filename, const string &extension) {
    cout << "Select flip type:\n";
    cout << "1. Horizontal\n2. Vertical\n";
    int flipChoice;
    cin >> flipChoice;

    Image image(filename );

    if (flipChoice == 1) {
        int w = image.width;
        for (int m = 0; m < w/2; ++m) {
            for (int n = 0; n < image.height; ++n) {
                for (int k = 0; k < image.channels; ++k) {
                    unsigned char tmp = image(m,n,k);
                    image(m,n,k)     = image(w-1-m,n,k);
                    image(w-1-m,n,k) = tmp;
                }
            }
        }
        cout << "Horizontal flip done.\n";
    } else if (flipChoice == 2) {
        int h = image.height;
        for (int m = 0; m < image.width; ++m) {
            for (int n = 0; n < h/2; ++n) {
                for (int k = 0; k < image.channels; ++k) {
                    unsigned char tmp = image(m,n,k);
                    image(m,n,k)     = image(m,h-1-n,k);
                    image(m,h-1-n,k) = tmp;
                }
            }
        }
        cout << "Vertical flip done.\n";
    } else {
        cout << "Invalid flip choice.\n";
        return;
    }

    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";

    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            image.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            image.saveImage(newname +"." + extension);
            break;
        }
    }
}



void CropImage(const string &filename, const string &extension) {
    Image image(filename);

    int x, y, w, h;
    cout << "Enter starting x and y (top-left corner): ";
    cin >> x >> y;
    cout << "Enter width (w) and height (h): ";
    cin >> w >> h;

    if (x < 0 || y < 0 || x + w > image.width || y + h > image.height) {
        cout << "Invalid crop dimensions!" << endl;
        return;
    }

    Image cropped(w, h);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < image.channels; k++) {
                cropped.setPixel(i, j, k, image.getPixel(x + i, y + j, k));
            }
        }
    }

    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";

    int savedecision;
    cin >> savedecision;

    switch (savedecision) {
        case 1: {
            cropped.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name: ";
            cin >> newname;
            cropped.saveImage(newname + "." + extension);
            break;
        }
        default:
            cout << "Invalid choice!\n";
        return;
    }

    cout << "Cropping done successfully.\n";
}

void ResizeImage(const string &filename, const string &extension) {
    Image image(filename);

    int newWidth, newHeight;
    cout << "Enter new width: ";
    cin >> newWidth;
    cout << "Enter new height: ";
    cin >> newHeight;

    if (newWidth <= 0 || newHeight <= 0) {
        cout << "Invalid dimensions!\n";
        return;
    }

    int oldWidth = image.width;
    int oldHeight = image.height;

    Image resized(newWidth, newHeight);

    double x_ratio = static_cast<double>(oldWidth) / newWidth;
    double y_ratio = static_cast<double>(oldHeight) / newHeight;

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            int oldX = static_cast<int>(x * x_ratio);
            int oldY = static_cast<int>(y * y_ratio);

            if (oldX >= oldWidth) oldX = oldWidth - 1;
            if (oldY >= oldHeight) oldY = oldHeight - 1;

            for (int c = 0; c < image.channels; c++) {
                unsigned char value = image.getPixel(oldX, oldY, c);
                resized.setPixel(x, y, c, value);
            }
        }
    }

    cout << "\nDo you want to save the resized image with its current name or rename it?\n";
    cout << "1. Current name\n2. Rename it\n";

    int saveDecision;
    cin >> saveDecision;

    switch (saveDecision) {
        case 1: {
            resized.saveImage(filename);
            break;
        }
        case 2: {
            string newName;
            cout << "Please enter the new image name: ";
            cin >> newName;
            resized.saveImage(newName + "." + extension);
            break;
        }
        default:
            cout << "Invalid choice!\n";
            return;
    }

    cout << " Image resized successfully to "
         << newWidth << " x " << newHeight << " pixels.\n";
}


void RotatedImage (const string& filename, const string& extension) {
    Image image(filename);
    int type;
    int anotherrotation;
    do {
        cout << "Please choose the rotation type:" << endl;
        cout << "1. 90 degrees clockwise" << endl;
        cout << "2. 180 degrees clockwise" << endl;
        cout << "3. 270 degrees clockwise" << endl;
        cin >> type;

        Image rotatedimage;
        switch (type) {
            case 1:
                rotatedimage=Image(image.height, image.width);
            for (int i=0;i<image.width;i++) {
                for (int j=0;j<image.height;j++) {
                    for (int k=0;k<3;k++) {
                        rotatedimage(image.height-1-j,i,k)=image(i,j,k);
                    }
                }
            }
            cout << "Do you want to save the image with its current name or rename it ?" << endl;
            cout << "1. current name" << endl;
            cout << "2. rename it" << endl;
            int savedecision;
            cin >> savedecision;
            switch(savedecision) {
                case 1: {
                    rotatedimage.saveImage(filename);
                    break;
                }
                case 2: {
                    string newname;
                    cout << "Please enter the new image name " << endl;
                    cin >> newname;
                    rotatedimage.saveImage(newname +"." + extension);
                    break;
                }
            }
            break;
            case 2:
                rotatedimage=Image(image.width, image.height);
            for (int i=0;i<image.width;i++) {
                for (int j=0;j<image.height;j++) {
                    for (int k=0;k<3;k++) {
                        rotatedimage(image.width-1-i,image.height-1-j,k)=image(i,j,k);
                    }
                }
            }
            cout << "Do you want to save the image with its current name or rename it ?" << endl;
            cout << "1. current name" << endl;
            cout << "2. rename it" << endl;
            cin >> savedecision;
            switch(savedecision) {
                case 1: {
                    rotatedimage.saveImage(filename);
                    break;
                }
                case 2: {
                    string newname;
                    cout << "Please enter the new image name " << endl;
                    cin >> newname;
                    rotatedimage.saveImage(newname +"." + extension);
                    break;
                }
            }
            break;
            case 3:
                rotatedimage=Image(image.height, image.width);
            for (int i=0;i<image.width;i++) {
                for (int j=0;j<image.height;j++) {
                    for (int k=0;k<3;k++) {
                        rotatedimage(j,image.width-1-i,k)=image(i,j,k);
                    }
                }
            }
            cout << "Do you want to save the image with its current name or rename it ?" << endl;
            cout << "1. current name" << endl;
            cout << "2. rename it" << endl;
            cin >> savedecision;
            switch(savedecision) {
                case 1: {
                    rotatedimage.saveImage(filename);
                    break;
                }
                case 2: {
                    string newname;
                    cout << "Please enter the new image name " << endl;
                    cin >> newname;
                    rotatedimage.saveImage(newname +"." + extension);
                    break;
                }
            }
            break;
            default:
                cout << "Invalid type" << endl;
        }
        cout << "Do you want to perform another rotation?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> anotherrotation;
    } while (anotherrotation==1);
}
void AddFrame(const string &filename, const string &extension) {
    Image image(filename);
    int width = image.width;
    int height = image.height;
    int thickness;
    cout << "Enter frame thickness: " << endl;
    cin >> thickness;
    int r, g, b;
    cout << "Enter frame color (R G B) each value from 0 to 255: " << endl;
    cin >> r >> g >> b;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (i < thickness || i>= width - thickness ||j < thickness || j >= height - thickness) {
                image.setPixel(i, j, 0, r);
                image.setPixel(i, j, 1, g);
                image.setPixel(i, j, 2, b);
            }
        }
    }
    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";
    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            image.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            image.saveImage(newname + "." + extension);
            break;
        }
    }
}
void applyBlur(const string& filename, int kernelSize, const string& extension) {
    Image image(filename);
    int steps = kernelSize / 2;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            for (int ky = -steps; ky <= steps; ky++) {
                for (int kx = -steps; kx <= steps; kx++) {
                    int nx = x + kx;
                    int ny = y + ky;
                    if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {
                        sumR += image.getPixel(nx, ny, 0);
                        sumG += image.getPixel(nx, ny, 1);
                        sumB += image.getPixel(nx, ny, 2);
                        count++;
                    }
                }
            }
            unsigned char avgR = sumR / count;
            unsigned char avgG = sumG / count;
            unsigned char avgB = sumB / count;
            image.setPixel(x, y, 0, avgR);
            image.setPixel(x, y, 1, avgG);
            image.setPixel(x, y, 2, avgB);
        }
    }
    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";
    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            image.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            image.saveImage(newname + "." + extension);
            break;
        }
    }
}

void MergeImage(const string& filename, const string& filename2, const string& extension) {
    Image I1(filename);
    Image I2(filename2);
    cout<<"choose merge option\n";
    cout<<"option 1: merge by resizing\n";
    cout<<"option 2: merge common area\n";
    int choice;
    cin>>choice;
    if(choice == 1) {
        int w = max(I1.width, I2.width);
        int h = max(I1.height, I2.height);
        Image out(w, h);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                int x1 = i * I1.width / w;
                int y1 = j * I1.height / h;
                int x2 = i * I2.width / w;
                int y2 = j * I2.height / h;
                for (int k = 0; k < 3; k++) {
                    int v1 = I1(x1, y1, k);
                    int v2 = I2(x2, y2, k);
                    out(i, j, k) = (v1 + v2) / 2;
                }
            }
        }
        cout << "Do you want to save the image with its current name or rename it ?" << endl;
        cout << "1. current name" << endl;
        cout << "2. rename it" << endl;
        int savedecision;
        cin >> savedecision;
        switch(savedecision) {
            case 1: {
                out.saveImage(filename);
                break;
            }
            case 2: {
                string newname;
                cout << "Please enter the new image name " << endl;
                cin >> newname;
                out.saveImage(newname +"." + extension);
                break;
            }
        }
        cout<<"photo is merged\n";
    }
    else if(choice == 2) {
        int w = min(I1.width, I2.width);
        int h = min(I1.height, I2.height);
        Image out(w, h);

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                for (int k = 0; k < 3; k++) {
                    int v1 = I1(i, j, k);
                    int v2 = I2(i, j, k);
                    out(i, j, k) = (v1 + v2) / 2;
                }
            }
        }
        cout << "Do you want to save the image with its current name or rename it ?" << endl;
        cout << "1. current name" << endl;
        cout << "2. rename it" << endl;
        int savedecision;
        cin >> savedecision;
        switch(savedecision) {
            case 1: {
                out.saveImage(filename);
                break;
            }
            case 2: {
                string newname;
                cout << "Please enter the new image name " << endl;
                cin >> newname;
                out.saveImage(newname +"." + extension);
                break;
            }
        }
    }
}


void GrayscaleImage(const string& filename, const string& extension) {
    Image I1(filename);
    for (int i=0; i<I1.width;  i++) {
        for (int j=0; j<I1.height; j++) {
            unsigned int average = 0;
            for (int k=0; k<I1.channels; k++) {
                average +=I1(i,j,k);
            }
            average /=3;
            for (int k=0; k<I1.channels; k++) {
                I1(i,j,k) = average;
            }
        }
    };
    cout << "Do you want to save the image with its current name or rename it ?" << endl;
    cout << "1. current name" << endl;
    cout << "2. rename it" << endl;
    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            I1.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            I1.saveImage(newname +"." + extension);
            break;
        }
    }
}

Image GaussianBlur(const Image& input,const string& filename) {
    float kernel[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };
    float sum = 16.0f;
    Image output(input.width, input.height);

    for (int y = 1; y < input.height - 1; ++y) {
        for (int x = 1; x < input.width - 1; ++x) {
            for (int c = 0; c < 3; ++c) {
                float value = 0;
                for (int j = -1; j <= 1; ++j) {
                    for (int i = -1; i <= 1; ++i) {
                        value += kernel[j + 1][i + 1] * input.getPixel(x + i, y + j, c);
                    }
                }
                unsigned char avg = static_cast<unsigned char>(value / sum);
                output.setPixel(x, y, c, avg);
            }
        }
    }

    for (int y = 0; y < input.height; ++y) {
        for (int c = 0; c < 3; ++c) {
            output.setPixel(0, y, c, input.getPixel(0, y, c));
            output.setPixel(input.width - 1, y, c, input.getPixel(input.width - 1, y, c));
        }
    }
    for (int x = 0; x < input.width; ++x) {
        for (int c = 0; c < 3; ++c) {
            output.setPixel(x, 0, c, input.getPixel(x, 0, c));
            output.setPixel(x, input.height - 1, c, input.getPixel(x, input.height - 1, c));
        }
    }
    return output;
}

void DetectImageEdges(const Image& I1,const string& filename ,const string& extension) {
    Image blurred = GaussianBlur(I1,filename);
    Image I2(I1.width, I1.height);

    for (int y = 0; y < I2.height; y++) {
        for (int x = 0; x < I2.width; x++) {
            for (int c = 0; c < 3; c++) {
                I2.setPixel(x, y, c, 255);
            }
        }
    }

    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    Image grayI1 = blurred;
    for (int y = 0; y < grayI1.height; y++) {
        for (int x = 0; x < grayI1.width; x++) {
            unsigned int average = 0;
            for (int k = 0; k < grayI1.channels; k++) {
                average += grayI1.getPixel(x, y, k);
            }
            average /= 3;
            for (int k = 0; k < grayI1.channels; k++) {
                grayI1.setPixel(x, y, k,static_cast<unsigned char>(average));
            }
        }
    }
    for (int y = 1; y < grayI1.height - 1; y++) {
        for (int x = 1; x < grayI1.width - 1; x++) {
            float horiz_sum = 0;
            float vert_sum = 0;

            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    unsigned char pi = grayI1.getPixel(x+i, y+j, 0);
                    horiz_sum += gx[j + 1][i + 1] * pi;
                    vert_sum += gy[j + 1][i + 1] * pi;
                }
            }

            int magnitude = static_cast<int>(sqrt(horiz_sum * horiz_sum + vert_sum * vert_sum));
            if (magnitude >100) {
                for (int c=0; c < 3; c++) {
                    I2.setPixel(x, y, c, 0);
                }
            }
        }
    }
    cout << "Do you want to save the image with its current name or rename it ?" << endl;
    cout << "1. current name" << endl;
    cout << "2. rename it" << endl;
    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            I2.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            I2.saveImage(newname +"." + extension);
            break;
        }
    }
    cout<<"photo is edged\n";

}

void Darker_lighterImage(const string& filename, const string& extension) {
    Image I1(filename);
    cout<<"if you want to darken the image choose 1\n";
    cout<<"if you want to lighten the image choose 2\n";
    int choice;
    cout<<"please enter your choice: ";
    cin>>choice;
    if(choice == 1) {
        for (int i=0; i<I1.width;  i++) {
            for (int j=0; j<I1.height; j++) {
                for (int k=0; k<I1.channels; k++) {
                    I1(i,j,k) = I1(i,j,k)*0.5;
                }
            }
        }
        cout<<"done\n";
        cout << "Do you want to save the image with its current name or rename it ?" << endl;
        cout << "1. current name" << endl;
        cout << "2. rename it" << endl;
        int savedecision;
        cin >> savedecision;
        switch(savedecision) {
            case 1: {
                I1.saveImage(filename);
                break;
            }
            case 2: {
                string newname;
                cout << "Please enter the new image name " << endl;
                cin >> newname;
                I1.saveImage(newname +"." + extension);
                break;
            }
        }
    }
    else if(choice == 2) {
        for (int i=0; i<I1.width; i++) {
            for (int j=0; j<I1.height; j++) {
                for (int k=0; k<I1.channels; k++) {
                    int newvalue = I1(i,j,k)*1.5;
                    if (newvalue > 255) {
                        newvalue = 255;
                    }
                    I1(i,j,k) = newvalue;
                }
            }
        }
        cout<<"done\n";
        cout << "Do you want to save the image with its current name or rename it ?" << endl;
        cout << "1. current name" << endl;
        cout << "2. rename it" << endl;
        int savedecision;
        cin >> savedecision;
        switch(savedecision) {
            case 1: {
                I1.saveImage(filename);
                break;
            }
            case 2: {
                string newname;
                cout << "Please enter the new image name " << endl;
                cin >> newname;
                I1.saveImage(newname +"." + extension);
                break;
            }
        }
    }
}
void InfraredFilter(const string& filename, const string& extension) {
    Image image(filename);
    Image result(image.width, image.height);
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            unsigned char r = image.getPixel(x, y, 0);
            unsigned char g = image.getPixel(x, y, 1);
            unsigned char b = image.getPixel(x, y, 2);
            unsigned char newR = 255;
            unsigned char newG = 255 - g;
            unsigned char newB = 255 - b;
            result.setPixel(x, y, 0, newR);
            result.setPixel(x, y, 1, newG);
            result.setPixel(x, y, 2, newB);
        }
    }
    cout << "Do you want to save the image with its current name or rename it ?" << endl;
    cout << "1. current name" << endl;
    cout << "2. rename it" << endl;
    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            result.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name " << endl;
            cin >> newname;
            result.saveImage(newname +"." + extension);
            break;
        }
    }
}

//Add purple filter

void PurpleFilter(const string &filename, const string &extension) {
    Image image(filename);

   
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned char r = image(i, j, 0);
            unsigned char g = image(i, j, 1);
            unsigned char b = image(i, j, 2);

            int newR = min(255, int(r * 1.2));
            int newG = max(0, int(g * 0.5));
            int newB = min(255, int(b * 1.4));

            image(i, j, 0) = newR;
            image(i, j, 1) = newG;
            image(i, j, 2) = newB;
        }
    }

    cout << "Purple filter applied successfully!\n";

    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";

    int savedecision;
    cin >> savedecision;
    switch(savedecision) {
        case 1: {
            image.saveImage(filename);
            break;
        }
        case 2: {
            string newname;
            cout << "Please enter the new image name: ";
            cin >> newname;
            image.saveImage(newname + "." + extension);
            break;
        }
    }
}

int main() {
    string filename;
    cout << "Please enter the file name:" << endl;
    cin >> filename;
    string extension;
    cout << "Please enter the new extension:" << endl;
    cout << "jpg/jpeg/png/bmp" << endl;
    cin >> extension;
    int cont=1;
    while (cont==1) {
        cout << "\nImage Processing Menu\n";
        cout << "1. Apply Grayscale filter\n";
        cout << "2. Apply Black and White filter\n";
        cout << "3. Apply Invert Color filter\n";
        cout << "4. Apply Merge Image filter\n";
        cout << "5. Apply Flip Image filter\n";
        cout << "6. Apply Rotate Image filter\n";
        cout << "7. Apply Frame Image filter\n";
        cout << "8. Apply Darken and Lighten Image filter\n";
        cout << "9. Apply Blur Image filter\n";
        cout << "10. Apply Detect Image Edges filter\n";
        cout << "11. Apply Crop Image filter\n";
        cout << "12. Apply Resize Image filter\n";
        cout << "13. Apply Infrared Image Filter\n";
        cout << "14.Apply Purple Filter\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Applying Grayscale filter" <<endl;
                GrayscaleImage(filename,extension);
                break;
            }
            case 2: {
                cout << "Applying Black and White filter" <<endl;
                BlackandWhiteImage(filename,extension);
                break;
            }

            case 3: {
                cout << "Applying Invert Colors filter" <<endl;
                InvertedImage(filename,extension);
                break;
            }
            case 4: {
                cout << "Applying Merge Image filter" <<endl;
                string filename2;
                cout << "Please enter the second image file name:" << endl;
                cin >> filename2;
                MergeImage(filename, filename2, extension);
                break;
            }
            case 5: {
                cout << "Applying Flip Image filter" <<endl;
                FlipImage(filename,extension);
                break;
            }
            case 6: {
                cout << "Applying Rotate Image filter" <<endl;
                RotatedImage(filename,extension);
                break;
            }
            case 7: {
                cout << "Applying Frame filter" <<endl;
                AddFrame(filename,extension);
                break;
            }
            case 8: {
                cout << "Applying Darken and Lighten Image filter" <<endl;
                Darker_lighterImage(filename,extension);
                break;
            }
            case 9: {
                int blurlevel;
                cout << "Enter blur level (must be an odd number): ";
                cin >> blurlevel;
                cout << "Applying Blur Image filter" <<endl;
                applyBlur(filename,blurlevel,extension);
                break;
            }
            case 10: {
                Image input(filename);
                Image inputImage(filename);
                cout << "Applying Images Egdes Detection Filter" <<endl;
                DetectImageEdges(input,filename,extension);
                break;
            }
            case 11: {
                cout << "Applying Crop Image filter" <<endl;
                CropImage(filename,extension);
                break;
            }
            case 12: {
                cout << "Applying Resize Image filter" <<endl;
                ResizeImage(filename,extension);
                break;
            }
            case 13: {
                cout << "Applying Infrared Image filter" << endl;
                InfraredFilter(filename,extension);
                break;
            }
            case 14:{
                cout << "Applying Purple Filter" << endl;
                PurpleFilter(filename,extension);
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }

        cout << "Do you want to apply another filter?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> cont;
    }
    return 0;
}