#include "decoder.h"

decoder::decoder()
{
    //ctor
}
string decoder::decode(bitmap_image& image_in)
{
    unsigned int block_width  = image_in.width ();
    unsigned int block_height = image_in.height();

    unsigned int total_bits;
//    total_bits = text.length()*8; //tu mozna zrobic optymalizacje na 7 bit (ASCII) ale mi sie nie chce...

total_bits = 4000000 * 8;

 char *tab;
tab = new  char[4000000];

for(int i=0;i<20;i++)
{
    tab[i] = 0;

}

    bool brk = false;
    unsigned int bit_counter = 0;


   for(unsigned int i=0;i<block_height;i++)
   {

       for(unsigned int j=0;j<block_width;j++)
        {
            unsigned char a=0,b=0,c=0;
            image_in.get_pixel(j,i,a,b,c);
            c = (c&0b00000001);
            tab[bit_counter/8] = tab[bit_counter/8] | (c<<(bit_counter%8));
            if(bit_counter>=total_bits || tab[bit_counter/8]=='\16')
            {
                brk=true;
                break;
            }
            bit_counter++;

            b = (b&0b00000001);
            tab[bit_counter/8] = tab[bit_counter/8] | (b<<(bit_counter%8));
            if(bit_counter>=total_bits || tab[bit_counter/8 ]=='\16')
            {
                brk=true;
                break;
            }
            bit_counter++;

            a = (a&0b00000001);
            tab[bit_counter/8] = tab[bit_counter/8] | (a<<(bit_counter%8));

            if(bit_counter>=total_bits || tab[bit_counter/8]=='\16')
            {
                brk=true;
                break;
            }
            bit_counter++;

        }
        if(brk) break;

   }

  /* for(int i=0;i<bit_counter/8;i++)
   {
       cout<<tab[i];

   }*/
tab[bit_counter/8] = '\0';

string out(tab);


delete [] tab;

return out;
}
decoder::~decoder()
{
    //dtor
}
