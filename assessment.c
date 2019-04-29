/*This code is an ecryption and decryption software that will work for a
rotation or substitution cipher*/
/*Any input errors will return a '0' while any file reading/writing errors 
will return '1'*/
/*This code will only encrypt/decrypt UPPER CASE letters. any letter/number/character
will not have any encyption/decryption applied to them and will just be printed to the output file and 
stdoutput.*/
/*STEP 1:
Type/copy a message to the input.txt file in the Assessment-Project-1 folder
it doesnt matter whether it needs to be encrypted or decrypted
However this message must be in 'ALL CAPS'.
As previously stated any character outside the ASCII range 'A' - 'Z'
will not change*/
/*STEP 2:
Run the code in the compiler, where the menu screen will be displayed
The compiler will read your choice from the menu screen*/
/*STEP 3:
The final message will be printed to both the output.txt file and the
terminal interface*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
/*Not all of these libraries are used but i have included them incase
i wanted to make adjustments to my code*/
/*the int 'k' will be the variable in which the key is stored should it be needed*/
/*the int 'i' is used as a counter*/
/*the char 'c' and 'c1' for roation and 'letter' and 'letter1' for substitution are used 
to store the character read from the file 'input.txt'*/
 


int main()
{
    int firstchoice; // the variable which is read and determines what code is run
    printf("        -------CIPHER-------\n");
    printf("    Rotation - Encryption (1)\n");
    printf("    Rotation - Decryption [Key Known] (2)\n");
    printf("    Rotation - Decryption [Key Unknown] (3)\n");
    printf("    Substitution - Encryption [Key Known] (4)\n");
    printf("    Substitution - Encryption [Key is Randomised] (5)\n");
    printf("    Substitution - Decryption [Key Known] (6)\n");
    printf("    Substitution - Decryption [Key Unkown] (7)\n");
    printf("    Your Choice: ");
    //This will decide what code is run
    scanf("%d", &firstchoice);
    
    /*         ROTATION CIPHER             */
        if (firstchoice == 1) //runs encryption
        {
            int k; //this is the numerical value between [0,26] which will determine how far the message is rotated
            printf("\nEnter encryption key [0 to 26]: ");
            scanf("%d", &k);
            if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8 && k != 9 && k != 10 && k != 11 && k != 12 && k != 13 && k != 14 && k != 15 && k != 16 && k != 17 && k != 18 && k != 19 && k != 20 && k != 21 && k != 22 && k != 23 && k != 24 && k != 25 && k != 26)
            {
                printf("\nUnknown Input\n\n"); 
                /*This is input error testing. 
                Another way would be to use the 
                modulus of the abs(k) forcing the number to be between 0 and 26*/
                return 0;
            }
            printf("\n"); // this is for formatting
            FILE *input;
            FILE *output;
            input = fopen("input.txt", "r"); //Will read the message from the file input.txt
            output = fopen("output.txt", "w"); //Will write the message to the file output.txt
            if(input == NULL)  //This is a safety net incase its reads the file 'input.txt' incorrectly
            {
                perror("fopen()");
                return 1;
            }
            if (output == NULL) //This is a safety net incase its reads the 'output.txt' file incorrectly
            {
                perror("fopen()");
                return 1;
            }
            while (feof(input) == 0) //Will read until the end of file as this will return a 1.
            {
                char c, c1; //c1 is used as manipulated will be done on the variable c. They are equal before any key is applied
                fscanf(input, "%c", &c); //reads each letter from the file input and stores it in c
                c1 = c;
                if (c >= 'A' && c <= 'Z')
                {
                    c = c + k; //applies the encryption
                }
                if ( (c1+k) >= '[')
                {
                    c = c - 26; // loops the encryption back to 'A' if the letter with the encyption applied goes over the value of 'Z'
                }
                if (c1 < 'A' || c1 > 'Z')
                {
                    c = c1; // anything outside of 'A' to 'Z' will remain unchanged
                }
                printf("%c", c);
                fprintf(output, "%c", c);
                /* Prints the message to both the concsole and to the file output*/
            }
            printf("\n\n"); //formating 
        }
        if (firstchoice == 2)//runs decryption [key known]
        {
            int k; //Read from the user determines the decryption of the message 
            printf("\nWhat is the decryption key [0-26]: ");
            scanf("%d", &k); //another input is read from the user
            if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8 && k != 9 && k != 10 && k != 11 && k != 12 && k != 13 && k != 14 && k != 15 && k != 16 && k != 17 && k != 18 && k != 19 && k != 20 && k != 21 && k != 22 && k != 23 && k != 24 && k != 25 && k != 26)
            {
                printf("Unkown Input\n");
                /*This is input error testing. 
                Another way would be to use the 
                modulus of the abs(k) forcing the number to be between 0 and 26*/
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
        if (firstchoice == 3)//Decryption key unknown. This is a brute froce attack printing all 26 possiblilites
        {
            printf("\n");
            int i; //i is a counter for the brute force decryption
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
            for (i = 0; i < 26; i++) 
            //Will print every possible decryption as a key of '26' is the same as a key of '0' that is why it is not tested
            {
                printf("Key used for Decryption: %d\n", i); 
                fprintf(output, "Key used for Decryption: %d\n", i);
                //Lets you know which decryption key worked
                rewind(input);
                while (feof(input) == 0)
                {
                    char c, c1;
                    fscanf(input, "%c", &c);
                    c1 = c;
                    if (c1 >= 'A' && c1 <= 'Z')
                    {
                        c = c - i;
                    }
                    if ( (c1-i) < 'A' )
                    {
                        c = c + 26;
                    }
                    if (c1 <'A' || c1 > 'Z')
                    {
                        c = c1;
                    }
                    printf("%c", c);
                    fprintf(output, "%c", c);
                }
            printf("\n\n");
            fprintf(output, "\n\n");
            }
            printf("\n\n");
        }
        
    /*      SUBSTITUTION CIPHER     */      
    if (firstchoice == 4) // Substitution encryption key known
    {
        char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        //Each letter represents the subsitution key for its respecitve UPPER CASE letter when read from the user
            printf("\nType Substitution Key for each letter:\n");
            printf("A: ");
            scanf(" %c", &a);
            if (a < 'A' || a > 'Z') //Input error tests
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("B: ");
            scanf(" %c", &b);
            if (b < 'A' || b > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("C: ");
            scanf(" %c", &c);
            if (c < 'A' || c > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("D: ");
            scanf(" %c", &d);
            if (d < 'A' || d > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("E: ");
            scanf(" %c", &e);
            if (e < 'A' || e > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("F: ");
            scanf(" %c", &f);
            if (f < 'A' || f > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("G: ");
            scanf(" %c", &g);
            if (g < 'A' || g > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("H: ");
            scanf(" %c", &h);
            if (h < 'A' || h > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("I: ");
            scanf(" %c", &i);
            if (i < 'A' || i > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("J: ");
            scanf(" %c", &j);
            if (j < 'A' || j > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("K: ");
            scanf(" %c", &k);
            if (k < 'A' || k > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("L: ");
            scanf(" %c", &l);
            if (l < 'A' || l > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("M: ");
            scanf(" %c", &m);
            if (m < 'A' || m > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("N: ");
            scanf(" %c", &n);
            if (n < 'A' || n > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("O: ");
            scanf(" %c", &o);
            if (o < 'A' || o > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("P: ");
            scanf(" %c", &p);
            if (p < 'A' || p > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("Q: ");
            scanf(" %c", &q);
            if (q < 'A' || q > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("R: ");
            scanf(" %c", &r);
            if (r < 'A' || r > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("S: ");
            scanf(" %c", &s);
            if (s < 'A' || s > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("T: ");
            scanf(" %c", &t);
            if (t < 'A' || t > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("U: ");
            scanf(" %c", &u);
            if (u < 'A' || u > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("V: ");
            scanf(" %c", &v);
            if (v < 'A' || v > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("W: ");
            scanf(" %c", &w);
            if (w < 'A' || w > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("X: ");
            scanf(" %c", &x);
            if (x < 'A' || x > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("Y: ");
            scanf(" %c", &y);
            if (y < 'A' || y > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("Z: ");
            scanf(" %c", &z);
            if (z < 'A' || z > 'Z')
            {
                printf("\nUnknown Input\n\n");
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
                char letter = 0, letter1 = 0;
                fscanf(input, "%c", &letter);
                letter1 = letter;
                if (letter < 'A' || letter > 'Z')
                {
                    letter = letter1;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'A') //Assigning each letter to what is is subsituted to from the user inputed key
                {
                    letter = a;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'B')
                {
                    letter = b;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'C')
                {
                    letter = c;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'D')
                {
                    letter = d;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'E')
                {
                    letter = e;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'F')
                {
                    letter = f;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'G')
                {
                    letter = g;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'H')
                {
                    letter = h;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'I')
                {
                    letter = i;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'J')
                {
                    letter = j;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'K')
                {
                    letter = k;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'L')
                {
                    letter = l;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'M')
                {
                    letter = m;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'N')
                {
                    letter = n;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'O')
                {
                    letter = o;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'P')
                {
                    letter = p;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'Q')
                {
                    letter = q;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'R')
                {
                    letter = r;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'S')
                {
                    letter = s;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'T')
                {
                    letter = t;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'U')
                {
                    letter = u;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'V')
                {
                    letter = v;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'W')
                {
                    letter = w;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'X')
                {
                    letter = x;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'Y')
                {
                    letter = y;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'Z')
                {
                    letter = z;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
            }
        printf("\n\n");            
    }
    
    if (firstchoice == 5)//Substitution encryption with a random key 
    {
        printf("\n");
        char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        srand(time(0));
        //generates a random set of numbers every time the code is run
        //this number is assigned to each variable [a,z]
        //and then assigned to each letter in the input file as its substitution
            
        a = rand() % 26 + 65; //Adding 65 so that the numbers correspond with 'A' to 'Z' in the ascii table
        b = rand() % 26 + 65; // i.e. making the number between 65 and 90
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
        /*The next 200 lines of code ensure that the random number assigned to each variable is unique
        thereby ensuring that each letter gets a unique substitution.
        it does this by adding 1 to the number until it reaches a number that is unique between '65' and '90'.
        It does this by testing each varibale with every other variable 'a' to 'z' exluding the one being tested.
        There are also an error test to ensure the number stays between '65' and '90' 
        by minusing 26 from the number if it exceeds '90'*/
       
        while (b == a || b == c || b == d || b == e || b == f || b == g || b == h || b == i || b == j || b == k || b == l || b == m || b == n || b == o || b == p || b == q || b == r || b == s || b == t || b == u || b == v || b == w || b == x || b == y || b == z)
        {
            b = b + 1;
            if (b > 90)
            {
                b = b - 26;
            }
        }
        while (c == a || c == b || c == d || c == e || c == f || c == g || c == h || c == i || c == j || c == k || c == l || c == m || c == n || c == o || c == p || c == q || c == r || c == s || c == t || c == u || c == v || c == w || c == x || c == y || c == z)
        {
            c = c + 1;
            if (c > 90)
            {
                c = c - 26;
            }
        }
        while (d == a || d == b || d == c || d == e || d == f || d == g || d == h || d == i || d == j || d == k || d == l || d == m || d == n || d == o || d == p || d == q || d == r || d == s || d == t || d == u || d == v || d == w || d == x || d == y || d == z)
        {
            d = d + 1;
            if (d > 90)
            {
                d = d - 26;
            }
        }
        while (e == a || e == b || e == c || e == d || e == f || e == g || e == h || e == i || e == j || e == k || e == l || e == m || e == n || e == o || e == p || e == q || e == r || e == s || e == t || e == u || e == v || e == w || e == x || e == y || e == z)
        {
            e = e + 1;
            if (e > 90)
            {
                e = e - 26;
            }
        }
        while (f == a || f == b || f == c || f == d || f == e || f == g || f == h || f == i || f == j || f == k || f == l || f == m || f == n || f == o || f == p || f == q || f == r || f == s || f == t || f == u || f == v || f == w || f  == x || f == y || f == z)
        {
            f = f + 1;
            if (f > 90)
            {
                f = f - 26;
            }
        }
        while (g == a || g == b || g == c || g == d || g == e || g == f || g == h || g == i || g == j || g == k || g == l || g == m || g == n || g == o || g == p || g == q || g == r || g == s || g == t || g == u || g == v || g == w || g == x || g == y || g == z)
        {
            g = g + 1;
            if (g > 90)
            {
                g = g - 26;
            }
        }
        while (h == a || h == b || h == c || h == d || h == e || h == f || h == g || h == i || h == j || h == k || h == l || h == m || h == n || h == o || h == p || h == q || h == r || h == s || h== t || h == u || h == v || h == w || h == x || h == y || h == z)
        {
            h = h + 1;
            if (h > 90)
            {
                h = h - 26;
            }
        }
        while (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h || i == j || i == k || i == l || i == m || i == n || i == o || i == p || i == q || i == r || i == s || i == t || i == u || i == v || i == w || i == x || i == y || i == z)
        {
            i = i + 1;
            if (i > 90)
            {
                i = i - 26;
            }
        }
        while (j == a || j == b || j == c || j == d || j == e || j == f || j == g || j == h || j == i || j == k || j == l || j == m || j == n || j == o || j == p || j == q || j == r || j == s || j == t || j == u || j == v || j == w || j == x || j == y || j == z)
        {
            j = j + 1;
            if (j > 90)
            {
                j = j - 26;
            }
        }
        while (k == a || k == b || k == c || k == d || k == e || k == f || k == g || k == h || k == i || k == j || k == l || k == m || k == n || k == o || k == p || k == q || k == r || k == s || k == t || k == u || k == v || k == w || k == x || k == y || k == z)
        {
            k = k + 1;
            if (k > 90)
            {
                k = k - 26;
            }
        }
        while (l == a || l == b || l == c || l == d || l == e || l == f || l == g || l == h || l == i || l == j || l == k || l == m || l == n || l == o || l == p || l == q || l == r || l == s || l == t || l == u || l == v || l == w || l == x || l == y || l == z)
        {
            l = l + 1;
            if (l > 90)
            {
                l = l - 26;
            }
        }
        while (m == a || m == b || m == c || m == d || m == e || m == f || m == g || m == h || m == i || m == j || m == k || m == l || m == n || m == o || m == p || m == q || m == r || m == s || m == t || m == u || m == v || m == w || m == x || m == y || m == z)
        {
            m = m + 1;
            if (m > 90)
            {
                m = m - 26;
            }
        }
        while (n == a || n == b || n == c || n == d || n == e || n == f || n == g || n == h || n == i || n == j || n == k || n == l || n == m || n == o || n == p || n == q || n == r || n == s || n == t || n == u || n == v || n == w || n == x || n == y || n == z)
        {
            n = n + 1;
            if (n > 90)
            {
                n = n - 26;
            }
        }
        while (o == a || o == b || o == c || o == d || o == e || o == f || o == g || o == h || o == i || o == j || o == k || o == l || o == m || o == n || o == p || o == q || o == r || o == s || o == t || o == u || o == v || o == w || o == x || o == y || o == z)
        {
            o = o + 1;
            if (o > 90)
            {
                o = o - 26;
            }
        }
        while (p == a || p == b || p == c || p == d || p == e || p == f || p == g || p == h || p == i || p == j || p == k || p == l || p == m || p == n || p == o || p == q || p == r || p == s || p == t || p == u || p == v || p == w || p == x || p == y || p == z)
        {
            p = p + 1;
            if (p > 90)
            {
                p = p - 26;
            }
        }
        while (q == a || q == b || q == c || q == d || q == e || q == f || q == g || q == h || q == i || q == j || q == k || q == l || q == m || q == n || q == o || q == p || q == r || q == s || q == t || q == u || q == v || q == w || q == x || q == y || q == z)
        {
            q = q + 1;
            if (q > 90)
            {
                q = q - 26;
            }
        }
        while (r == a || r == b || r == c || r == d || r == e || r == f || r == g || r == h || r == i || r == j || r == k || r == l || r == m || r == n || r == o || r == p || r == q || r == s || r == t || r == u || r == v || r == w || r == x || r == y || r == z)
        {
            r = r + 1;
            if (r > 90)
            {
                r = r - 26;
            }
        }
        while (s == a || s == b || s == c || s == d || s == e || s == f || s == g || s == h || s == i || s == j || s == k || s == l || s == m || s == n || s == o || s == p || s == q || s == r || s == t || s == u || s == v || s == w || s == x || s == y || s == z)
        {
            s = s + 1;
            if (s > 90)
            {
                s = s - 26;
            }
        }
        while (t == a || t == b || t == c || t == d || t == e || t == f || t == g || t == h || t == i || t == j || t == k || t == l || t == m || t == n || t == o || t == p || t == q || t == r || t == s || t == u || t == v || t == w || t == x || t == y || t == z)
        {
            t = t + 1;
            if (t > 90)
            {
                t = t - 26;
            }
        }
        while (u == a || u == b || u == c || u == d || u == e || u == f || u == g || u == h || u == i || u == j || u == k || u == l || u == m || u == n || u == o || u == p || u == q || u == r || u == s || u == t || u == v || u == w || u == x || u == y || u == z)
        {
            u = u + 1;
            if (u > 90)
            {
                u = u - 26;
            }
        }
        while (v == a || v == b || v == c || v == d || v == e || v == f || v == g || v == h || v == i || v == j || v == k || v == l || v == m || v == n || v == o || v == p || v == q || v == r || v == s || v == t || v == u || v == w || v == x || v == y || v == z)
        {
            v = v + 1;
            if (v > 90)
            {
                v = v - 26;
            }
        }
        while (w == a || w == b || w == c || w == d || w == e || w == f || w == g || w == h || w == i || w == j || w == k || w == l || w == m || w == n || w == o || w == p || w == q || w == r || w == s || w == t || w == u || w == v || w == x || w == y || w == z)
        {
            w = w + 1;
            if (w > 90)
            {
                w = w - 26;
            }
        }
        while (x == a || x == b || x == c || x == d || x == e || x == f || x == g || x == h || x == i || x == j || x == k || x == l || x == m || x == n || x == o || x == p || x == q || x == r || x == s || x == t || x == u || x == v || x == w || x == y || x == z)
        {
            x = x + 1;
            if (x > 90)
            {
                x = x - 26;
            }
        }
        while (y == a || y == b || y == c || y == d || y == e || y == f || y == g || y == h || y == i || y == j || y == k || y == l || y == m || y == n || y == o || y == p || y == q || y == r || y == s || y == t || y == u || y == v || y == w || y == x || y == z)
        {
            y = y + 1;
            if (y > 90)
            {
                y = y - 26;
            }
        }
        while (z == a || z == b || z == c || z == d || z == e || z == f || z == g || z == h || z == i || z == j || z == k || z == l || z == m || z == n || z == o || z == p || z == q || z == r || z == s || z == t || z == u || z == v || z == w || z == x || z == y)
        {
            z = z + 1;
            if (z > 90)
            {
                z = z - 26;
            }
        }

        // printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
        /*used to see what the random numbers are for testing.
        Will add to comments for final product*/
                
        printf("\n"); //formatting
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
            letter = letter1; //character is unchanged outside of the range 'A' to 'Z'
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
        //This letter is then printed to stdoutput and the file output.txt
        }
        printf("\n\n");//formatting
    }
        
        if (firstchoice == 6)//Substituion decrpytion key known 
        {
            char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
            printf("\nType Substitution Key for each letter:\n");
            printf("A: ");
            scanf(" %c", &a);
            if (a < 'A' || a > 'Z') //Input error tests
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("B: ");
            scanf(" %c", &b);
            if (b < 'A' || b > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("C: ");
            scanf(" %c", &c);
            if (c < 'A' || c > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("D: ");
            scanf(" %c", &d);
            if (d < 'A' || d > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("E: ");
            scanf(" %c", &e);
            if (e < 'A' || e > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("F: ");
            scanf(" %c", &f);
            if (f < 'A' || f > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("G: ");
            scanf(" %c", &g);
            if (g < 'A' || g > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("H: ");
            scanf(" %c", &h);
            if (h < 'A' || h > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("I: ");
            scanf(" %c", &i);
            if (i < 'A' || i > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("J: ");
            scanf(" %c", &j);
            if (j < 'A' || j > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("K: ");
            scanf(" %c", &k);
            if (k < 'A' || k > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("L: ");
            scanf(" %c", &l);
            if (l < 'A' || l > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("M: ");
            scanf(" %c", &m);
            if (m < 'A' || m > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("N: ");
            scanf(" %c", &n);
            if (n < 'A' || n > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("O: ");
            scanf(" %c", &o);
            if (o < 'A' || o > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("P: ");
            scanf(" %c", &p);
            if (p < 'A' || p > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("Q: ");
            scanf(" %c", &q);
            if (q < 'A' || q > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("R: ");
            scanf(" %c", &r);
            if (r < 'A' || r > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("S: ");
            scanf(" %c", &s);
            if (s < 'A' || s > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("T: ");
            scanf(" %c", &t);
            if (t < 'A' || t > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("U: ");
            scanf(" %c", &u);
            if (u < 'A' || u > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("V: ");
            scanf(" %c", &v);
            if (v < 'A' || v > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("W: ");
            scanf(" %c", &w);
            if (w < 'A' || w > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("X: ");
            scanf(" %c", &x);
            if (x < 'A' || x > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("Y: ");
            scanf(" %c", &y);
            if (y < 'A' || y > 'Z')
            {
                printf("\nUnknown Input\n\n");
                return 0;
            }
            printf("\n");
            printf("Z: ");
            scanf(" %c", &z);
            if (z < 'A' || z > 'Z')
            {
                printf("\nUnknown Input\n\n");
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
                char letter = 0, letter1 = 0;
                fscanf(input, "%c", &letter);
                letter1 = letter;
                if (letter < 'A' || letter > 'Z')
                {
                    letter = letter1;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'A') //Assigning each letter to what is is subsituted to from the use inputed key
                {
                    letter = a;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'B')
                {
                    letter = b;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'C')
                {
                    letter = c;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'D')
                {
                    letter = d;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'E')
                {
                    letter = e;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'F')
                {
                    letter = f;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'G')
                {
                    letter = g;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'H')
                {
                    letter = h;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'I')
                {
                    letter = i;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'J')
                {
                    letter = j;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'K')
                {
                    letter = k;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'L')
                {
                    letter = l;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'M')
                {
                    letter = m;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'N')
                {
                    letter = n;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'O')
                {
                    letter = o;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'P')
                {
                    letter = p;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'Q')
                {
                    letter = q;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'R')
                {
                    letter = r;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'S')
                {
                    letter = s;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'T')
                {
                    letter = t;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'U')
                {
                    letter = u;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'V')
                {
                    letter = v;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'W')
                {
                    letter = w;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'X')
                {
                    letter = x;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'Y')
                {
                    letter = y;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
                if (letter1 == 'Z')
                {
                    letter = z;
                    printf("%c", letter);
                    fprintf(output, "%c", letter);
                }
            }
        printf("\n\n");
        }
        
        if (firstchoice == 7)//Substitution Decryption
        {
            printf("\nThis is currently unavailable\n\n");
        }
        
        if (firstchoice != 1 && firstchoice != 2 && firstchoice != 3 && firstchoice != 4 && firstchoice != 5 && firstchoice != 6 && firstchoice !=7)
        {
            //This is input error protection
            printf("\nUnknown input\n\n");
            return 0;
        }
    return 0;
}

