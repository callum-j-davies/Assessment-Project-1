/*This code is an ecryption and decryption software that will work for a
rotation or substitution cipher*/
/*Any input errors will return a '0' while any file reading/writing errors 
will return '1'*/
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
#include <time.h>
/*Not all of these libraries are used but i have included them incase
i wanted to make adjustments to my code*/
 


int main()
{
    int firstchoice; // decides what code is run
    printf("        -------CIPHER-------\n");
    printf("    Rotation - Encryption (1)\n");
    printf("    Rotation - Decryption [Key Known] (2)\n");
    printf("    Rotation - Decryption [Key Unknown] (3)\n");
    printf("    Substitution - Encryption (4)\n");
    printf("    Substitution - Decryption (5)\n");
    printf("    Your Choice: ");
    //This will decide what code is run
    scanf("%d", &firstchoice);
    
    /*         ROTATION CIPHER             */
        if (firstchoice == 1) //runs encryption
        {
            int k;
            printf("Enter encryption key [0 to 26]: ");
            //This will determine how much the message is rotated
            scanf("%d", &k);
            if (k < 0 || k > 26)
            {
                printf("Unknown Input\n");
                return 0;
            }
            printf("\n"); // this is for formatting
            FILE *input;
            FILE *output;
            input = fopen("input.txt", "r"); //Will read from the file input.txt
            output = fopen("output.txt", "w"); //Will write to the file output.txt
            if(input == NULL)  //This is a safety net incase its reads from the file incorrectly
            {
                perror("fopen()");
                return 1;
            }
            if (output == NULL) //This is a safety net incase its reads from the file incorrectly
            {
                perror("fopen()");
                return 1;
            }
            while (feof(input) == 0)
            {
                char c, c1;
                fscanf(input, "%c", &c); //reads each letter from the file input and stores it in c
                c1 = c;
                if (c >= 'A' && c <= 'Z')
                {
                    c = c + k; //applies the encryption
                }
                if ( (c1+k) >= '[')
                {
                    c = c - 26; // loops the encryption back to 'A'
                }
                if (c1 < 'A' || c1 > 'Z')
                {
                    c = c1; // anything outside of 'A' to 'Z' will remain unchanged
                }
                printf("%c", c);
                fprintf(output, "%c", c);
                /* Prints the message to both the concsole and to the file output*/
            }
            printf("\n\n");
        }
        if (firstchoice == 2)//runs decryption
        {
            int k;
            printf("\nWhat is the decryption key [0-26]: ");
            scanf("%d", &k);
            if (k < 0 || k > 26)
            {
                printf("Unkown Input\n");
                return 0;
            }
            printf("\n");
            FILE *input;
            FILE *output;
            input = fopen("input.txt", "r");
            output = fopen("output.txt", "w");
            if(input == NULL) 
            {
                perror("fopen()");
                return 1;
            }
            if (output == NULL)
            {
                perror("fopen()");
                return 1;
            }
            while (feof(input) == 0)
            {
                char c, c1;
                fscanf(input, "%c", &c);
                c1=c;
                if (c >= 'A' && c <= 'Z')
                {
                    c = (c-k); // applies decryption
                }
                if ( (c1-k) < 'A') // allows decryption to loop back to 'Z'
                {
                    c = c + 26;
                }
                if (c1 < 'A' || c1 > 'Z')
                {
                    c = c1; // anything outside of 'A' to 'Z' will remain unchanged
                }
                printf("%c", c);
                fprintf(output, "%c", c);
            }
            printf("\n\n");
        }      
        if (firstchoice == 3)
        {
            int i; //i is a counter
            FILE *input;
            FILE *output;
            input = fopen("input.txt", "r");
            output = fopen("output.txt", "w");
            if(input == NULL) 
            {
                perror("fopen()");
                return 1;
            }
            if (output == NULL)
            {
                perror("fopen()");
                return 1;
            }

            for (i = 1; i <= 26; i++) //Will print every possible decryption
            {
                while (feof(input) == 0)
                {
                    char c, c1;
                    fscanf(input, "%c", &c);
                    c1 = c;
                    if (c >= 'A' && c <= 'Z')
                    {
                        c = c - i;
                    }
                    if ( (c1-i) < 'A' )
                    {
                        c = c + 26;
                    }
                    if (c1 <'A' || c1 > 'Z')
                    {
                        c = c;
                    }
                    printf("%c", c);
                    fprintf(output, "%c", c);
                }   
            }
            printf("\n\n");
        }
        
    /*      SUBSTITUTION CIPHER     */      
        if (firstchoice == 4) 
        {
            printf("\n");
            int counter;
            int num;
            char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
            srand(time(0));
            for (counter = 0; counter < 26; counter ++)
            //generates a random set of numbers  [65,90] every tme the code is run
            //this number is assigned to each variable [a,z]
            //and then assigned to each letter in the input file as its substitution
            {
                num = rand() % 26 + 65; //Adding 65 so that the numbers correspond with 'A' to 'Z' in the ascii table
                printf("%d, ", num); //used to see what the random numbers are for testing
                if (counter == 0)
                    a = num;
                if (counter == 1)
                    b = num;
                if (counter == 2)
                    c = num;
                if (counter == 3)
                    d = num;
                if (counter == 4)
                    e = num;
                if (counter == 5)
                    f = num;
                if (counter == 6)
                    g = num;
                if (counter == 7)
                    h = num;
                if (counter == 8)
                    i = num;
                if (counter == 9)
                    j = num;
                if (counter == 10)
                    k = num;
                if (counter == 11)
                    l = num;
                if (counter == 12)
                    m = num;
                if (counter == 13)
                    n = num;
                if (counter == 14)
                    o = num;
                if (counter == 15)
                    p = num;
                if (counter == 16)
                    q = num;
                if (counter == 17)
                    r = num;
                if (counter == 18)
                    s = num;
                if (counter == 19)
                    t = num;
                if (counter == 20)
                    u = num;
                if (counter == 21)
                    v = num;
                if (counter == 22)
                    w = num;
                if (counter == 23)
                    x = num;
                if (counter == 24)
                    y = num;
                if (counter == 25)
                    z = num;
            }
        printf("\n");
        FILE *input;
        FILE *output;
        input = fopen("input.txt", "r");
        output = fopen("output.txt", "w");
        if(input == NULL) 
        {
            perror("fopen()");
            return 1;
        }
        if (output == NULL)
        {
            perror("fopen()");
            return 1;
        }
        while (feof(input) == 0)
        {
            char letter; // 'letter' is replacing 'c' as this variable name has been used
            fscanf(input, "%c", &letter);
            if (letter < 'A' || letter > 'Z')
            {
                letter = letter;
                printf("%c", letter);
                fprintf(input, "%c", letter);
            }
            if (letter == 'A')
            {
                letter = a;         //letter gets assigned the first random number
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'B')
            {
                letter = b;         //letter gets assigned the second random number
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'C')
            {
                letter = c;         //so on...
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'D')
            {
                letter = d;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'E')
            {
                letter = e;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'F')
            {
                letter = f;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'G')
            {
                letter = g;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'H')
            {
                letter = h;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'I')
            {
                letter = i;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'J')
            {
                letter = j;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'K')
            {
                letter = k;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'L')
            {
                letter = l;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'M')
            {
                letter = m;
                printf("%c", letter);
                fprintf(output, "%c", letter);
                }
            if (letter == 'N')
            {
                letter = n;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'O')
            {
                letter = o;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'P')
            {
                letter = p;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'Q')
            {
                letter = q;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'R')
            {
                letter = r;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'S')
            {
                letter = s;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'T')
            {
                letter = t;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'U')
            {
                letter = u;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'V')
            {
                letter = v;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'W')
            {
                letter = w;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'X')
            {
                letter = x;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'Y')
            {
                letter = y;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
            if (letter == 'Z')
            {
                letter = z;
                printf("%c", letter);
                fprintf(output, "%c", letter);
            }
        }
        printf("\n\n");
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

