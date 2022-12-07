#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned.h"


const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

colorPair colorPairedNames[MAX_COLOR_PAIR];


void printPairedColor(char* colorPairBuff, int Idx)
{
    memset(colorPairBuff, 0, TABLE_ROW_SIZE);
    sprintf(colorPairBuff, "%-2d | %-6s | %s",colorPairedNames[Idx].colorSequenceNumber,colorPairedNames[Idx].majorColor, colorPairedNames[Idx].minorColor);
}


int printColorMap() {
	int colorCount = 0;
	char colorPairBuffdata[TABLE_ROW_SIZE];
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
			colorCount = i * 5 + j;
            colorPairedNames[colorCount].colorSequenceNumber =  colorCount+1;
            colorPairedNames[colorCount].majorColor =  majorColor[i];
            colorPairedNames[colorCount].minorColor =  minorColor[j];
            printPairedColor(colorPairBuffdata,colorCount);
			printf("%s\n",colorPairBuffdata);
        }
    }
    return i * j;
}

void testColorMap(int Idx, int expected_SeqNumber,
                    const char* expectedMajorColor,const char* expectedMinorColor)
{
    assert(colorPairedNames[Idx].colorSequenceNumber == expected_SeqNumber);
	assert(strcmp(colorPairedNames[Idx].majorColor, expectedMajorColor) == 0);
	assert(strcmp(colorPairedNames[Idx].minorColor, expectedMinorColor) == 0);
}

int main() {
	int i=0,j=0,countIdx=0;
    int result = printColorMap();
    assert(result == 25);
	for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
			countIdx = i * 5 + j;
			testColorMap(countIdx,(countIdx+1),majorColor[i],minorColor[j]);
		}
	}
    printf("All is well (maybe!)\n");
    return 0;
}
