// Disjoint set for use in Kruskal's algorithm

import java.io.*;
import java.util.*;

public class DisjointSet
{
    // default constants
    private static final int default_size = 512;
    
    // parent and rank buffer for the disjoint set
    public int[] parent_array;
    public int[] rank_array;

    // constructor
    public DisjointSet()
    {
        setSize(default_size);
    }

    public DisjointSet(int size)
    {
        setSize(size);
    }

    public void setSize(int size)
    {
        parent_array = new int[size];
        rank_array   = new int[size];
        reset();
    }

    public int size()
    {
        return parent_array.length;
    }

    // reset up to a length
    public void reset()
    {
        for (int i = 0; i < parent_array.length; i++)
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
}
