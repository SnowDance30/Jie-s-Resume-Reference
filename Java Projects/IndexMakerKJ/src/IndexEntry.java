/**
 *  Purpose: The class creates each word index which is a line 
 *  		 with its word and the respective line numbers, and
 *  		 creates methods to store words and numbers.
 *  Author:  K. Jie
 *  Created On:  Oct 1st 2018
 */

//Import the ArrayList tool in the class.
import java.util.ArrayList;

public class IndexEntry 
{

	private String word;
	private ArrayList<Integer> numsList;
	
	//The constructor will assign the value to
	//'word' property and make a new arraylist .
	public IndexEntry(String word)
	{
		this.word = word.toUpperCase();
		numsList = new ArrayList<Integer>();		
	}
	
	/**Add the line numbers into the numsList if 
	 * not included yet.
	 * @param num
	 */
	public void add(int num)
	{
		
		if (!(numsList.contains(num))) 
		{
			numsList.add(num);
		}
		
	}
	

	//Return 'word' value.
	public String getWord()
	{
		return this.word;
	}
	
	//Overrides toString methods
	//and prints the line with the format provided.
	public String toString()
	{
		//Make all the numbers in a String.
		String container = "";
		for (int r =0; r< numsList.size();r++ )
		{
			if (r== numsList.size()-1)
			{
				container+= numsList.get(r);
			}else
			{
				container+= numsList.get(r)+", ";
			}
		}
		return word+" "+ container;
		
	}
	
}