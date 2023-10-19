/*بسم الله الرحمن الرحيم
    اللهم أشرح لي صدري
       ويسر لي أمري
 واحلل عقدة من لساني
*/

// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                CS213-2023-20221072-20220195-20220326-A1-FULL.cpp
// Last Modification Date:    9/10/2023
// Author1 and ID and Group:    Abdelrahman Mohamed Ahmed    20220195     boodymohammed26@gmail.com
// Author2 and ID and Group:    Salman Ahmed Hamed           20221072     solom.9850@gmail.com
// Author3 and ID and Group:    Marwan Mohamed Abdellatif    20220326     marwanmohamed200415@gmail.com


//include file and libraries
#include <bits/stdc++.h>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;

//defines
#define ll long long
#define e '\n'
#define sp ' '
#define END return 0;

//variable initialization
const int N = 1e5 + 5;
unsigned char img[SIZE][SIZE];

//directional array
int dx[] = {0,1,0,-1,0,1,1,-1,-1};
int dy[] = {0,0,1,0,-1,1,-1,1,-1};

//functions declaration
void menu();
void load_image();
void filters();
void black_white();
void invert();
void merge();
void flip();
void rotate();
void dark_light();
void detect_edges();
void enlarge();
void shrink();
void mirror();
void shuffle();
void skew_right();
void blur();
void crop();
void skew_up();
void save();
bool valid(char c);
void save_choice();

int main(){
    menu();
    load_image();
    filters();
    END
}

//function initialization
void menu(){
    //program interface
    cout<<"_______________________________________________________"<<e;
    cout<<"| Welcome to our photo editor program for (GS images) |"<<e;
    cout<<"_______________________________________________________"<<e;
}

//______________________________________________________________________________//

void load_image(){
    char text[1000];
    //input image
    cout<<"Enter image name you want to edit: ";
    cin>>text;
    strcat(text,".bmp");
    readGSBMP(text,img);
}

//______________________________________________________________________________//

void filters(){
    //choose filter
    char c;
    do {
        cout << "1- Black & White Filter\n"
                "2- Invert Filter\n"
                "3- Merge Filter \n"
                "4- Flip Image\n"
                "5- Darken and Lighten Image \n"
                "6- Rotate Image\n"
                "7- Detect Image Edges \n"
                "8- Enlarge Image\n"
                "9- Shrink Image\n"
                "a- Mirror 1/2 Image\n"
                "b- Shuffle Image\n"
                "c- Blur Image\n"
                "d- Crop Image\n"
                "e- Skew Image Right\n"
                "f- Skew Image Up\n"
                "s- Save the image to a file\n"
                "0- Exit" << e << e;
        cout << "Choose filter to Apply OR s to Save OR 0 to Exit: ";
        cin >> c;
        while (!valid(c)) {
            cout << "Please Enter a valid letter: ";
            cin >> c;
        }
        if (c == '1')
            black_white();
        else if (c == '2')
            invert();
        else if (c == '3')
            merge();
        else if (c == '4')
            flip();
        else if (c == '5')
            dark_light();
        else if (c == '6')
            rotate();
        else if (c == '7')
            detect_edges();
        else if (c == '8')
            enlarge();
        else if (c == '9')
            shrink();
        else if (c == 'a')
            mirror();
        else if (c == 'b')
            shuffle();
        else if (c == 'c')
            blur();
        else if (c == 'd')
            crop();
        else if (c == 'e')
            skew_right();
        else if (c == 'f')
            skew_up();
        else if (c == 's')
            save();
        else
            break;
    }while(c != '0');
}

//______________________________________________________________________________//

void black_white(){
    float sum = 0, cnt = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            sum += img[i][j];
            cnt++;

        }
    }
    float avr = sum / cnt;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (img[i][j] > avr)
                img[i][j] = 255.0;
            else
                img[i][j] = 0.0;
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void invert(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img[i][j] = (255 - img[i][j]);
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void merge(){
    unsigned char img1[SIZE][SIZE];
    char text2[1000];
    cout<<"Enter image name you want to merge:"<<e;
    cin>>text2;
    strcat(text2,".bmp");
    readGSBMP(text2,img1);
    for(int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
            img[i][j] = (img[i][j] + img1[i][j]) / 2;
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void flip(){
    unsigned char img1[SIZE][SIZE];
    cout<< "To Flip the image Horizontally Enter (h)\n"
           "To Flip the image Vertically Enter (v): ";
    char c1; cin>>c1;
    while (c1 != 'h' and c1 != 'v'){
        cout<< "Please Enter a Valid Letter:"
               "Horizontally (h)\n"
               "Vertically (v): ";
        cin>> c1;
    }
    if (c1 == 'h') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img1[i][j] = img[i][SIZE-1-j];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] = img1[i][j];
            }
        }
    }
    else if (c1 == 'v') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img1[i][j] = img[SIZE - 1 - i][j];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] = img1[i][j];
            }
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void rotate(){
    unsigned char img1[SIZE][SIZE];
    cout<<"To Rotate 90 Degrees Enter (90) : \n"
          "To Rotate 180 Degrees Enter (180) : \n"
          "To Rotate 270 Degrees Enter (270) : \n";
    int n;cin>>n;
    while(n != 90 and (n != 180 and n != 270)){
        cout<<"Please Enter a Valid Number";
        cin>>n;
    }
    if(n==90){
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0 ; j < SIZE ; j++){
                img1[j][SIZE-1-i]=img[i][j];
            }
        }
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0 ; j < SIZE ; j++){
                img[i][j]=img1[i][j];
            }
        }
    }else if(n==180){
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0 ; j < SIZE ; j++){
                img1[SIZE-1-i][SIZE-1-j]=img[i][j];
            }
        }
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0 ; j < SIZE ; j++){
                img[i][j]=img1[i][j];
            }
        }
    }else if (n==270){
        for(int i = 0;i < SIZE ; i++){
            for (int j = SIZE-1; j >= 0 ; j--){
                img1[SIZE-1-j][i]=img[i][j];
            }
        }
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0 ; j < SIZE ; j++){
                img[i][j]=img1[i][j];
            }
        }
    }
    save_choice();

}

//______________________________________________________________________________//

void dark_light(){
    char c;
    cout<<"To Darken Enter (d)\n"
          "To Lighten Enter (l): ";
    cin>>c;
    while(c != 'd' && c != 'l'){
        cout<<"Please Enter a Valid Letter\n"
              "Darken (d) , Lighten (l): ";
        cin>>c;
    }
    if(c == 'd'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] /= 2;
            }
        }
    }
    else{
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] += (255 - img[i][j])/2;
            }
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void detect_edges(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i != (SIZE-1) and j != (SIZE-1)) {
                if (abs(img[i][j] - img[i][j + 1]) > 30 || abs(img[i][j] - img[i+1][j]) > 30  )
                    img[i][j] = 0;
                else
                    img[i][j] = 255;
            }
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void enlarge(){
    char img1[SIZE][SIZE];
    cout<<"Enter the quadrant you want to Enlarge (1,2,3,4): ";
    int n;cin>>n;
    while(n > 4 || n < 1){
        cout<<"Please Enter a Valid number (1,2,3,4): ";
        cin>>n;
    }
    switch (n) {
        case 1:{
            for (int i = 0; i < SIZE/2 ; ++i) {
                for (int j = 0 ; j < SIZE/2; ++j ) {
                    img1[2*i][2*j] = img[i][j];
                    img1[2*i][2*j+1] = img[i][j];
                    img1[2*i+1][2*j] = img[i][j];
                    img1[2*i+1][2*j+1] = img[i][j];

                }
            }
            break;
        }
        case 2:{
            for (int i = 0; i < SIZE/2 ; ++i) {
                for (int j = SIZE/2,g = 0 ; j < SIZE; ++j ,++g) {
                    img1[2*i][2*g] = img[i][j];
                    img1[2*i][2*g+1] = img[i][j];
                    img1[2*i+1][2*g] = img[i][j];
                    img1[2*i+1][2*g+1] = img[i][j];

                }
            }
            break;
        }
        case 3:{
            for (int i = SIZE/2 ,g = 0; i < SIZE ; ++i ,++g) {
                for (int j = 0 ; j < SIZE/2; ++j ) {
                    img1[2*g][2*j] = img[i][j];
                    img1[2*g][2*j+1] = img[i][j];
                    img1[2*g+1][2*j] = img[i][j];
                    img1[2*g+1][2*j+1] = img[i][j];

                }
            }
            break;
        }
        case 4:{
            for (int i = SIZE/2 ,g = 0; i < SIZE ; ++i ,++g) {
                for (int j = SIZE/2 , k = 0 ; j < SIZE; ++j , k++ ) {
                    img1[2*g][2*k] = img[i][j];
                    img1[2*g][2*k+1] = img[i][j];
                    img1[2*g+1][2*k] = img[i][j];
                    img1[2*g+1][2*k+1] = img[i][j];

                }
            }
            break;
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img[i][j] = img1[i][j];
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void shrink(){
    unsigned char img1[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            img1[i][j] = 255;
        }
    }
    cout << "Enter The Shrink Size Between 1/2 or 1/3 or 1/4 : \n";
    string n;
    cin >> n;
    while (n != "1/2" and (n != "1/3" and n != "1/4")) {
        cout << "Please Enter Valid Size : \n";
        cin >> n;
    }
    if (n == "1/2") {
        for (int i = 2; i < SIZE; i++) {
            for (int j = 2; j < SIZE; j++) {
                unsigned int sum = 0;
                for (int k = i - 2; k < i; k++) {
                    for (int l = j - 2; l < j; l++) {
                        sum += img[k][l];
                    }
                }
                img1[i / 2][j / 2] = sum / 4;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] = img1[i][j];
            }
        }
    } else if (n == "1/3") {
        for (int i = 3; i < SIZE; i++) {
            for (int j = 3; j < SIZE; j++) {
                unsigned int sum = 0;
                for (int k = i - 3; k < i; k++) {
                    for (int l = j - 3; l < j; l++) {
                        sum += img[k][l];
                    }
                }
                img1[i / 3][j / 3] = sum / 9;
            }
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] = img1[i][j];
            }
        }
    } else if (n == "1/4") {
        for (int i = 4; i < SIZE; i++) {
            for (int j = 4; j < SIZE; j++) {
                unsigned int sum = 0;
                for (int k = i - 4; k < i; k++) {
                    for (int l = j - 4; l < j; l++) {
                        sum += img[k][l];
                    }
                }
                img1[i / 4][j / 4] = sum / 16;
            }
        }

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img[i][j] = img1[i][j];
            }
        }
    }
}
//______________________________________________________________________________//

void shuffle(){
    int a[4];
    cout << "Enter the order you want to shuffle: ";
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    unsigned char img1[SIZE][SIZE];
    for (int k = 0; k < 4; ++k) {
        int i, j, i1, j1;
        if (k == 0)
            i1 = 0, j1 = 0;

        else if (k == 1)
            i1 = 0, j1 = SIZE / 2;

        else if (k == 2)
            i1 = SIZE / 2, j1 = 0;

        else if (k == 3)
            i1 = SIZE / 2, j1 = SIZE / 2;
        //______________________________________//
        if (a[k] == 1)
            i = 0, j = 0;

        else if (a[k] == 2)
            i = 0, j = SIZE / 2;

        else if (a[k] == 3)
            i = SIZE / 2, j = 0;

        else if (a[k] == 4)
            i = SIZE / 2, j = SIZE / 2;
        //______________________________________//
        for (int l = 0; l < SIZE / 2; ++l) {
            for (int m = 0; m < SIZE / 2; ++m) {
                img1[i1 + l][j1 + m] = img[i + l][j + m];
            }
        }
    }
    for (int x = 0; x < SIZE; ++x) {
        for (int z = 0; z < SIZE; ++z) {
            img[x][z] = img1[x][z];
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void mirror(){
    cout<<"Enter (l) for left side mirroring:"
          "Enter (r) for right side mirroring:"
          "Enter (u) for up side mirroring:"
          "Enter (d) for down side mirroring:";
    char c; cin>> c;
    while (c != 'l' and c != 'r' and c != 'u' and c != 'd'){
        cout<< "Enter a valid letter: ";
        cin >> c;
    }
    unsigned char img1[SIZE][SIZE];
    // copying image in image1
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img1[i][j] = img[i][j];
        }
    }

    if (c == 'l'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                img1[i][SIZE-1-j] = img[i][j];
            }
        }
    }else if (c == 'r'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                img1[i][j] = img[i][SIZE-1-j];
            }
        }
    }else if (c == 'u'){
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img1[SIZE-1-i][j] = img[i][j];
            }
        }
    }else if (c == 'd'){
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                img1[i][j] = img[SIZE-1-i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img[i][j] = img1[i][j];
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void skew_right(){
    double seta , y;
    cout<<"Enter degree you want to skew with: ";
    cin>>seta;
    y = SIZE * tan((seta*22)/(7*180));
    int x = SIZE - y;
    unsigned char img1[SIZE][SIZE];

    //shrink the image
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < x; ++j) {
            img1[i][j] = img[i][j*255/(x-1)];
        }
    }

    //make the wallpaper white
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img[i][j] = 255;
        }
    }
    //shifting the image
    double step = y/256;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < x; ++j) {
            img[i][j+(int)y] = img1[i][j];
        }
        y -= step;
    }
    save_choice();
}

//______________________________________________________________________________//

void skew_up(){
    unsigned char img1[SIZE][SIZE];
    unsigned char img2[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img1[i][j] = 255;
            img2[i][j] = 255;
        }
    }
    double ang;
    cout<<"Enter degree you want to skew with: ";
    cin >> ang;
    ang = (ang * 22) / (180 * 7);
    int x = (int)(SIZE / ( 1 + tan(ang)));
    double index = SIZE - x;
    double mv = index/ SIZE;
    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j < SIZE ; ++j) {
            img1[(i*x)/SIZE][j] = img[i][j];
        }
    }

    for (int i = 0; i <SIZE ; ++i) {
        for (int j = (int)index; j < index+x ; ++j) {
            img2[j][i] = img1[(int)(j-index)][i];
        }
        index -= mv;
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img[i][j] = img2[i][j];
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void blur(){
    unsigned char img1[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int total = 0 , count = 0;
            for (int k = 0; k < 9; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(ny >= 0 && ny < SIZE && nx >= 0 && nx < SIZE){
                    total += img[nx][ny];
                    count++;
                }
            }
            img1[i][j] = total / count;
        }
    }
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            img[i][j]=img1[i][j];
        }
    }
    save_choice();
}

//______________________________________________________________________________//

void crop(){
    unsigned char img1[SIZE][SIZE];
    int x,y,l,w;
    cout<< "Enter the point you want to crop from: "; cin>> x>> y;
    cout<< endl;
    cout<< "Enter the Length and Width of the part you want to crop: "; cin>> l >> w;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img1[i][j] = 255;
        }
    }
    for (int i = x; i <= l+x; ++i) {
        for (int j = y; j <= w+y; ++j) {
            img1[i][j] = img[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            img[i][j] = img1[i][j];
        }
    }
}

//______________________________________________________________________________//

void save(){
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter image file name to save: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load_image image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName,  img);
}

//______________________________________________________________________________//

bool valid(char c){
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || c == 's');
}

//______________________________________________________________________________//

void save_choice(){
    cout<<"Do you Want to Save? (y/n): ";
    char c; cin>>c;
    while(c != 'y' and c != 'n'){
        cout<<"Please Enter a Valid letter (y/n): ";
        cin>>c;
    }
    if(c == 'y'){
        save();
    }
}

