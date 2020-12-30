/* AUTHOR: Daudi Ricardo Wampamba Bandres */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winuser.h>

/*
Takes two arguments as such
generator [FSTRING] [optional: START] [END] [optional: STEP]

Build Command:
gcc -lUser32 -Wall -ansi -pedantic-errors -o generator.exe generator.c
*/
int main(int argc, char *argv[])
{
    char * FSTRING, * OUTSTRING = calloc(4096, sizeof(char));
    int START = 0, END, STEP = 1, i, j, k;

    HGLOBAL hMem;

    if(argc != 3)
    {
        if(argc != 4) {
            if(argc != 5) {
                fputs("USAGE: generator [FSTRING] [optional: START] [END] [optional: STEP]", stderr);
                return 1;
            }
            if(!(sscanf(argv[4], "%d", &STEP))) {
                fputs("Invalid Step\n", stderr);
                return 1;
            }
        }
        if(!(sscanf(argv[2], "%d", &START))) {
            fputs("Invalid Start\n", stderr);
            return 1;
        }
        if(!(sscanf(argv[3], "%d", &END))) {
            fputs("Invalid End\n", stderr);
            return 1;
        }
    }
    else if(!(sscanf(argv[2], "%d", &END))) {
        fputs("Invalid End", stderr);
        return 1;
    };
    FSTRING = argv[1];
    
    for(i = START, k = 0; i < END; i += STEP, k += j){
        for(j = 0; *(FSTRING + j); j++) {
            if(*(FSTRING + j) == '\\') {
                ++j;
                --k;
                *(OUTSTRING + k + j) = *(FSTRING + j);
            }
            else if(*(FSTRING + j) == '?') {
                k += sprintf((OUTSTRING + k + j), "%d", i) - 1;
            }
            else *(OUTSTRING + k + j) = *(FSTRING + j);
        }
        *(OUTSTRING + k + (j++)) = '\n';
    }
    *(OUTSTRING + (++k)) = '\0';

    OUTSTRING[4095] = '\0'; /* FOR SAFETY */

    if(!(hMem = GlobalAlloc(GMEM_MOVEABLE, k))) return 2;
    memcpy(GlobalLock(hMem), OUTSTRING, k);
    GlobalUnlock(hMem);
    if(!OpenClipboard(0)) return 3;
    if(!EmptyClipboard()) return 4;
    if(!SetClipboardData(CF_TEXT, hMem)) return 5;
    CloseClipboard();

    printf(OUTSTRING);
    free(OUTSTRING);

    return 0;
}
