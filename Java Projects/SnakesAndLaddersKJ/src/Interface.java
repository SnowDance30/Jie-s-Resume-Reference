/**
 * Purpose: This class is user interface. Most of the prompts are here to guide
 * 			users how to use the program(play the game). A built-in instruction
 * 			is written in this class. The class will call other methods to start 
 * 			the game. 
 * Created by: Kevin Jie
 * Created on: Jan 14th, 2019
 */
import java.util.Scanner;

public class Interface
{
	private static Scanner answer = new Scanner(System.in);
	private static String key;
	private static boolean check = true;	
	
	
	//Print a briefly and clear instruction to the users.
	private static void instruction()
	{
		System.out.println("Welcome to Snakes and Ladders game!");
		System.out.println("In this game, two players will versus each other, and one will become the winner!\n");
		System.out.println("Quick Instruction of the game:");
		System.out.println("The board has 100 tiles in total, and two players will both start at the 0th tile.");
		System.out.println("***The player who reaches EXACT 100th tile first will WIN the game!***");
		System.out.println("In this game, the 1ST PLAYER will ALWAYS roll the dice FIRST!");
		System.out.println("Each player will take turns to roll the dice (press \"p\") to advance between 1 and 6.");
		System.out.println("If players lands on a head of a snake, they will go back to the tile containning the tail of the sanke.");
		System.out.println("If players lands on a bottom of a ladder, they will climb up to the tile containning the top of the ladder.");
		System.out.println("If players will land over 100th tile, he/she will bounce back.\n");
		System.out.println("Scoring:");
		System.out.println("1. Climb a ladder: +10 points	2. Step a snake's head: -5 points	3. Arrive at 100th: +50 points");
		System.out.println("4. At the END of every 5th round, each play will get 10 points.\n");
		
		//Start the game by press 'y'.
		char temp = 'y';
		while(check)
		{
			System.out.println("If you finish reading the instruction, press \"y\" to start your game.");
			key = answer.nextLine();
			if (key.charAt(0) == temp)
			{
				check = false;
			}
		}
		System.out.println("\nGame starts! Have fun!\n");
		
		//Get players' name.
		System.out.println("Please enter 1st player's name:");
		MainGame.p1_Name = answer.nextLine();
		System.out.println("Please enter 2nd player's name:");
		MainGame.p2_Name = answer.nextLine();
		
		System.out.println();
	}
	
	
	//Custom function to display previous results.
	public static void displaySort()
	{
		while(true)
		{
			System.out.println("Do you want to see the precvious result? Press \"y\"(yes) or \"n\"(no).");
			key = answer.nextLine();
			char temp1 = 'y';
			char temp2 = 'n';
			//Display the data.
			if(key.charAt(0) == temp1)
			{
				Database.display();
				break;
			}
			//End the method
			else if(key.charAt(0) == temp2)
			{
				return;
			}
		}
	}
	
	
	//Main method.
	public static void main(String[] args)
	{
		instruction();
		MainGame.play();
		displaySort();
		System.out.println("\nYou may restart the game to play a new game.");
	}
	

}
