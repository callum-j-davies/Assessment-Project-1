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
        char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        srand(time(0));
        //generates a random set of numbers  [65,90] every tme the code is run
        //this number is assigned to each variable [a,z]
        //and then assigned to each letter in the input file as its substitution
            
        a = rand() % 26 + 65; //Adding 65 so that the numbers correspond with 'A' to 'Z' in the ascii table
        b = rand() % 26 + 65;
        c = rand() % 26 + 65;
        d = rand() % 26 + 65;
        e = rand() % 26 + 65;
        f = rand() % 26 + 65;
        g = rand() % 26 + 65;
        h = rand() % 26 + 65;
        i = rand() % 26 + 65;
        j = rand() % 26 + 65;
        k = rand() % 26 + 65;
        l = rand() % 26 + 65;
        l = rand() % 26 + 65;
        m = rand() % 26 + 65;
        n = rand() % 26 + 65;
        o = rand() % 26 + 65;
        p = rand() % 26 + 65;
        q = rand() % 26 + 65;
        r = rand() % 26 + 65;
        s = rand() % 26 + 65;
        t = rand() % 26 + 65;
        u = rand() % 26 + 65;
        v = rand() % 26 + 65;
        w = rand() % 26 + 65;
        x = rand() % 26 + 65;
        y = rand() % 26 + 65;
        z = rand() % 26 + 65;
        printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
        //used to see what the random numbers are for testing
                
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
            char letter = 0, letter1 = 0; // 'letter' is replacing 'c' as this variable name has been used
            fscanf(input, "%c", &letter);
            letter1 = letter;
            if (letter < 'A' || letter > 'Z')
            {
            letter = letter1;
            }
            if (letter1 == 'A')
            {
                letter = a;         //letter gets assigned the first random number
            }
            if (letter1 == 'B')
            {
                letter = b;         //letter gets assigned the second random number
            }
            if (letter1 == 'C')
            {
                letter = c;         //so on...
            }
            if (letter1 == 'D')
            {
                letter = d;
            }
            if (letter1 == 'E')
            {
                letter = e;
            }
            if (letter1 == 'F')
            {
                letter = f;
            }
            if (letter1 == 'G')
            {
                letter = g;
            }
            if (letter1 == 'H')
            {
                letter = h;
            }
            if (letter1 == 'I')
            {
                letter = i;
            }
            if (letter1 == 'J')
            {
                letter = j;
            }
            if (letter1 == 'K')
            {
                letter = k;
            }
            if (letter1 == 'L')
            {
                letter = l;
            }
            if (letter1 == 'M')
            {
                letter = m;
            }
            if (letter1 == 'N')
            {
                letter = n;
            }
            if (letter1 == 'O')
            {
                letter = o;
            }
            if (letter1 == 'P')
            {
                letter = p;
            }
            if (letter1 == 'Q')
            {
                letter = q;
            }
            if (letter1 == 'R')
            {
                letter = r;
            }
            if (letter1 == 'S')
            {
                letter = s;
            }
            if (letter1 == 'T')
            {
                letter = t;
            }
            if (letter1 == 'U')
            {
                letter = u;
            }
            if (letter1 == 'V')
            {
                letter = v;
            }
            if (letter1 == 'W')
            {
                letter = w;
            }
            if (letter1 == 'X')
            {
                letter = x;
            }
            if (letter1 == 'Y')
            {
                letter = y;
            }
            if (letter1 == 'Z')
            {
                letter = z;
            }
        printf("%c", letter);
        fprintf(output, "%c", letter);
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

