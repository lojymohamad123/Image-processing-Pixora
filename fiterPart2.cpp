
//filter8

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
            cropped.saveImage(filename + "." + extension);
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



//filter11



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
            resized.saveImage(filename + "." + extension);
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