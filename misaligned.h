
#define MAX_COLOR_PAIR 25
#define TABLE_ROW_SIZE 50

typedef struct{
    int colorSequenceNumber;
    const char *majorColor;
    const char *minorColor;
}colorPair;

void printPairedColor(char* colorPairBuff, int Idx);
int printColorMap();
void testColorMap(int Idx, int expected_SeqNumber,
                    const char* expectedMajorColor,const char* expectedMinorColor);