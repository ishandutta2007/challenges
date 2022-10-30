import java.io.*;
import java.util.*;

public class DisjointSet
{
    // file to open
    static final String input_file = "sets.in";
    
    // parent and rank buffer for the disjoint set
    public int[] parent_array;
    public int[] rank_array;

    // constructor
    public DisjointSet()
    {
        // setup default array size
        parent_array = new int[512];
        rank_array   = new int[512];
    }

    // resize our set
    public void Resize(int size)
    {
        parent_array = new int[size];
        rank_array   = new int[size];
    }

    // reset up to a length
    public void ResetArray(int len)
    {
        if (len < 0)
            len = parent_array.length;

        for (int i = 0; i < len; i++)
        {
            // by default a value will be in
            // relation with itself
            parent_array[i] =  i;

            // rank is 0 on default
            rank_array[i]   =  0;
        }
    }

    // set union
    public void Union(int x, int y)
    {
        int xroot, yroot;

        // by convention, the first argument is the marker
        xroot = FindSet(x);
        yroot = FindSet(y);
       
        // if this is a subtree, we check which one is bigger

        // xroot is bigger, so we merge yroot as a subtree
        if (rank_array[xroot] > rank_array[yroot])
            parent_array[yroot] = xroot;

        // if yroot is bigger, make xroot a subtree of yroot
        else if (rank_array[xroot] < rank_array[yroot])
            parent_array[xroot] = yroot;
        
        // this is when they have the same rank, if it is a new
        // element we add it to the tree
        else if (xroot != yroot)
        {
            // use the element with least value as the marker
            if (xroot <= yroot)
            { 
                parent_array[yroot] = xroot;
                rank_array[xroot]++;
            }
            else
            {
                parent_array[xroot] = yroot;
                rank_array[yroot]++;
            }
        }
    }

    // find set and merge 
    public int FindSet(int n)
    {
        int pos, temp, 
            ret = parent_array[n];

        // first we find the root of the node
        for (pos = n; parent_array[pos] != pos; )
            ret = pos = parent_array[pos];
        
        // we go through the path to the root
        // again, but this time we set every node we hit 
        // parent to be the root of the node we found above
        for (pos = n; parent_array[pos] != pos; )
        {
            temp               = pos;
            pos                = parent_array[pos];
            parent_array[temp] = ret;
        }
        
        return ret;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner     ifp;
        DisjointSet disjoint_set = new DisjointSet();

        // open the file
        try
        {
            ifp = new Scanner(new File(input_file));
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Can't open input file " + input_file + ".");
            return;
        }
        
        // get the number of processes we need to parse
        for (int i = 0, n = ifp.nextInt(); i < n; i++)
        {
            System.out.println("Test Case #" + (i + 1) + ":");
            
            int size = ifp.nextInt();

            // resize every op
            if (size >= disjoint_set.parent_array.length)
                disjoint_set.Resize(size * 2);
            
            // every new run reset the array
            disjoint_set.ResetArray(size);

            // get the number of ops we need to parse and then do it
            for (;;)
            {
                int    arg1, arg2;
                String op, str;
              
                // get the op we are supposed to int
                str = ifp.next();
                op  = str.toLowerCase();
                
                // union operation
                if (op.compareTo("union") == 0)
                {
                    arg1 = ifp.nextInt();
                    arg2 = ifp.nextInt();
                    System.out.println("Union(" + arg1 + ", " + arg2 + ")");

                    disjoint_set.Union(arg1, arg2);
                }

                // find set
                else if (op.compareTo("findset") == 0)
                {
                    arg1 = ifp.nextInt();
                    System.out.println("Findset(" + arg1 + ") = " + disjoint_set.FindSet(arg1));
                }

                // print out the parent array
                else if (op.compareTo("print") == 0)
                {
                    System.out.println("Print");
                    
                    System.out.print("Parent array = [");
                    
                    for (int x = 0; x < size - 1; x++)
                        System.out.print(disjoint_set.parent_array[x] + ", ");
                    
                    System.out.println(disjoint_set.parent_array[size - 1] + "]");
                    
                    break;
                }
                
                // unknown op
                else
                {
                    System.out.println("Invalid operation: " + str);
                    break;
                }
            }

            System.out.println("");
        }
    }
}
