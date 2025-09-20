#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(int argc, char *argv[]) {
    time_t sec;
    time(&sec);
    int x;
    char z[16];
    sprintf(z, "%p", &x);
    long numberCollection = 0;
    for (int i = 1; i < 16; i++) {
        numberCollection += z[i];
    }

    numberCollection *= sec;

    int len = (numberCollection == 0) ? 1 : (int) log10(labs(numberCollection)) + 1;

    int randomNumber = 0;

    for (len = 1; len < 16; len++) {
        randomNumber += numberCollection % 10;
        numberCollection /= 10;
    }

    int sum = 0;
    int temp = randomNumber;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;


        if (sum < 10) {
            if (sum == 0) {
                randomNumber = 1;
            } else {
                randomNumber = sum;
            }
            break;
        } else {
            randomNumber = sum;
        }
    }

    printf(randomNumber ? "%d\n" : "%d\n", randomNumber);
}
