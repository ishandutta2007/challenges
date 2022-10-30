// Graph info

import java.util.*;

class ZombieInfo implements Comparable<ZombieInfo>, Comparator
{
    // the info for comparison
    public int    cost;
    public String p1, p2;
 
    // various constructors
    ZombieInfo()
    {
    }

    ZombieInfo(ZombieInfo z)
    {
        p1   = new String(z.p1);
        p2   = new String(z.p2);
        cost = z.cost;
    }

    ZombieInfo(String p1_, String p2_, int cost_)
    {
        p1   = new String(p1_);
        p2   = new String(p2_);
        cost = cost_;
    }

    public void set(ZombieInfo z)
    {
        p1   = new String(z.p1);
        p2   = new String(z.p2);
        cost = z.cost;
    }

    // this is for the min-heap to ensure
    // the minimum is always on top
    public int compareTo(ZombieInfo z)
    {
        int result;

        if (cost < z.cost)
            return -1;
        else if (cost > z.cost)
            return 1;
        else
        {
            result = p1.compareTo(z.p1);
            if (result != 0)
                return result;

            result = p2.compareTo(z.p2);
            if (result != 0)
                return result;
        }

        return 0;
    }

    // this is for the sorting, to make sure
    // we print out proper output
    public int compare(Object o1, Object o2)
    {
        int result;
        ZombieInfo[] z = { (ZombieInfo)o1, (ZombieInfo)o2 };
        
        // compare first field
        result = z[0].p1.compareTo(z[1].p1);
        if (result != 0)
            return result;
        
        // compare second field
        result = z[0].p2.compareTo(z[1].p2);
        if (result != 0)
            return result;
       
        // if all else fails, do it by cost
        if (z[0].cost < z[1].cost)
            return -1;

        if (z[0].cost > z[1].cost)
            return 1;

        return 0;
    }
}
