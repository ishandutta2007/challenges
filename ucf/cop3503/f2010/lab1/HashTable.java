import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

public class HashTable
{
    // constants
    public  final static int TABLE_SIZE = 9109;
    public  static int       NOT_FOUND  = -1;
    
    // statistic variable for the hash table
    private long             longest_entry;
    private long             empty_entries;
    private long             average_sum;

    // hash table made of linked lists
    private LinkedList[]     table;

    // constructor makes the table
    // and set defaults
    public HashTable()
    {
        // init the linked list for use
        table = new LinkedList[TABLE_SIZE];
        
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = new LinkedList();

        clear();
    }

    // reset everything
    private void clear()
    {
        average_sum   = 0;
        longest_entry = 0;
        empty_entries = TABLE_SIZE;
        
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i].clear();
    }
    
    // return how many free entries in the hash table 
    // there are
    private long get_empty_entries_num()
    {
        return empty_entries;
    }

    // get longest length
    private long get_longest_entry()
    {
        return longest_entry;
    }

    // get average length of the non empty entries
    private double get_average_entry_length()
    {
        // avoid dividing by 0
        if (empty_entries == TABLE_SIZE)
            return 0.0;
        
        return average_sum / ((TABLE_SIZE - empty_entries) * 1.0);
    }

    // insert name into the hash table
    public void insert(String w)
    {
        int    i, len;
        int    index;
        String lower;

        lower = w.toLowerCase();
        index = hashFunction(lower);

        // search if there is already a person of this
        // name
        for (i = 0, len = table[index].size(); i < len; i++)
        {
            // already have it just return
            if (lower.compareTo((String)table[index].get(i)) == 0)
                return;
        }

        table[index].addLast(lower);

        // this is to update the statistic data incrementally
        // so whenever we need the statistic we don't have to
        // rebuild it from scratch
        if (len == 0)
            empty_entries--;
        
        average_sum++;
        
        longest_entry = Math.max(longest_entry, table[index].size());
    }

    // hash function to get the index
    private int hashFunction(String w)
    {
        int    index = 0, exp = 1;
        String lower = w.toLowerCase();
        
        // go through the string backward using 
        // val(character[len-i]) * 26^i for i = 0 to n
        for (int i = 0, j = lower.length() - 1; j >= i; j--)
        {
            // make sure the character is an alphabet character
            // so it ignores stuff like underscores and numbers
            // only do english char, ignore the rest
            if (lower.charAt(j) >= 'a' && lower.charAt(j) <= 'z')
            //if (Character.isLetter(lower.charAt(j)))
            {
                // have to do modular exponentiation so 
                // the numbers don't get too big
                index += ((lower.charAt(j) - 'a')) * exp;
                exp    = (exp * 26) % TABLE_SIZE;
                index  = index % TABLE_SIZE;
            }
        }
        
        return index;
    }

    // If w is in the hash table, the integer returned is 
    // the location of of w in the hash table. If w is NOT in 
    // the table, then NOT_FOUND is returned 
    public int search(String w)
    {
        String lower = w.toLowerCase();
        int    index = hashFunction(lower);
        
        for (int i = 0, j = table[index].size(); i < j; i++)
        {
            if (lower.compareTo((String)table[index].get(i)) == 0)
                return index;
        }

        return NOT_FOUND;
    }

    public static void main(String[] args) throws IOException
    {
        String    filename, user_input;
        HashTable hash_table = new HashTable();
        Scanner   stdin      = new Scanner(System.in), 
                  ifp;

        System.out.println("Welcome to the Famous People List!");
        System.out.println("Enter the name of your people file.");

        // open the input file 
        // in ISO-8859-1 format since the sample file
        // given is in that format
		filename = "";
        try
        {
			filename = stdin.next();
            ifp = new Scanner(new File(filename), "ISO-8859-1");
        }
        catch (Exception e)
        {
            System.out.println("Can't open the input file " + filename + "!");
            return;
        }

        // read in the file and store it in a hash table
        for (int i = 0, npeople = ifp.nextInt(); i < npeople; i++)
        {
            String famous_people_name = ifp.next();
            hash_table.insert(famous_people_name);
        }

        System.out.println(""); 
        System.out.println("Great, your list has been stored in memory.");
        System.out.println("There are " + hash_table.get_empty_entries_num() + " empty entries.");
        System.out.println("The longest entry is length " + hash_table.get_longest_entry() + ".");
        System.out.println("The average length of an entry is " + hash_table.get_average_entry_length() + ".");
        System.out.println("");

        for (;;)
        {
            System.out.println("What person would you like to search for?");
            user_input = stdin.next();
           
            int index  = hash_table.search(user_input);
            if (index != NOT_FOUND)
                System.out.println(user_input + " is a valid famous person, found in entry " + index + ".");
            else
                System.out.println(user_input + " is not a valid famous person.");

            System.out.println("");
            System.out.println("Would you like to check another word(yes=1,no=0)?");
            try
            {
				user_input = stdin.next();

                if (Integer.parseInt(user_input) == 0)
                    break;
                else if (Integer.parseInt(user_input) != 1)
                {
                    System.out.println("Invalid input! Quitting!");
                    break;
                }
            }
            catch (Exception e)
            {
                System.out.println("Invalid input! Quitting!");
                break;
            }
        }

        System.out.println("Thank you for using the Famous People List!");
    }
}
