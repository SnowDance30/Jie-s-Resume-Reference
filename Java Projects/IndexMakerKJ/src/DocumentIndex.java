/**
 * Purpose: Purpose: The class will create an array list that
 *  		holds all the IndexEntry objects(words and numbers), 
 *  		and organizes the objects in an alphabetical order.
 *  Author:  K. Jie
 *  Created On:  Oct 1st 2018
 */
//Import the ArrayList tool in the class.
import java.util.ArrayList;

//Extend the Arraylist class and restricts its genericity.
public class DocumentIndex extends ArrayList<IndexEntry>
{

	//Calling the super constructor method.
	public DocumentIndex()
	{
		super();
	}
	
	//Overload the super constructor method.
	public DocumentIndex(int capicity)
	{
		super(capicity);
	}

	//Add numbers to its respective word line.
	public void addWord(String word, int num)
	{
		int line = this.foundOrInserted(word);
		this.get(line).add(num);		
	}
	
	/** This help method is used to compare the words 
	 * to determine add numbers to which object of the ArrayList<IndexEntry>
	 * @param word
	 * @return index of the object in ArrayList
	 */
	private int foundOrInserted(String word)
	{
		for (int r = 0; r< this.size(); r++ )
		{
			//Compare the alphabet order to determine 
			//whether it should be inserted.
			if (word.compareToIgnoreCase(this.get(r).getWord()) <0 )
			{
				IndexEntry index = new IndexEntry(word);
				this.add(r,index);
				return r;
			//Compare if the word is the same.
			}else if (word.equalsIgnoreCase( this.get(r).getWord()) )
			{
				return r;
			}
		}
		//Add one new object if it is a new word.
		IndexEntry index = new IndexEntry(word);
		this.add(index);
		return this.size()-1;
	}
	
	/**
	 * Extract all the words from the input file,
	 * make words separate and call the methods above.
	 * @param str
	 * @param num
	 */
	public void addAllWords(String str, int num)
	{
		//Use split method to separate words.
		String[] words = str.split("\\W+");
		
		//Call addWord method to add the line numbers.
		for (String i: words)
		{
			if (!(i.equals("")))
			{
				addWord(i, num);
			}
		}
	}
}