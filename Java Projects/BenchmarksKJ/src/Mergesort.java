/**
 * purpose: The class will sort the array ascendingly
 * 			by using mergesort algorithm.
 * created by: Maria Litvin and Gary Litvin
 * created on: unknown
 * modified by: Kevin Jie
 * modified on: November 16th, 2018
 */

public class Mergesort
{
	private static double[] temp;

	// start sorting
	public static void sort(double[] a)
	{
		int n = a.length;
		temp = new double[n];
		recursiveSort(a, 0, n-1);
	}

	// Recursive method uses "divide and conquer".
	private static void recursiveSort(double[] a, int from, int to)
	{
		// base case.
		if (to - from < 2)       
		{
			if (to > from && a[to] < a[from])
			{
				// swap two elements
				double aTemp = a[to];
				a[to] = a[from]; 
				a[from] = aTemp;
			}
		}
		else                     
		{
			// "divide and conquer"
			int middle = (from + to) / 2;
			recursiveSort(a, from, middle);
			recursiveSort(a, middle + 1, to);
			merge(a, from, middle, to);
		}
	}

	// merge two arrays into one sorted array
	private static void merge(double[] a, int from, int middle, int to)
	{
		//set left, right and temporary pointers
		int i = from, j = middle + 1, k = from;

		//compare the left one to the right one
		while (i <= middle && j <= to)
		{
			if (a[i] < a[j])
			{
				temp[k] = a[i];   
				i++;
			}
			else
			{
				temp[k] = a[j];
				j++;
			}
			k++;
		}

		// copy the first half into the temp array
		while (i <= middle)
		{
			temp[k] = a[i];   
			i++;
			k++;
		}

		// copy the second half into the temp array
		while (j <= to)
		{
			temp[k] = a[j];   
			j++;
			k++;
		}

		// copy back to the original array to make it ordered
		for (k = from; k <= to; k++)
			a[k] = temp[k];
	}
}