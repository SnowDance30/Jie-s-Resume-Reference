/**
 * Purpose: This class contains 3 main methods which can perform adding, displaying
 * 			and searching data in an xml file, and 3 help methods which receive 
 * 			the entered texts from the console.
 * Created by Kevin Jie
 * Created on Dec 7th, 2018
 * 
 */
import nu.xom.*;
import java.io.*;
	
public class Methods {

	private static String txtName;
	private static String txtAge;
	private static String txtSex;
	private Document doc;
	private Element root;
	private Elements allPeople;
	
	//The method sets the name string.
	public static void setName(String name)
	{
		txtName = name;
	}

	//The method sets the age string.
	public static void setAge(String age)
	{
		txtAge = age;
	}

	//The method sets the sex string.
	public static void setSex(String sex)
	{
		txtSex = sex;
	}
	
	//The method appends data into a .xml file.
	public void addPeople()
	{
		//Create a new File object which has the path of the target xml file.
		File file = new File("PeopleInfo.xml");
    	
    	if (file.exists()) //If the file has created before
    	{
    		//Use Builder class to read the file, document it and find the root element in the file.
    		try 
    		{
    			Builder builder = new Builder(); 
    			doc = builder.build(file);
    			root = doc.getRootElement();
    		}
    		//Catch the following errors if any, then display the prompt.
    		catch(IOException e)
    		{
    			System.out.println("Error: " + e);
    		}

    		catch(ParsingException e)
    		{
    			System.out.println("Error: " + e);
    		}
    	}
    	//If there is no file created before, create a new root and a new document.
    	else
    	{
    		root = new Element("peopleInfo");
    		doc = new Document(root);
    	}
    	
	    //Creates all the elements needed.
		Element people = new Element("people");
		Element name = new Element("name");
	    Element age = new Element("age");
	    Element sex = new Element("sex");

	    //Assign the values to the elements.
	    name.appendChild(txtName);
	    age.appendChild(txtAge);
	    sex.appendChild(txtSex);

	    //Construct the xml format by determining grandparent element, 
	    //parent element and sub-element.
	    root.appendChild(people);;
	    people.appendChild(name);
	    people.appendChild(age);
        people.appendChild(sex);
	      
	    //Append new data into the target .xml file.
	    try 
	    {
	    	FileWriter xmlfile = new FileWriter("PeopleInfo.xml");
	    	BufferedWriter writer =  new BufferedWriter(xmlfile);
	    	writer.append(doc.toXML());
	    	writer.close();
        }
        catch (IOException e) 
	    {
        }
	}
	
	//The method will display a list of all the data stored in the target .xml file.
    public void displayPeople() 
    {                                        
		//Declare a new File and Builder object 
		File file = new File("PeopleInfo.xml");
    	Builder builder = new Builder();
    	
    	//Try the following lines and catch the following expected errors
    	try
    	{
    		//Retrieve the information in the existing XML into the document object
    		doc = builder.build(file);
    		root = doc.getRootElement();
    		
            //Formats and outputs the XML.
	        Serializer serializer = new Serializer(System.out);
	    	serializer.setIndent(4);
	    	serializer.setMaxLength(64);
	    	serializer.write(doc);
    	}
    	//Print the following error messages when the expected error occurs.
    	catch(IOException e)
    	{
    		System.out.println("This file does not exist.");
    	}

    	catch(ParsingException e)
    	{
    		System.out.println("This file does not exist.");
    	}
    }
    
    //This method will search the NAME of a target item in an xml file and 
    //tell the user whether it is in the content.
    public void searchPeople(String item)
    {
    	//Declare a new File and Builder object 
		File file = new File("PeopleInfo.xml");
    	Builder builder = new Builder();

    	//Try to proceed the lines and catch expected errors
    	try
    	{
    		//Read data in the file, document it, find 
    		//the root elements and all the child elements.
    		doc = builder.build(file);
    		root = doc.getRootElement();
    		allPeople = root.getChildElements();
    		
    	   //Match through all the data.
    	   for (int j = 0 ; j < allPeople.size() ; j++)
    	   {
    		   //If find the name of an data.
    		   if(allPeople.get(j).getFirstChildElement("name").getValue().equalsIgnoreCase(item))
    		   {
    			   //Print the result.
    			   System.out.println("Search result:");
    			   System.out.println("Name: " + allPeople.get(j).getFirstChildElement("name").getValue());
    			   System.out.println("Age: " + allPeople.get(j).getFirstChildElement("age").getValue());
    			   System.out.println("Sex: " + allPeople.get(j).getFirstChildElement("sex").getValue());
    			   return;
    		   }
    	   }
    	   
    	   //If not found.
    	   System.out.println("No match found.");	
    	}
    	//Print the following error messages when the expected error occurs.
    	catch(IOException e)
    	{
    		System.out.println("This file does not exist.");
    	}
    	catch(ParsingException e)
    	{
    		System.out.println("This file does not exist.");
    	}
    }

}
