#!/usr/bin/env python
"""
@desc: The module is a Ball game implemented by pygame module.
       Players uses mouses left-clikcing or right-clicking to
       control the bar at the bottom moving.
       The module uses object-oriented programming design.
@authour: Kevin Jie
@date: 2021/5/20
"""

import pygame
from pygame.locals import *
import sys
import random

# Global Constants for pre-set.
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BG_COLOUR = (0, 0, 70)  # background colour

SCREEN_SIZE = [620, 800]  # size of screen
BAR_SIZE = [30, 10]  # size of pad
BALL_SIZE = [20, 30]  # size of the ball


class Game(object):
    def __init__(self):
        pygame.init()
        self.clock = pygame.time.Clock()  # timer
        self.screen = pygame.display.set_mode(SCREEN_SIZE)
        pygame.display.set_caption('My Game')  # header

        # ball initial position
        self.ball_pos_x = SCREEN_SIZE[0] // 2 - BALL_SIZE[0] / 2
        self.ball_pos_y = 0
        # ball moving direction
        self.ball_dir_y = 1  # 1:down

        self.ball_pos = pygame.Rect(self.ball_pos_x, self.ball_pos_y, BALL_SIZE[0], BALL_SIZE[1])

        self.score = 0
        self.bar_pos_x = SCREEN_SIZE[0] // 2 - BAR_SIZE[0] // 2
        self.bar_pos = pygame.Rect(self.bar_pos_x, SCREEN_SIZE[1] - BAR_SIZE[1], BAR_SIZE[0], BALL_SIZE[1])

    def bar_move_left(self):
    """
    @desc: self.bar_move_left() moves the bar 2 units left
    @param: None
    @return: None
    """
        self.bar_pos_x = self.bar_pos_x - 2


    def bar_move_right(self):
    """
    @desc: self.bar_move_right() moves the bar 2 units right
    @param: None
    @return: None
    """
        self.bar_pos_x = self.bar_pos_x + 2


    def run(self):
    """
    @desc: self.run() enters the main procedure of the program
    @param: None
    @return: None
    """
        pygame.mouse.set_visible(0)  # 0 is mouse invisible; 1 is mouse visible
        bar_move_left = False
        bar_move_right = False
        while True:
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()

                elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:  # mouse left-clicking
                    bar_move_left = True
                elif event.type == pygame.MOUSEBUTTONUP and event.button == 1:  # bounce left
                    bar_move_left = False
                elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 3:  # mouse right-clicking
                    bar_move_right = True
                elif event.type == pygame.MOUSEBUTTONUP and event.button == 3:  # bounce right
                    bar_move_right = False

            if bar_move_left == True and bar_move_right == False:
                self.bar_move_left()
            if bar_move_left == False and bar_move_right == True:
                self.bar_move_right()

            self.screen.fill(BG_COLOUR)
            self.bar_pos.left = self.bar_pos_x
            pygame.draw.rect(self.screen, WHITE, self.bar_pos)

            # Movement of the ball
            self.ball_pos.bottom += self.ball_dir_y * 3
            pygame.draw.rect(self.screen, WHITE, self.ball_pos)

            # Determine the landing point
            if self.bar_pos.top <= self.ball_pos.bottom and (
                    self.bar_pos.left <= self.ball_pos.right and self.bar_pos.right >= self.ball_pos.left):
                self.score += 1
                print("Score: ", self.score, end='\r')
            elif self.bar_pos.top <= self.ball_pos.bottom and (
                    self.bar_pos.left > self.ball_pos.right or self.bar_pos.right < self.ball_pos.left):
                print("Game Over: ", self.score)
                return self.score

            # Updating the initial position if failed to catch the ball
            if self.bar_pos.top <= self.ball_pos.bottom:
                self.ball_pos_x = random.randint(0, SCREEN_SIZE[0] - BALL_SIZE[0])
                self.ball_pos_y = 0
                self.ball_pos = pygame.Rect(self.ball_pos_x, self.ball_pos_y, BALL_SIZE[0], BALL_SIZE[1])

            pygame.display.update()  # Update the screens
            self.clock.tick(60)


game = Game()
game.run()