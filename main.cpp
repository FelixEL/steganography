#include <iostream>
#include "bitmap/bitmap_image.hpp"
#include "encoder.h"
#include "decoder.h"
#include <string>

using namespace std;

int main()
{
    cout<<"             ST-Crypto"<<endl<<endl;
    cout<<"Software for pure steganography"<<endl;
    cout<<"             Author: E11"<<endl;
    cout<<"!! ONLY 24bit BMP allowed!!"<<endl;

while(1)
{
cout<<endl;
cout<<endl;
cout<<"command list: \n-->encode: enc\n-->decode: dec\n-->exit: exit"<<endl<<"Enter command:"<<endl;
string command;
cin>>command;
if(command == "enc")
{

    cout<<endl;
    cout<<"enter filename"<<endl;
    string filename_in;
    cin>>filename_in;

    bitmap_image image(filename_in + ".bmp");

    const unsigned int block_width  = image.width ();
    const unsigned int block_height = image.height();
    if(block_height==0 || block_height==0 )
    {
       cout<<endl<<"WRONG FILE!!!";
       continue;
    }
    encoder enc;
    cout<<endl;
    cout<<"maximum payload in ASCII characters: "<<enc.maxPayload(image);
    cout<<endl;
    cout<<"enter information payload (only ASCII characters allowed):"<<endl;;

    string input;
    cin.ignore();
    cin.clear();
    std::getline(std::cin, input);

    enc.encode(image,input);
    image.save_image(filename_in + "_encoded.bmp");
}
else  if(command == "dec")
{
    cout<<endl;
    cout<<"enter filename"<<endl;
    string filename_in;
    cin>>filename_in;
    bitmap_image image(filename_in + ".bmp");
    const unsigned int block_width  = image.width ();
    const unsigned int block_height = image.height();

    if(block_height==0 || block_height==0 )
    {
       cout<<endl<<"WRONG FILE!!!";
       continue;
    }
    decoder dec;
    string output;
    output = dec.decode(image);

    cout <<endl<< output<<endl;

}
else if(command == "exit")
{

    return 0;

}
else
{
    cout<<endl;
    cout<<"WRONG  COMMAND !!";
    continue;
}







/*

cout<<"enter filename";
string filename_in;
cin>>filename_in;

   bitmap_image image(filename_in + ".bmp");

   const unsigned int block_width  = image.width ();
   const unsigned int block_height = image.height();


encoder enc;
decoder dec;



cout<<endl;
cout<<endl;
cout<<endl;
cout<<"maximum payload in ASCII characters: "<<enc.maxPayload(image);
cout<<endl;
cout<<endl;
cout<<"enter information payload (only ASCII characters allowed):"<<endl;;


string input;
getline(std::cin, input);

enc.encode(image,input);

string output;
output = dec.decode(image);




cout << output;






image.save_image("new.bmp");
*/
}

    return 0;
}
