/**
 * Purpose: This class constructs an abstract game board for the game.
 * 			It sets the locations of ladders and snakes. It also has 
 * 			methods to detect whether players are standing on a special
 * 			tile (a bottom of a ladder or a head of a snake), then add or
 * 			decrease the scores.
 * Created by: Kevin Jie
 * Created on: Jan 14th, 2019
 */
public class GameBoard 
{
	//Store special tiles information in arrays
	private static int[] heads = {25, 34, 47, 65, 87, 91, 99};
	private static int[] tails = {5, 1, 19, 52, 57, 61, 69};
	private static int[] tops = {27, 51, 55, 70, 95, 98};
	private static int[] bots = {6, 3, 36, 20, 63, 68};
	
	private static boolean l_Check;
	private static boolean s_Check;
	
	
	//The method will detect whether there needs a move at current tile, return the new location back.
	public static int placeCheck(int place)
	{
		l_Check = false;
		s_Check = false;
		
		//Check ladder by linear search, if qualified, return the new location and skip the snake check.
		for(int q = 0; q < bots.length; q++)
		{
			//Move the player up to a new location.
			if (place == bots[q])
			{
				place = tops[q];
				System.out.println("	Lucky! You find a ladder! You climbed to " +  tops[q] + " tile now!");
				l_Check = true;	// Activate ladder boolean check
				return place;
			}
		}
		
		//Check snake by linear search
		for(int q = 0; q< heads.length; q++)
		{
			//Move the player down to a new location.
			if (place == heads[q])
			{
				place = tails[q];
				System.out.println("	Sad! You step on a snake head! You fell to " +  tails[q] + " tile now!");
				s_Check = true;	//Activate snake boolean check
				return place;
			}
		}
		
		//If the tile is not special, return the original location.
		return place;
	}
	
	
	//Add or reduce scores by stepping on a ladder or a snake.
	public static int addScores(int scores)
	{
		if (l_Check == true)	//If step on a ladder, add scores
		{
			scores += 10;
		}
		else if(s_Check == true)	//If step on a snake head, reduce scores
		{
			scores -= 5; 
		}
		return scores;
	}
	
}
