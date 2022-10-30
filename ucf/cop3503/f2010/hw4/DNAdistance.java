// Find edit distances between strings

import java.util.*;
import java.io.*;
import java.math.*;

public class DNAdistance
{
    // file to open
    private static final String    input_file = "DNA.in";
    
    // used for looking up dna characters quickly
    private static final char[]    dna_accepted_char  = { 'A', 'T', 'G', 'C' };
    private static       int[]     dna_char;    
    private static final int       dna_add_cost = 2;
    private static final int       dna_del_cost = 2;
    private static final int[][]   dna_swap_cost_table = 
    {
        // A T G C
        { 0, 2, 3, 4 }, // A
        { 2, 0, 4, 5 }, // T
        { 3, 4, 0, 1 }, // G
        { 4, 5, 1, 0 }, // C
    };

    public static void main(String[] args)
    {
        int      i;
        int      test_cases;
        Scanner  ifp;

        // the data
        String str1, str2; 
        
        // open the file
        try
        {
            ifp = new Scanner(new File(input_file), "ISO-8859-1");
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Can't open input file " + input_file + ".");
            System.out.println(e.getMessage());
            return;
        }
        
        // init lookup tables for uses 
        dna_char            = new int[26];
       
        // init dna accepted chars for quick lookup
        for (i = 0; i < 26; i++)
            dna_char[i] = 26;

        for (i = 0; i < dna_accepted_char.length; i++)
            dna_char[dna_accepted_char[i] - 'A'] = i;

        // get number of test cases
        test_cases = ifp.nextInt();
       
        for (i = 0; i < test_cases; i++)
        {
            System.out.print("Test " + (i + 1) + ": ");

            // get the data
            str1 = ifp.next();
            str2 = ifp.next();
            
            System.out.println("The edit distance is " + edit_distance(str1, str2) + ".");
        }
        
        // cleanup
        ifp.close();
    }

    // get swap cost of 2 chars 
    private static int calc_swap_cost(char a, char b)
    {
        // unknown chars
        if (a < 'A' || a > 'Z' || b < 'A' || b > 'Z' || 
           (dna_char[a - 'A'] > 25) || (dna_char[b - 'A'] > 25))
            return 2;
        
        return dna_swap_cost_table[dna_char[a - 'A']][dna_char[b - 'A']];
    }

    // find edit distance between 2 string
    private static int edit_distance(String a, String b)
    {
        char    c1, c2;
        int     i, k, alen, blen, edit_cost, up, left, diagonal;
        int[][] table;

        // a is horizontal, b is vertical
        alen   = a.length() + 1;
        blen   = b.length() + 1;

        table  = new int[alen][blen];
      
        // init the table to the delete costs of various one chars 
        for (i = 0; i < alen; i++)
            table[i][0] = dna_del_cost * i; 

        for (i = 0; i < blen; i++)
            table[0][i] = dna_add_cost * i;
     
        // find edit distance
        for (i = 1; i < blen; i++)
        {
            for (k = 1; k < alen; k++)
            {
                c1       = a.charAt(k - 1);
                c2       = b.charAt(i - 1);
                diagonal = table[k - 1][i - 1];

                // if match copy diagonal
                if (c1 == c2)
                    table[k][i] = diagonal; 
                else
                {
                    // take the minimum of the diagonal/up/left + cost
                    up    = table[k][i - 1];
                    left  = table[k - 1][i];

                    edit_cost    = calc_swap_cost(c1, c2);
                    table[k][i]  = Math.min(diagonal + edit_cost, 
                                            Math.min(dna_del_cost + left, dna_add_cost + up));
                }
            }
        }
        
        return table[alen - 1][blen - 1];
    }
}

