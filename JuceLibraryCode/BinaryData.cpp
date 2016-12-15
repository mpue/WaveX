/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== iconic_1-1-1_audio-spectrum_32_0_000000_none.png ==================
static const unsigned char temp_binary_data_0[] =
{ 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,1,3,0,0,0,73,180,232,183,0,0,0,6,80,76,84,69,0,0,0,0,0,0,165,103,185,207,0,0,0,1,116,82,78,83,0,64,230,216,102,0,0,0,31,73,68,65,84,8,91,99,96,96,176,97,96,64,39,108,176,18,54,232,132,13,
145,4,54,189,88,237,192,116,11,0,217,43,18,193,25,212,196,99,0,0,0,0,73,69,78,68,174,66,96,130,0,0 };

const char* iconic_111_audiospectrum_32_0_000000_none_png = (const char*) temp_binary_data_0;

//================== iconic_1-1-1_audio-spectrum_128_0_000000_none.png ==================
static const unsigned char temp_binary_data_1[] =
{ 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,128,0,0,0,128,1,3,0,0,0,249,240,243,136,0,0,0,6,80,76,84,69,0,0,0,0,0,0,165,103,185,207,0,0,0,1,116,82,78,83,0,64,230,216,102,0,0,0,47,73,68,65,84,72,75,237,200,177,13,0,48,12,2,65,246,95,26,87,65,22,
202,6,126,42,254,164,55,59,247,60,216,192,15,130,135,97,7,0,52,168,16,168,0,130,192,0,9,44,125,159,104,194,5,52,0,0,0,0,73,69,78,68,174,66,96,130,0,0 };

const char* iconic_111_audiospectrum_128_0_000000_none_png = (const char*) temp_binary_data_1;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xa3c58f04:  numBytes = 119; return iconic_111_audiospectrum_32_0_000000_none_png;
        case 0x6b554138:  numBytes = 135; return iconic_111_audiospectrum_128_0_000000_none_png;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "iconic_111_audiospectrum_32_0_000000_none_png",
    "iconic_111_audiospectrum_128_0_000000_none_png"
};

}
