#include <iostream> 

class BitVector {

    private:
        const uint32_t WordSize = 32;
        uint32_t *bitsarr;
    public: 
        BitVector(){};
        BitVector(uint32_t sumBit)
        {   
            uint32_t byte = sumBit%WordSize == 0 ? sumBit/WordSize : sumBit/WordSize + 1;
            bitsarr = new uint32_t[byte]{0};
        }
        ~BitVector() 
        {
            delete[]bitsarr;
            bitsarr = nullptr;
        }
        void BitVector::Set (uint32_t indexBit)
        {
            if(bitsarr != NULL)
            {
                uint32_t tmp = 1;
                bitsarr[indexBit/WordSize] |= tmp  << indexBit - WordSize;
            }
            else
                std::cout << "Bad pointer." << std::endl;
        }
        void BitVector::ReSet (uint32_t indexBit)
        {
            uint32_t tmp = 1;
            bitsarr[indexBit/WordSize] &= ~(tmp << indexBit - WordSize);
        }   
        bool CheckBit(uint32_t indexBit)
        {
            uint32_t tmp = 1;
            return bitsarr[indexBit/WordSize] & (tmp << indexBit - WordSize);
        }
};

int main()
{
    BitVector bit{100};
    bit.Set(39);
    std::cout << bit.CheckBit(39) << std::endl;
    bit.ReSet(39);
    std::cout << bit.CheckBit(39) << std::endl;


}










