/**
 * Purpose: This class constructs the main body of the game. It has a 
 * 			method to make players act by turns. It describes how players
 * 			will move, how to count scores and how to end the game properly.
 * 			It also has a recurrsion method help to count the bonus scores.
 * Created by: Kevin Jie
 * Created on: Jan 14th, 2019
 */
import java.util.Scanner;

public class MainGame 
{
	private static Scanner answer = new Scanner(System.in);
	private static String key;
	private static boolean check1 = true;
	private static boolean check2 = false;
	private static int dice;
	private static int countTurn = 0;
	
	//player1 information
	public static int p1_Loc = 0;
	public static String p1_Name;
	public static int p1_Scor = 0;
	
	//player2 information
	public static String p2_Name;
	public static int p2_Loc = 0;
	public static int p2_Scor = 0;
	
	
	//The core method controls which player's turn, rolling the dice, moving and scoring
	public static void play() 
	{
		//Create a set of temporary copies which will hold player's information
		String temp_Name = "";
		int temp_Loc = 0;
		int temp_Scor = 0;
		
		//The round will continue going until one player wins
		while (true) 
		{
			countTurn += 1;		//Start and count one new round
			switch(countTurn % 2)	//Determine the current turn is odd or even
			{
				//If even, it is player2's turn, pass the values to the temporary copies
				case 0:
					temp_Name = p2_Name;
					temp_Loc = p2_Loc;
					temp_Scor = p2_Scor;
					break;
				
				//If even, it is player2's turn, pass the values to the temporary copies
				case 1:
					temp_Name = p1_Name;
					temp_Loc = p1_Loc;
					temp_Scor = p1_Scor;
					break;
			}

			System.out.println("\n");
			
			//print current round number (not the turn number)
			if (countTurn % 2 == 1)
			{
				System.out.println("Round " + (countTurn/2+1) + ":");
			}
			
			//press 'p' to roll the dice
			while (check1) 
			{
				System.out.println("\t" + temp_Name + ", it's your turn! Press \"p\" to roll the dice!");
				key = answer.nextLine();
				if (key.equalsIgnoreCase("p"))
				{
					check1 = false;
				}
			}
			
			check1 = true;	//Edit the boolean condition to ture 
			
			//Use built-in Math.random method to generate a number between 1 to 6
			dice = (int) (Math.random() * 6);	
			if (dice == 0) 
			{
				dice = 6;
			}
			
			//If player will land before 100
			if((temp_Loc + dice) < 100)
			{
				temp_Loc += dice;	//Move to the new location normally.
				System.out.println("	Your dice is " + dice + ", your current location is AT " + temp_Loc + ".");
				temp_Loc = GameBoard.placeCheck(temp_Loc);	//Check the tile whether it is special
				temp_Scor = GameBoard.addScores(temp_Scor);	//Check whether should change the score
			}
			//If player will land at 100
			else if ((temp_Loc + dice) == 100)
			{
				temp_Loc += dice;	//Move to the new location
				System.out.println("	Your dice is " + dice + ", your current location is AT " + temp_Loc + ".");
				temp_Scor += 50;	//Gain 50 pts.
				check2 = true;	//Activate end game code
			}
			//if player will land beyond 100
			else 
			{
				temp_Loc = 100 - (temp_Loc + dice - 100);	//Bounce back to a new location
				System.out.println("	Your dice is " + dice + ", you wont't arrive at 100, so you bounce back to " + temp_Loc + ".");
				temp_Loc = GameBoard.placeCheck(temp_Loc);	//Check the tile whether it is special
				temp_Scor = GameBoard.addScores(temp_Scor);//Check whether should change the score
			}
			
			//Determine it is which player's round, then pass the temporary values back to the original variables
			switch(countTurn % 2)
			{			
				case 0:
					p2_Loc = temp_Loc;
					p2_Scor = temp_Scor;
					break;
					
				case 1:
					p1_Loc = temp_Loc;
					p1_Scor = temp_Scor;
					break;
			}
			
			//If one player lands at 100
			if(check2 == true)
			{
				bonusAdd(countTurn);	//Add bonus-round scores to each player
				System.out.println("\n\nGame Over.");
				System.out.println("Congratulation! " + temp_Name + ", you are the WINNER!!! Get 50 pts!\n");	
				System.out.println(p1_Name + ": Your socre is " + p1_Scor + ".");
				System.out.println(p2_Name + ": Your socre is " + p2_Scor + "."); 
				
				//Use built-in String class method to convert winner's round and scores to strings
				String round = String.valueOf(countTurn/2+1);
				String grade = String.valueOf(p1_Scor);
				if(p1_Scor < p2_Scor)	//Determine winner's scores
				{	
					grade = String.valueOf(p2_Scor);
				}
				
				//Use the strings to write winner's information into an xml file.
				Database.addPeople(temp_Name, round ,grade);
				
				//Finish the method
				return;
			}
		}
	}
	
	
	//A custom reccursive function to count bonus-round scores
	private static void bonusAdd(int count)
	{
		//Base case, if less than 10 turns
		if (count / 10 == 0)
		{
			return;
		}
		//Each player will get 10 bonus scores if the number of turns is more than 10
		else 
		{
			p1_Scor += 10;
			p2_Scor += 10;
			bonusAdd(count - 10);
		}
	}

}
