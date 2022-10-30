// Minimum heap for use in Kruskal's algorithm

public class Heap
{
    private static final int default_size = 512;

    public ZombieInfo[] array;
    public int          size;

    // constructors
    public Heap()
    {
        setSize(default_size);
    }

    public Heap(int size)
    {
        setSize(default_size);
    }

    // for reserving memory 
    public void setSize(int size)
    {
        array = new ZombieInfo[size];
        for (int i = 0; i < array.length; i++)
            array[i] = new ZombieInfo();
        reset();
    }

    // resizing memory 
    public void resize(int size)
    {
        ZombieInfo[] temp_array = new ZombieInfo[size];

        for (int i = 0; i < array.length; i++)
            temp_array[i] = new ZombieInfo(array[i]);
        
        array = temp_array;
    }

    // get length of the array
    public int array_size()
    {
        return array.length - 1;
    }

    // reset
    public void reset()
    {
        size = 1;
    }

    // insert into min-heap
    public void insert(ZombieInfo z)
    {
        if (size == array.length)
            resize(size * 2);

        array[size].set(z);
        percolateUp(size);
        size++;
    }

    // get size
    public int size()
    {
        return size - 1;
    }

    // is empty?
    public boolean empty()
    {
        return size() == 0;
    }

    // return minimum element in the heap
    public ZombieInfo getMin()
    {
        return array[1];
    }

    // delete the minimum element, and fix the structure
    public void deleteMin()
    {
        if (size() == 0)
            return;

        array[1].set(array[--size]);
        percolateDown(1);
    }

    // for debugging
    public void printTree()
    {
        for (int i = 1; i <= size(); i++)
            System.out.println(i + ": " + array[i].p1 + " " + array[i].p2 + " " + array[i].cost);
        
        System.out.println("");
    }

    // percolating up, fixing any ordering 
    private void percolateUp(int index)
    {
        int i, k;

        for (k = index, i = index / 2; i >= 1; i /= 2)
        {
            if (array[k].compareTo(array[i]) < 0)
            {
                swap(array[i], array[k]);
                k = i;
            }
            else
                break;
        }
    }

    // percolate down, fixing any ordering
    private void percolateDown(int index)
    {
        int min, pos;

        for (pos = index * 2; pos <= size(); pos = index * 2)
        {
            min = pos;
            
            if ((pos + 1 <= size()) && (array[pos].compareTo(array[pos+1]) > 0))
                min = ++pos;
           
            if (array[index].compareTo(array[min]) > 0)
                swap(array[index], array[min]);
            else
                break;

            index = pos;
        }
    }

    private void swap(ZombieInfo z1, ZombieInfo z2)
    {
        ZombieInfo temp;

        temp = new ZombieInfo(z1);
        z1.set(z2);
        z2.set(temp);
    }
}
