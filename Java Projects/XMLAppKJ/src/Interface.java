/**
 * Purpose: This is the user interface class. Users can enter different numbers
 * 			to operate an xml file to achieve different functions, which are 
 * 			adding, displaying and searching data.
 * Created by Kevin Jie
 * Created on Dec 7th, 2018
 * 
 */
import java.util.Scanner;

public class Interface {
	
	private static boolean check = true;
	private static Scanner answer = new Scanner(System.in);
	
    public static void main(String[] args)
    {
    	//Create a new Information class object waiting to do options.
    	Methods a = new Methods();
    	
    	//Print prompts.
    	System.out.println("Hello. What do you want to do? (Enter a number from below)");
    	System.out.println("1. Add entries.");
    	System.out.println("2. Display data.");
    	System.out.println("3. Search data");
    	
		String choice1 = answer.nextLine();
		
		//Select choices.
		if (choice1.equals("1"))
		{
			while (check)
			{
				//Enter the data.
				System.out.println("Name?");
				Methods.setName(answer.nextLine());
				
				System.out.println("Age?"); 
				Methods.setAge(answer.nextLine());
				
				System.out.println("Sex?"); 
				Methods.setSex(answer.nextLine());
				
				System.out.println("Enter a number from below:");
				System.out.println("1. Enter another person.");
				System.out.println("2. Exit.");
				String choice5 = answer.nextLine();
				a.addPeople();//Perform adding data.
				
				if (!choice5.equals("1")) //End adding.
				{
					check = false;
				}
			}
		}
		else if (choice1.equals("2"))
		{
			a.displayPeople();//Perform displaying data.
		}
		else if (choice1.equals("3"))
		{
			//Search by a particular NAME.
			System.out.println("Please enter the person's NAME which you want to search.");
			String name = answer.nextLine();
			a.searchPeople(name);//Perform searching data.
		}
		else
		{
			System.out.println("Wrong input! Please restart and re-enter your choice!");//If not found
		}
    	
		System.out.println("You may restart to do another option.");
    }
}
