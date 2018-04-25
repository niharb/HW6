/*
 * Nihar Babaria
 * CS 3377
 * njb160030@utdallas.edu
 */
#ifndef _CDKHEADER_H_
#define _CDKHEADER_H_

#include <stdint.h>


class BinaryFileHeader
{

public:
	uint32_t magicNumber; /* Should be 0xFEEDFACE */
	uint32_t versionNumber;
	uint64_t numRecords;

};



/*
* Records in the file have a fixed length buffer
* that will hold a C-Style string. This is the
* size of the fixed length buffer.
*/


const int maxRecordStringLength = 25;
class BinaryFileRecord
{

public:
	uint8_t strLength;
	char stringBuffer[maxRecordStringLength];

};

#endif /* _CDKHEADER_H_ */
