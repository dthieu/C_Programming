#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int isMatch(char target[], char num[]);
int isValidNumber(char num[]);
void createRandomNumber(char num[]);

/* Check matching
 * Input
 * + target : the number was generated
 * + num    : the guess number
 * Output
 * + 1 : True
 * + 0 : False
 */
int isMatch(char target[], char num[])
{
    unsigned int hit = 0, blow = 0;
    for (int i = 0; i < 4; ++i) {
        if (target[i] == num[i])
            hit++;
        else
            blow++;
    }
    printf("hit %d, blow %d\n", hit, blow);
    if (hit == blow)
        return 1;
    return 0;
}
/* Check whether input number valid or not
 * Input
 * + num    : the input number
 * Output
 * + 1 : True
 * + 0 : False
 */
int isValidNumber(char num[])
{
    // Check length of input number
    /*char* pNum = &num[0];
    int count = 0;
    while (*pNum++)
        count++;
    if (count < 1 || count > 4) {
        printf("Error! Your number not enough 4 digits!\n");
        return 0;
    }*/

    // Check whether is digit or not
    for (int i = 0; i < 4; ++i) {
        if (num[i] < 48 || num[i] > 57) { // is not digit
            printf("Error! Your number contains characters which not a digit!\n");
            return 0;
        }
    }
    // Check same digits in a number
    if (num[0] == num[1] || num[0] == num[2] || num[0] == num[3]
        || num[1] == num[2] || num[1] == num[3]
        || num[2] == num[3]){
        printf("Error! Your number have some same digits!\n");
        return 0;
    }
    return 1;
}

/* Generating a number including 4 digits
 * Input
 * Output
 * + num : Number (4 digits)
 */
void createRandomNumber(char num[])
{
    time_t t;
    srand((unsigned) time(&t));
    // loop when number having same digits
    while (num[0] == num[1] || num[0] == num[2] || num[0] == num[3]
            || num[1] == num[2] || num[1] == num[3]
            || num[2] == num[3]) {
        for (int i = 0; i < 4; i++)
            num[i] = (char)((rand() % (57 - 48)) + 48); // random 48 -> 57
    }
}
/* Get a number from player
 * Input
 * Output
 * + num : Number (4 digits)
 */
void getNumberFromPlayer(char num[])
{
    while (1) {
        printf("Type your number: ");
        scanf("%4s", num);
        if (isValidNumber(num))
            break;
        printf("\n");
    }
}

int main()
{
    char target[4];
    char guess[4];
    unsigned int countGuess = 0;
    createRandomNumber(target);

    printf("\t\tGUESS NUMBER\n\n");
    printf("Need guess: %s\n\n", target);

    while (1)
    {
        getNumberFromPlayer(guess);
        if (isMatch(target, guess))
        {
            printf("Good!\n");
            printf("Number of guessing: %d\n", countGuess);
            break;
        }
        else
            countGuess++;
    }

    return 0;
}
