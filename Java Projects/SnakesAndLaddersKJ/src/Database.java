/**
 * Purpose: The class is a file operating class. The class has method to write
 * 			previous game data into an xml file. It also can sort the data by 
 * 			highest scores and display a list with all the data on the console.
 * Created by: Kevin Jie
 * Created on: Jan 14th, 2019
 */
import java.io.*;
import java.util.ArrayList;
import nu.xom.*;

public class Database 
{
	private static Document doc;
	private static Element root;
	private static Elements allScores;
	
	//Three arraylists will help to sort the xml data later.
	private static ArrayList<Integer> scores = new ArrayList<Integer>();
	private static ArrayList<String> names = new ArrayList<String>();
	private static ArrayList<String> round = new ArrayList<String>();


	//Write the winner's data into an xml file.
	public static void addPeople(String name, String count, String grade) 
	{
		//Hold the xml file path in a file object
		File file = new File("Result.xml");

		//If the file has created before.
		if (file.exists()) 
		{
			//Use Builder class to read the file, document data and retrieve the root element in the file.
			try 
			{
				Builder builder = new Builder(); 
				doc = builder.build(file);
				root = doc.getRootElement();
			}
			//Catch the following errors if any, then display the prompts.
			catch(IOException e)
			{
				System.out.println("Error: " + e);
			}
			
			catch(ParsingException e)
			{
				System.out.println("Error: " + e);
			}
		}
		//Create a root element if there is no previous file.
		else
		{
			root = new Element("gameResult");
			doc = new Document(root);
		}
		
		//Create necessary elements
		Element info = new Element ("information");
		Element winner = new Element("winner");
		Element round = new Element ("round");
		Element score = new Element ("score");
		    	
		//Name the elements by previous strings data
		winner.appendChild(name);
		round.appendChild(count);
		score.appendChild(grade);
		
		//Append child element to make a hierarchy
		root.appendChild(info);
		info.appendChild(winner);
		info.appendChild(round);
		info.appendChild(score);
		
		//Try use FileWritter class to append new data into the xml file.
		try 
	    {
	    	FileWriter xmlfile = new FileWriter("Result.xml");
	    	BufferedWriter writer =  new BufferedWriter(xmlfile);
	    	writer.append(doc.toXML());
	    	writer.close();
        }
		//Catch errors if any
        catch (IOException e) 
	    {
        	System.out.println("Error: " + e);
        }    		
	}
	
	
	//Display the data on the console by the highest scores order
	public static void display()
	{
    	//Create a file object of the xml file and a new builder object
		File file = new File("Result.xml");
    	Builder builder = new Builder();

    	//Try to read data from the file, retrieve all the child elements, then print them out.
    	try
    	{
    		doc = builder.build(file);
    		root = doc.getRootElement();
    		allScores = root.getChildElements();
    		
    		sort(); //Call the custom method to sort the data.
    	   
    		//Print out the data.
    		System.out.println("\nResult:");
    		for (int q = 0; q< scores.size(); q++)
    		{
  
    			System.out.println("Winner: " + names.get(q) + "\tRound: " + round.get(q) + "\tScores: " + scores.get(q));    			   
    		}
    	   
    	}	
    	//Print out prompts if any error occurs.
    	catch(IOException e)
    	{
    		System.out.println("This file does not exist.");
    	}
    	catch(ParsingException e)
    	{
    		System.out.println("This file does not exist.");
    	}
	}
	
	
	//Custom functions to sort the xml data by storing and sorting them in arraylists.
	private static void sort()
	{
		//Import data to arraylists from root elements.
		for (int j = 0 ; j < allScores.size() ; j++)
 	   	{
 		   scores.add(Integer.parseInt(allScores.get(j).getFirstChildElement("score").getValue()));
 		   names.add(allScores.get(j).getFirstChildElement("winner").getValue());
 		   round.add(allScores.get(j).getFirstChildElement("round").getValue());
 	   	}
 	   
 	   //Selection sort from the highest to the lowest scores.
 	   for (int q = scores.size()-1; q > 0; q--)
 	   {
 		   int min = q;
 		   for (int i = 0; i < q; i++)
 		   {
 			   if (scores.get(i) < scores.get(min))
 			   {
 				   min = i;
 			   }
 		   }
 		   
 		   //Change the order of scores.
 		   int temp = scores.get(min);
 		   scores.set(min, scores.get(q));
 		   scores.set(q, temp);
 		   
 		   //Change the corresponding order of winner names.
 		   String temp1 = names.get(min);
 		   names.set(min, names.get(q));
 		   names.set(q,  temp1);
 		   
 		   //Change the corresponding order of winner rounds.
 		   temp1 = round.get(min);
 		   round.set(min,  round.get(q));
 		   round.set(q,  temp1);
 	   }
	}
	
}
