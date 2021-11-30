/**
 * purpose: The class is the main class contains GUI interface.
 * 			It runs the chosen method, records the result data
 * 			and displays it on the console.
 * created by: Maria Litvin and Gary Litvin
 * created on: unknown
 * modified by: Kevin Jie
 * modified on: November 16th, 2018
 */

import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JComboBox;
import java.util.Random;
import java.util.Arrays;

public class Benchmarks extends JFrame
{
	private static int numberOfRuns = 20;

	private JTextField arraySizeInput, display;
	private String sortMethodNames[] =
		{"Selection Sort", "Insertion Sort", "Mergesort", "Quicksort"};
	private JComboBox<String> chooseSortMethod;

	private final long seed;
	private int arraySize;

	// Constructor initializes fields and the seed.
	public Benchmarks()
	{
		super("Benchmarks");

		Container c = getContentPane();
		c.setLayout(new GridLayout(6, 1));

		c.add(new JLabel(" Array size: "));
		arraySizeInput = new JTextField(4);
		arraySizeInput.setText("1000");
		arraySizeInput.selectAll();
		c.add(arraySizeInput);

		chooseSortMethod = new JComboBox<String>(sortMethodNames);
		
		c.add(chooseSortMethod);

		JButton run = new JButton("Run");
		run.addActionListener(new RunButtonListener());
		c.add(run);

		c.add(new JLabel(" Avg Time (milliseconds): "));

		display = new JTextField("   Ready");
		display.setBackground(Color.YELLOW);
		display.setEditable(false);
		c.add(display);

		// set a seed to use the same random
		// generator while running the program
		seed = System.currentTimeMillis();
	}

	// fill the array with random numbers and use the
	// chosen sort method, return the total sort time
	private long runSort(double[] a, int sortMethod, int numberOfRuns)
	{
		// create a Random object with the assigned seed
		Random generator = new Random(seed);
	  
		long totalTime = 0;
		long startTime;
		long endTime;
		
		for (int r = 0; r < numberOfRuns; r++)  
		{
			// fill the array with random numbers
			for (int i = 0; i < a.length; i++)  
			{
				a[i] = generator.nextDouble();
			}
		
			startTime = System.currentTimeMillis();
		
			// select the chosen method
			if (sortMethod == 1)
			{
				SelectionSort.sort(a);
			}
			else if (sortMethod == 2)
			{
				InsertionSort.sort(a);
			}
			else if (sortMethod == 3)
			{
				Mergesort.sort(a);
			}
			else
			{
				Quicksort.sort(a);
			}
	
			endTime = System.currentTimeMillis();
			// add time after a run
			totalTime += (endTime - startTime);
		}
    
		return totalTime;
    
	}

	// the action class of clicking the button
	private class RunButtonListener implements ActionListener
	{
		// display necessary texts
		public void actionPerformed(ActionEvent e)
		{
			String inputStr = arraySizeInput.getText().trim();
			try
			{
				arraySize = Integer.parseInt(inputStr);
			}
			catch (NumberFormatException ex)
			{
				display.setText(" Invalid array size");
				arraySize = 0;
				return;
			}

			if (arraySize <= 0)
			{
				display.setText(" Invalid array size");
				return;
			}

			if (arraySize <= 0)
			{
				return;
			}

			//prepare to execute runSort 
			int sortMethod = chooseSortMethod.getSelectedIndex() + 1;
			double a[] = new double[arraySize];
			//calculate the average time for one run
			double avgTime = (double)runSort(a, sortMethod, numberOfRuns)
                                                          / numberOfRuns;
			display.setText(String.format("  %.2f", avgTime));

			arraySizeInput.selectAll();
			arraySizeInput.requestFocus();
			System.out.println("Array size = " + arraySize +
					" Runs = " + numberOfRuns + " " +
					sortMethodNames[sortMethod - 1] + " avg time: " + avgTime);

		}
	}

	// main method
	public static void main(String[] args)
	{
		// run 20 times
		numberOfRuns = 20;
		if (args.length > 0)
		{
			int n = -1;
			try
			{
				n = Integer.parseInt(args[0].trim());
			}
			catch (NumberFormatException ex)
			{
				System.out.println("Invalid command-line parameter");
				System.exit(1);
			}
			if (n > 0)
				numberOfRuns = n;
		}

		Benchmarks window = new Benchmarks();
		window.setBounds(300, 300, 180, 200);
		window.setDefaultCloseOperation(EXIT_ON_CLOSE);
		window.setVisible(true);
	}
}