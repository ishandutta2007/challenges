// Flight Planner for cities that finds connectivity using Floyd-Warshall algorithm

import java.util.*;
import java.io.*;

public class FlightPlanner
{
    // file to open
    private static final String input_file   = "flights.in";
    
    // default size
    private static final int    default_size =  512;

    public static void main(String[] args)
    {
        int      test_cases, num_cities;
        Scanner  ifp;

        // the data
        String[] cities; 
        int[][]  adj_mat;

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

        cities  = new String [default_size];
        adj_mat = new int    [default_size][default_size];

        // get number of test cases
        test_cases = ifp.nextInt();
        
        for (int i = 0; i < test_cases; i++)
        {
            System.out.println("Test Case #" + (i + 1) + ":");

            // get the number of cities
            num_cities = ifp.nextInt();
            
            // resize if necessary
            if (num_cities > cities.length)
            {
                cities  = new String [num_cities * 2];
                adj_mat = new int    [num_cities * 2][num_cities * 2];
            }

            // get the cities name
            for (int k = 0; k < num_cities; k++)
                cities[k] = new String(ifp.next());
        
            // get the adjacency matrix
            for (int k = 0; k < num_cities; k++)
                for (int j = 0; j < num_cities; j++)
                    adj_mat[j][k] = ifp.nextInt();

            // then set the diagonal to 1s rather than 0
            // as in input, treat cities as being able
            // to connect to themselves,
            // makes it easier to check for closure later
            for (int k = 0; k < num_cities; k++)
                adj_mat[k][k] = 1;

            // use floyd-warshall to get the connectivity
            for (int k = 0; k < num_cities; k++)
                for (int l = 0; l < num_cities; l++)
                    for (int j = 0; j < num_cities; j++)
                        adj_mat[l][j] = adj_mat[l][j] | (adj_mat[l][k] & adj_mat[k][j]);
         
            // print out the results
            System.out.print("The cities that CAN REACH all other cities are: ");

            boolean closure;
           
            // if the city rows are all 1, then the city can go to all other cities
            for (int k = 0; k < num_cities; k++)
            {
                closure = true;

                for (int j = 0; j < num_cities; j++)
                {
                    if (adj_mat[j][k] == 0)
                    {
                        closure = false;
                        break;
                    }
                }

                if (closure)
                    System.out.print(" " + cities[k]);
            }

            System.out.println("");

            System.out.print("The cities that CAN BE REACHED by all other cities are: ");
            
            // if the city columns are all 1, then the city can be reached by all other cities 
            for (int k = 0; k < num_cities; k++)
            {
                closure = true;
                
                for (int j = 0; j < num_cities; j++)
                {
                    if (adj_mat[k][j] == 0)
                    {
                        closure = false;
                        break;
                    }
                }

                if (closure)
                    System.out.print(" " + cities[k]);
            }
            
            System.out.println("");
            
            System.out.println("");
        }

        // cleanup
        ifp.close();
    }
}
