// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "../bmplib.cpp"
#include "../bmplib.h"
using namespace std;
unsigned char img[SIZE][SIZE][RGB];

void loadImage ();
void saveImage ();
void doSomethingForImage ();

int main()
{
    loadImage();
    doSomethingForImage();
    saveImage();
    return 0;
}

//_________________________________________//
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, img);
}

//_________________________________________//
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, img);
}

//_________________________________________
void doSomethingForImage() {
    unsigned char img1[SIZE][SIZE][RGB];

//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img1[i][j] = image[i][SIZE-1-j];
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            image[i][j] = img1[i][j];
//        }
//    }

// Vertically fliped
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img1[i][j] = img[SIZE-1-i][j];
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img[i][j] = img1[i][j];
//        }
//    }

// Mirror image
//    cout<<"Enter (l) for left side mirroring:\n"
//          "Enter (r) for right side mirroring:\n"
//          "Enter (u) for up side mirroring:\n"
//          "Enter (d) for down side mirroring:\n";
//    char c; cin>> c;
//    while (c != 'l' and c != 'r' and c != 'u' and c != 'd'){
//        cout<< "Enter a valid letter: ";
//        cin >> c;
//    }
//    // copying image in image1
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img1[i][j] = img[i][j];
//        }
//    }
//
//    if (c == 'l'){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE / 2; ++j) {
//                img1[i][SIZE-1-j] = img[i][j];
//            }
//        }
//    }else if (c == 'r'){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE / 2; ++j) {
//                img1[i][j] = img[i][SIZE-1-j];
//            }
//        }
//    }else if (c == 'u'){
//        for (int i = 0; i < SIZE / 2; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                img1[SIZE-1-i][j] = img[i][j];
//            }
//        }
//    }else if (c == 'd'){
//        for (int i = 0; i < SIZE / 2; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                img1[i][j] = img[SIZE-1-i][j];
//            }
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img[i][j] = img1[i][j];
//        }
//    }

// edges
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int  avrg = 0;
            for (int k = 0; k < RGB; ++k) {
                avrg += img[i][j][k];
            }
            avrg /= RGB;
            if (avrg > 127){
                for (int k = 0; k < RGB; ++k) {
                    img[i][j][k] = 255;
                }
            } else{
                for (int k = 0; k < RGB; ++k) {
                    img[i][j][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            for (int k = 0; k < RGB; ++k) {
                if (i != (SIZE-1) and j != (SIZE-1)) {
                    if (abs(img[i][j][k] - img[i][j + 1][k]) > 30 || abs(img[i][j][k] - img[i+1][j][k]) > 30  )
                        img[i][j][k] = 0;
                    else
                        img[i][j][k] = 255;
                }
            }
        }for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {
                    if (i != (SIZE-1) and j != (SIZE-1)) {
                        if (abs(img[i][j][k] - img[i][j + 1][k]) > 30 || abs(img[i][j][k] - img[i+1][j][k]) > 30  )
                            img[i][j][k] = 0;
                        else
                            img[i][j][k] = 255;
                    }
                }
            }
        }

//crop
//    int x,y,l,w;
//    cout<< "Enter the point you want to crop from: "; cin>> x>> y;
//    cout<< "Enter the Length and Width of the part you want to crop: "; cin>> l >> w;
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img1[i][j] = 255;
//        }
//    }
//    for (int i = x; i <= l+x; ++i) {
//        for (int j = y; j <= w+y; ++j) {
//            img1[i][j] = img[i][j];
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            img[i][j] = img1[i][j];
//        }
//    }

// flip RGB
// horizontal flip
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img1[i][j][k] = img[i][SIZE-1-j][k];
//            }
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img[i][j][k] = img1[i][j][k];
//            }
//        }
//    }

// vertical flip RGB
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img1[i][j][k] = img[SIZE-1-i][j][k];
//            }
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img[i][j][k] = img1[i][j][k];
//            }
//        }
//    }

//Mirror image RGB
//    cout<<"Enter (l) for left side mirroring:\n"
//          "Enter (r) for right side mirroring:\n"
//          "Enter (u) for up side mirroring:\n"
//          "Enter (d) for down side mirroring:\n";
//    char c; cin>> c;
//    while (c != 'l' and c != 'r' and c != 'u' and c != 'd'){
//        cout<< "Enter a valid letter: ";
//        cin >> c;
//    }
//    // copying image in image1
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//            img1[i][j][k] = img[i][j][k];
//            }
//        }
//    }
//
//    if (c == 'l'){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE / 2; ++j) {
//                for (int k = 0; k < RGB; ++k) {
//
//                img1[i][SIZE-1-j][k] = img[i][j][k];
//                }
//            }
//        }
//    }
//    else if (c == 'r') {
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE / 2; ++j) {
//                for (int k = 0; k < RGB; ++k) {
//                    img1[i][j][k] = img[i][SIZE - 1 - j][k];
//                }
//            }
//        }
//    }else if (c == 'u'){
//        for (int i = 0; i < SIZE / 2; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                for (int k = 0; k < RGB; ++k) {
//                    img1[SIZE - 1 - i][j][k] = img[i][j][k];
//                }
//            }
//        }
//    }else if (c == 'd'){
//        for (int i = 0; i < SIZE / 2; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                for (int k = 0; k < RGB; ++k) {
//                    img1[i][j][k] = img[SIZE - 1 - i][j][k];
//                }
//            }
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//            img[i][j][k] = img1[i][j][k];
//            }
//        }
//    }
// black and white RGB
// getting average of the three colors of each pixel
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            int  avrg = 0;
//            for (int k = 0; k < RGB; ++k) {
//                avrg += img[i][j][k];
//            }
//            avrg /= RGB;
//  change it to black and white
//            if (avrg > 127){
//                for (int k = 0; k < RGB; ++k) {
//                    img[i][j][k] = 255;
//                }
//            } else{
//                for (int k = 0; k < RGB; ++k) {
//                    img[i][j][k] = 0;
//                }
//            }
//        }
//    }

//crop RGB
// taking points from the user
//    int x,y,l,w;
//    cout<< "Enter the point you want to crop from: "; cin>> x>> y;
//    cout<< "Enter the Length and Width of the part you want to crop: "; cin>> l >> w;
// copying img in img1
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img1[i][j][k] = 255;
//            }
//        }
//    }
//    for (int i = x; i <= l+x; ++i) {
//        for (int j = y; j <= w+y; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img1[i][j][k] = img[i][j][k];
//            }
//        }
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            for (int k = 0; k < RGB; ++k) {
//                img[i][j][k] = img1[i][j][k];
//            }
//        }
//    }

}
