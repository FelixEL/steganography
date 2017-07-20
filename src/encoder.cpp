#include "encoder.h"

encoder::encoder()
{
    //ctor
}

void encoder::encode(bitmap_image& image_in,string text)
{
    unsigned int block_width  = image_in.width ();
    unsigned int block_height = image_in.height();


text.push_back('\16');

//cout<<endl<<text;
    unsigned int total_bits;
    total_bits = (text.length() + 1)*8; //tu mozna zrobic optymalizacje na 7 bit (ASCII) ale mi sie nie chce...

//total_bits = block_width * 3;

    bool brk = false;
    unsigned int bit_counter = 0;

   for(unsigned int i=0;i<block_height;i++)
   {

       for(unsigned int j=0;j<block_width;j++)
        {
            unsigned char a=0,b=0,c=0;
            image_in.get_pixel(j,i,a,b,c);
            c = (a&0b11111110) | ((text.c_str()[bit_counter/8]>>(bit_counter%8))&0b00000001);
            bit_counter++;
            b = (b&0b11111110) | ((text.c_str()[bit_counter/8]>>(bit_counter%8))&0b00000001);
            bit_counter++;
            a = (c&0b11111110) | ((text.c_str()[bit_counter/8]>>(bit_counter%8))&0b00000001);
            bit_counter++;
            image_in.set_pixel(j,i,a,b,c);
            if(bit_counter>=total_bits)
            {
                brk=true;
                break;
            }
        }
        if(brk) break;

   }


}


unsigned int encoder::maxPayload(bitmap_image& image_in)
{
    unsigned int block_width  = image_in.width ();
    unsigned int block_height = image_in.height();

    return (block_width*block_height*3)/8;
}


encoder::~encoder()
{
    //dtor
}
