/*
 * Nihar Babaria
 * njb160030@utdallas.edu
 * CS 3377
 */

#include <iostream>
#include "cdk.h"

#include "cdkheader.h"



#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix


  const char 		*rowTitles[] = {" ", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[] = {" ", "a", "b", "c", "d", "e"};
  int		boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};

  /*
   * Initialize the Cdk screen.
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  string fileName = "cs3377.bin"; 
  ifstream binInfile(fileName, ios::in|ios::binary); 
  BinaryFileHeader *myHeader = new BinaryFileHeader();
  BinaryFileRecord *myRecord = new BinaryFileRecord();

  binInfile.read((char *) myHeader, sizeof(BinaryFileHeader)); 
  
  snprintf(MagicNumBuff, 32, "Magic: 0x%X", myHeader->Magic); 
  snprintf(VersionBuff, 32, "Version: %u", myHeader->vNumber); 
  snprintf(RecordBuff, 64, "NumRecords: %lu", myHeader->Records);

  for(unsigned int i = 0; i < myHeader->Records && j <= 5; i++)
  { 
    binInfile.read((char *) Record, sizeof(BinaryFileRecord)); 
    snprintf(bufferStringLen, 32, "strlen: %u", myRecord->strLength); 
    setCDKMatrixCell(myMatrix, j, 1, bufferStringLen); 
    setCDKMatrixCell(myMatrix, j, 2, myRecord->stringBuffer); 
    j++;
  }

  /*
   * Dipslay a message
   */
  setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
  drawCDKMatrix(myMatrix, true);    /* required  */

  /* see results, pause until a key is pressed. */
  unsigned char x;
  cin >> x;

  // Cleanup screen
  endCDK();
}
