/**
 *  Purpose: The program will read an input file, loading all the information 
 * 			 inside it, output the words with its respective indices
 *  		 in another output file.
 *  		 from the command-line args or prompts the user for the file names.
 *  Author: Maria Litvin and Gary Litvin
 *  Create on: Unknown
 *  Modified by: K. Jie
 *  Modified on: Oct 1st 2018
 */

//Import FileReader package to in order to use its codes.
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

public class IndexMaker
{
  public static void main(String[] args) throws IOException
  {
	  //Initialize Scanner.
    Scanner keyboard = new Scanner(System.in);
    String fileName;

    // Open input file and enter the 
    // receive the filename from keyboard.
    if (args.length > 0)
      fileName = args[0];
    else
    {
      System.out.print("\nEnter input file name: ");
      fileName = keyboard.nextLine().trim();
    }

    BufferedReader inputFile =
                 new BufferedReader(new FileReader(fileName), 1024);

    // Create output file and 
    // receive the filename from keyboard.

    if (args.length > 1)
      fileName = args[1];
    else
    {
      System.out.print("\nEnter output file name: ");
      fileName = keyboard.nextLine().trim();
    }

    PrintWriter outputFile =
                 new PrintWriter(new FileWriter(fileName));

    // Make a new object of the DocumentIndex
    //class and running the creating index process.

    DocumentIndex index = new DocumentIndex();

    String line;
    int lineNum = 0;
    while ((line = inputFile.readLine()) != null)
    {
      lineNum++;
      index.addAllWords(line, lineNum);
    }

    // Save the information in the output file.

    for (IndexEntry entry : index)
      outputFile.println(entry);

    // Close the files and the tools.

    inputFile.close();
    outputFile.close();

    keyboard.close();
    System.out.println("Done.");
  }
}