void BlackandWhiteImage(const string &filename, const string &extension) {
    Image image(filename );

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned char r = image(i,j,0);
            unsigned char g = image(i,j,1);
            unsigned char b = image(i,j,2);
            unsigned char gray =
                static_cast<unsigned char>(0.299*r + 0.587*g + 0.114*b);
            image(i,j,0) = image(i,j,1) = image(i,j,2) = gray;
        }
    }
    cout << "Black and White filter applied.\n";

    cout << "Do you want to save the image with its current name or rename it?\n";
    cout << "1. current name\n2. rename it\n";

    int savedecision;
    cin >> savedecision;

    switch(savedecision) {
        case 1: {
            image.saveImage(filename + "." + extension);
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
            image.saveImage(filename + "." + extension);
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