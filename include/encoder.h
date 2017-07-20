#ifndef ENCODER_H
#define ENCODER_H
#include "../bitmap/bitmap_image.hpp"
#include <string>
#include <bitset>

using namespace std;
class encoder
{
    public:
        encoder();
        virtual ~encoder();

        void encode(bitmap_image&,string);
        unsigned int maxPayload(bitmap_image&);

    protected:
    private:
};

#endif // ENCODER_H
