/**
 * purpose: The class will sort the array ascendingly
 * 			by using insertion sort algorithm.
 * created by: Maria Litvin and Gary Litvin
 * created on: unknown
 * modified by: Kevin Jie
 * modified on: November 16th, 2018
 */

public class InsertionSort
{
	public static void sort(double[] a)
	{
		for (int n = 1; n < a.length; n++)
		{
			double aTemp = a[n];

			// Shift elements to one right until the saved
			// element is greater than the current element.
			int i = n;
			while (i > 0 && aTemp < a[i-1])
			{
				a[i] = a[i-1];
				i--;
			}
			
			// Insert the saved element.
			a[i] = aTemp;
		}
	}
}