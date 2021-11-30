#!/usr/bin/env python
"""
@author Kevin Jie
@desc The module implements the Snake game by pygame module.
      The module uses objected-oriented programming design.
@date 2020/8/18
"""

import pygame, sys, random
from pygame.locals import *

# define global constants for colour values
RED = (255, 0, 0)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
SCREEN_SIZE = [640, 480]


def main():
    pygame.init()
    fps_clock = pygame.time.Clock()  # speed variable
    playsurface = pygame.display.set_mode(SCREEN_SIZE)  # screen size
    pygame.display.set_caption('SNAKE')  # header

    snake_position = [150, 150]  # initial position
    snake_body = [[150, 150], [130, 100], [110, 100]]  # number of elements in the body means the length
    target_position = [300, 300]  # initial target position
    targetflag = 1
    direction = 'left'     # initial direction
    change_direction = direction
    
    while True:

        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                if event.key == K_RIGHT:  # right-arrow key
                    change_direction = 'right'
                if event.key == K_LEFT:   # left-arrow key
                    change_direction = 'left'
                if event.key == K_UP:     # up-arrow key
                    change_direction = 'up'
                if event.key == K_DOWN:   # down-arrow key
                    change_direction = 'down'
                if event.key == K_ESCAPE:
                    pygame.event.post(pygame.event.Event(QUIT))


        if change_direction == 'left' and not direction == 'right':
            direction = change_direction
        if change_direction == 'right' and not direction == 'left':
            direction = change_direction
        if change_direction == 'up' and not direction == 'down':
            direction = change_direction
        if change_direction == 'down' and not direction == 'up':
            direction = change_direction


        if direction == 'right':
            snake_position[0] += 10
        if direction == 'left':
            snake_position[0] -= 10
        if direction == 'up':
            snake_position[1] -= 10
        if direction == 'down':
            snake_position[1] += 10
        # increase the length of the body of Snake
        snake_body.insert(0, list(snake_position))
        # reach the target position
        if snake_position[0] == target_position[0] and snake_position[1] == target_position[1]:
            targetflag = 0
        else:
            snake_body.pop()
        if targetflag == 0:
            x = random.randrange(1, 32)
            y = random.randrange(1, 24)
            target_position = [int(x * 10), int(y * 10)]
            targetflag = 1
        # Fill background colour
        playsurface.fill(BLACK)
        # Draw the snake body
        for position in snake_body:
            # first param: serface: specify an area
            # second param: colour: choose a colour
            # third param: rect: return a rectangle (xy),(width,height)
            # fourth param：width：represent the thickness of the line
            pygame.draw.rect(playsurface, RED, Rect(position[0], position[1], 10, 10))
            pygame.draw.rect(playsurface, WHITE, Rect(target_position[0], target_position[1], 10, 10))

        # updating to the screen
        pygame.display.flip()
        if snake_position[0] > SCREEN_SIZE[0] or snake_position[0] < 0:
            gameover()
        elif snake_position[1] > SCREEN_SIZE[1] or snake_position[1] < 0:
            gameover()

        # game speed
        fps_clock.tick(6)
        
def gameover():
    """
    @decs: gameover() ends the game
    @param: None
    @retrun: int, 0
    """
    pygame.quit()
    sys.exit()



if __name__ == '__main__':
    main()