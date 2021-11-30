 /**
   * purpose: The class will sort the array ascendingly
   * 		  by using quicksort algorithm.
   * created by: Maria Litvin and Gary Litvin
   * created on: unknown
   * modified by: Kevin Jie
   * modified on: November 16th, 2018
   */
public class Quicksort
{
	// start sorting
	public static void sort(double[] a)
	{
		recursiveSort(a, 0, a.length - 1);
	}
  
	// recursive method to sort the array
	private static void recursiveSort(double[] a, int from, int to)
	{
		// base case
		if (from >= to)
		{
			return;
		}
			
    	// choose the median as the pivot location
		int p = (from + to ) / 2;

		// set and move the pointers
		int i = from;
		int j = to;
    	while (i <= j)
    	{
    		if (a[i] <= a[p])
    			i++;
    		else if (a[j] >= a[p])
    			j--;
    		else
    		{
    			// swap to make the two in correct order
    			swap (a, i, j);
    			i++;
    			j--;
    		}
    	}

    	// swap the pivot to the correct position
    	if (p < j)  
    	{
    		swap (a, j, p);
    		p = j;
    	}
    	else if (p > i)
    	{
    		swap (a, i, p);
    		p = i;
    	}

    	// divide the array and re-sort them
    	recursiveSort(a, from, p - 1);
    	recursiveSort(a, p + 1, to);
	}

	// help method to swap two elements
	private static void swap (double[] a, int i, int j)
	{
		double temp = a[i]; 
		a[i] = a[j]; 
		a[j] = temp;
	}	
}