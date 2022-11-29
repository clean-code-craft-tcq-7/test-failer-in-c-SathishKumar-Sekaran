#include <stdio.h>
#include <assert.h>

int test_CompinationNumber[5][5];
const char* test_MajorColor[5][5];
const char* test_MinorColor[5][5];

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            test_CompinationNumber[i][j] =  i * 5 + j;
            test_MajorColor[i][j] =  majorColor[i];
            test_MinorColor[i][j] =  minorColor[i];
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            
        }
    }
    return i * j;
}

void testColorMap(int MajorColorIdx,int MinorColorIdx, int expected_CompinationNumber,
                        char* expectedMajorColor,char* expectedMinorColor)
{
    assert(test_CompinationNumber[MajorColorIdx][MinorColorIdx] == expected_CompinationNumber);
    assert(test_MajorColor[MajorColorIdx][MinorColorIdx] == expectedMajorColor);
    assert(test_MinorColor[MajorColorIdx][MinorColorIdx] == expectedMinorColor);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testColorMap(0,0,0,"White","Blue");
    testColorMap(0,4,4,"White","Slate");
    testColorMap(2,3,12,"Black","Brown");
    testColorMap(4,0,20,"Violet","Blue");
    printf("All is well (maybe!)\n");
    return 0;
}
