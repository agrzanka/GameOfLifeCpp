#include"RLE.h"
#include"GOL.h"

//decoder needs to change strings like 3t3f|1t5f to: true,true, true, false, false, false|true, false, false, false, false, false
//which gives us coordinates for pattern: {0,0},{1,0},{2,0},{0,1} and those are the "alive" cells to init a board. 

//encoder - analogical situation but reverse xD