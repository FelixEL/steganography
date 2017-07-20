#ifndef DECODER_H
#define DECODER_H
#include "../bitmap/bitmap_image.hpp"
#include <string>
#include <bitset>

using namespace std;
class decoder
{
    public:
        decoder();
        virtual ~decoder();

        string decode(bitmap_image&);
    protected:
    private:
};

#endif // DECODER_H
