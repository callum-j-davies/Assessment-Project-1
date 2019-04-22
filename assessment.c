/*This code is an ecryption and decryption software that will work for a
rotation or substitution cipher*/
/*STEP 1:
Type a meesage to the notepad file on desktop
it doesnt matter whether it needs to be 
encrypted or decrypted
However this message must be in 'ALL CAPS'*/
/*STEP 2:
The compiler will read either a 0 or 1 from the user to choose 
Rotation of Substitution cipher*/
/*STEP 3:
the compiler will read either a 0 or 1 from the user to choose
encryption or decryption
This will run the respective code and print
the encyption/decryption to the screen*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*Not all of these libraries are used but i have included them incase
i wanted to make adjustments to my code*/


int main()
{
    int firstchoice; // decides what code is run
    printf("-------CIPHER-------\n");
    printf("Rotation - Encryption (1)\n");
    printf("Rotation - Decryption [Key Known] (2)\n");
    printf("Rotation - Decryption [Key Unknown] (3)\n");
    printf("Substitution - Encryption (4)\n");
    printf("Substitution - Decryption (5)\n");
    printf("Your Choice: ");
    //This will decide what code is run
    scanf("%d", &firstchoice);
    
    /*         ROTATION CIPHER             */
        if (firstchoice == 1) //runs encryption
        {
            int k;
            printf("Enter encryption key [0 to 26]: ");
            //This will determine how much the message is rotated
            scanf("%d", &k);
            FILE *input;
            FILE *output;
            input = fopen("input.txt", "r");
            output = fopen("output.txt", "w");
            //Will read from the file data.txt
            if(input == NULL) 
            {
                perror("fopen()");
                return 0;
                //This is a safety net incase its reads from the file incorrectly
            }
            while (feof(input) == 0)
            {
                char c;
                fscanf(input, "%c", &c);
                if (c >= 'A' && c <= 'Z')
                {
                    c = c+k;
                }
                if ( (c+k) > 'Z')
                {
                    c = c - 26;
                }
                if (c < 'A' && c > 'Z')
                {
                    c = c;
                }
                printf("%c", c);
                fprintf(output, "%c", c);
            }
            printf("\n");
        }
        if (firstchoice == 2)//runs decryption
        {
            int k;
            printf("\n\nWhat is the decryption key [0-26]: ");
            scanf("%d", &k);
            if (k < 0 || k > 26)
            {
                printf("Unkown Input\n");
            }
            FILE *input;
            input = fopen("input.txt", "r");
            //Will read from the file data.txt
            if(input == NULL) 
            {
                perror("fopen()");
                return 0;
                //This is a safety net incase its reads from the file incorrectly
            }
            while (feof(input) == 0)
            {
                char c;
                fscanf(input, "%c", &c);
                if (c >= 'A' && c <= 'Z')
                {
                    c = (c-k);
                    if (c < 'A')
                    {
                        c += 26;
                    }
                }
                printf("%c", c); 
            }
            printf("\n");
        }   
        if (firstchoice == 3)
        {
            int d, d1, x=0; //d and d1 is the difference between some letter either
            //'I' or 'A' explained on line 119. x is a counter for the array
            FILE *input;
            input = fopen("input.txt", "r");
            if(input == NULL) 
            {
                perror("fopen()");
                return 0;
            }
            while (feof(input) == 0)
            {
                char message[1024]; 
                fgets(message, 1024, input);
                char c;
                fscanf(input, "%c", &c);
                if (message[x-1] == ' ' && message[x] > 'A' && message[x] < 'Z' && message[x+1] == ' ')
                /* tests for a single letter in message
                as this can only be an 'A' or an 'I'
                as these are the only two letters in the English
                language that appear as a single letter */
                {
                    d = message[x] - 'A';
                    d1 = message [x] - 'I';
                }
                c = c - d;
                if (c < 'A')
                    {
                        c += 26;
                    }
                    printf("%c", c); 
            }
            printf("\n");
        }
        
        /*      SUBSTITUTION CIPHER     */      
        if (firstchoice == 4) 
        {

        }
        if (firstchoice == 5)
        {
            
        }
    
    if (firstchoice != 1 && firstchoice != 2 && firstchoice != 3 && firstchoice != 4 && firstchoice != 5)
    {
        printf("Unknown input\n");
    }
    return 0;
}

