// Find and rescue survivors using Kruskal's algorithm

import java.io.*;
import java.util.*;

public class Zombie
{
    private static final String input_file = "zombie.in";
    
    public static void main(String[] args)
    {
        // default constants
        int default_size = 1024;
        
        // stuff for storing the input
        ZombieInfo   zombie_info;
        
        // for outputting the paths
        ZombieInfo[] zombie_array;
        
        // disjoint set and heap for kruskal's algorithm
        DisjointSet disjoint_set;
        Heap        minheap;
        
        // use a hash table to uniquely map the names to a key for
        // the disjoint set and for quick lookup
        Hashtable hash_table; 

        // input 
        String      p1, p2;
        int         test_case, nroutes, noccupied, npath, 
                    min_cost,  cost, ident;
        Scanner     ifp;

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

        // init the data structures
        zombie_array = new ZombieInfo[default_size];
        hash_table   = new Hashtable(default_size);
        minheap      = new Heap(default_size);
        disjoint_set = new DisjointSet(default_size);

        // get number of cases
        test_case = ifp.nextInt();

        for (int i = 0; i < test_case; i++)
        {
            // get the routes, and non occupied
            nroutes   = ifp.nextInt();
            noccupied = ifp.nextInt();
           
            // resize if needed
            if ((nroutes * 2) > minheap.array_size())
            {
                minheap.setSize(nroutes * 2);
                disjoint_set.setSize(nroutes * 2);
                zombie_array = new ZombieInfo[nroutes * 2];
            }
            else
            {
                minheap.reset();
                disjoint_set.reset();
            }

            // insert all the edges into a heap first,
            // so we can get the minimum edges easily
            hash_table.clear();
            ident = 0;

            for (int k = 0; k < nroutes; k++)
            {
                p1   = ifp.next();
                p2   = ifp.next();
                if (p1.compareTo(p2) > 0)
                {
                    String tempstr = p1;
                    p1 = p2;
                    p2 = tempstr;
                }

                cost = (k < noccupied) ? ifp.nextInt() : 0;
                
                // hash these so we can easily insert
                // into disjoint set later
                if (!hash_table.containsKey(p1))
                {
                    hash_table.put(p1, new Integer(ident));
                    ident++;
                }
                if (!hash_table.containsKey(p2))
                {
                    hash_table.put(p2, new Integer(ident));
                    ident++;
                }

                // insert into heap
                zombie_info = new ZombieInfo(p1, p2, cost);
                minheap.insert(zombie_info);
            }

            // then remove the minimum edge one by one 
            for (npath = min_cost = 0; !minheap.empty(); minheap.deleteMin())
            {
                int[] marker = { 0, 0 };
                zombie_info = new ZombieInfo(minheap.getMin());
                
                marker[0]   = ((Integer) hash_table.get(zombie_info.p1)).intValue();
                marker[1]   = ((Integer) hash_table.get(zombie_info.p2)).intValue();
               
                // then we see if the edge removed is connecting vertices already
                // connected
                marker[0]   = disjoint_set.FindSet(marker[0]);
                marker[1]   = disjoint_set.FindSet(marker[1]);

                if (marker[0] != marker[1])
                {
                    // if it is not, connect it
                    disjoint_set.Union(marker[0], marker[1]);
                    min_cost += zombie_info.cost;

                    zombie_array[npath++] = zombie_info;
                }
            }

            Arrays.sort((Object[]) zombie_array, 0, npath, (Comparator)new ZombieInfo());
            System.out.println("The minimum zombie encounters of the rescue effort are " + min_cost + ".");
            for (int j = 0; j < npath; j++)
            {
                System.out.println(zombie_array[j].p1 + " " + zombie_array[j].p2 + " " + 
                        ((zombie_array[j].cost != 0) ? zombie_array[j].cost : ""));

            }
            System.out.println("");
        }

        // cleanup
        ifp.close();
    }
}
