* This project is developed by me, and the theory part
is fully explaiend and cited below. *

First, make sure Python3 is available on your environment.

Second, users should install pip.

# Instruction of intalling pip for Windows Users:
1. Create a new text (.txt) file and rename it as "get-pip.txt" 
2. Open the website: https://bootstrap.pypa.io/get-pip.py 
   Copy everything (using "Ctrl + A" on keyboard) into the "get-pip.txt" file. Save it and close.
3. Rename the file again as "get-pip.py" (notice, rename it as ".py" file).
4. Right click "Windows Start Menu", left click "Run Windows Powershell as administrator".
5. Enter the path where "get-pip.py" file is stored, and enter the command: "python get-pip.py"
   Then pip is installed automatically
6. After successfully installed, users could enter "pip" in Powershell to test pip command.

Third, users should install pillow (PIL) library. PIL is a python image processing library. It is an 
    essential tool of running the file.
	
# Instruction of installing pillow (PIL) library
1. Right click "Windows Start Menu", left click "Run Windows Powershell as administrator".
2. Enter "pip install --upgrade pip"
3. Enter "pip install pillow"
Then pillow library is successfully installed on your computer.


Lab Theory Part:
Character painting is a combination of a series of characters. We can regard characters as relatively
    large pixels. A character can represent a color (it can be understood in order to simplify). 
	The more types of characters, the more colors can be represented, and the picture will have a more 
	hierarchical sense.

Brief introduction of Grayscale:
Grayscale: refers to the color depth of the midpoint of the black-and-white image, which generally 
    ranges from 0 to 255. White is 255 and black is 0. Therefore, the black-and-white image is also
	called gray image. （Reference: https://en.wikipedia.org/wiki/Grayscale)

Brief introduction of RGB color model:
RGB color mode is a color standard in the industry. It obtains various colors through the changes 
    of red (R), green (g) and blue (b) color channels and their superposition. RGB represents the 
	colors of red, green and blue channels. This standard includes almost all colors that can be 
	perceived by human vision, It is one of the most widely used color systems at present.
	(Reference: https://en.wikipedia.org/wiki/RGB_color_model)

We can use the grayscale formula to map the RGB value of pixels to the gray value (note that this
    formula is not a real algorithm, but a simplified "sRGB iec61966-2.1" formula. The real formula 
	is more complex, but it is not necessary in our application scenario):
		# gray ＝ 0.2126 * r + 0.7152 * g + 0.0722 * b
	In this way, we can create a non repetitive character list. The symbols at the beginning of the 
	list are used for those with small gray value (dark), and the symbols at the end of the list are 
	used for those with large gray value (light).
	(Reference: https://en.wikipedia.org/wiki/Grayscale 
	(Colorimetric (perceptual luminance-preserving) conversion to grayscale)
