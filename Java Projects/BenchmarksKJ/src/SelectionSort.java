/**
 * purpose: The class will sort the array ascendingly 
 * 			by using selection sort algorithm.
 * created by: Maria Litvin and Gary Litvin
 * created on: unknown
 * modified by: Kevin Jie
 * modified on: November 16th, 2018
 */

public class SelectionSort
{
	public static void sort(double[] a)
	{
		// Searching in backward order
		for (int n = a.length; n > 1; n--)
		{
			// Search the largest value from 
			// a[0] to current element.
			int iMax = 0;
			for (int i = 1; i < n; i++)
			{
				if (a[i] > a[iMax])
					iMax = i;
			}
			
			// Swap two elements
			double aTemp = a[iMax];
			a[iMax] = a[n-1];
			a[n-1] = aTemp;

		}
	}
}