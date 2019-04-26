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

