#!/usr/bin/env python
"""
@author: Kevin Jie
@desc: Please read "README.txt" first. All details are fully writen
       in the file, incluing pre-environment installment and cited
       theory part.
        
       The module achieves tranfering a colour/while-black image
       into a text file form, which looks like the original image
       if you zoom it out in your browzer or text editor. 
       
       ps. My text editor is NotePad++ and it is every effective.
@date: 2020/8/26
"""

from PIL import Image
import argparse

# Command line processing parameters
parser = argparse.ArgumentParser()

parser.add_argument('file')     # Input file
parser.add_argument('-o', '--output')   # Output file
parser.add_argument('--width', type = int, default = 80)   # Output width of the image
parser.add_argument('--height', type = int, default = 80)  # Output length of the image

# Get arguments
args = parser.parse_args()

# Global constants
IMG = args.file
OUTPUT = args.output
WIDTH = args.width
HEIGHT = args.height


# This is a list of characters used to create an image. The number of 
#   characters and the order of characters could be changed to 
#   explore different output image.
CHARS = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ")


def get_char(r, g, b, theta = 256):
    """
    @desc: get_char(r, g, b, theta) maps grayscale onto the CHARS list.
    @param: int: r 
            int: g
            int: b
            int: theta, default value = 256
    @return: int
    """

    # 0 means white positions on the image
    if theta == 0:
        return ' '
        
    length = len(CHARS)
    
    # Translate RGB value to grayscale, the range of grayscale is [0, 255], use the formula
    gray_value = int(0.2126 * r + 0.7152 * g + 0.0722 * b)

    unit = (256.0 + 1)/length
    return CHARS[int(gray_value/unit)]


if __name__ == '__main__':

    file = Image.open(IMG)
    file = file.resize((WIDTH,HEIGHT), Image.NEAREST)

    result = ""

    for i in range(HEIGHT):
        for j in range(WIDTH):
            result += get_char(*file.getpixel((j,i)))
        result += '\n'

    print(result)
    
    # Write charters to files
    if OUTPUT:
        with open(OUTPUT,'w') as f:
            f.write(result)
    else:
        with open("output.txt",'w') as f:
            f.write(result)