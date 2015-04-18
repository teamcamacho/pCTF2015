#!/usr/bin/env python

import sys

keys = open("what kind of mysterious message is this", "r").read()

def printgrid(grid):
    for o in reversed(grid):
        for i in range(len(o)):
            sys.stdout.write(o[i][0])
        print

def processmoves(moves, grid):

    for m in moves:
        grid[m[1]][m[0]] = "*"

    return grid

grid = [ [ " " for i in range(164) ] for i in range(20) ]

x = 2
y = 10

moves = list([[x,y]])

write = True

for i in keys:
    if i == "a":
        x -= 1
    if i == "s":
        y -= 1
    if i == "d":
        x += 1
    if i == "w":
        y += 1
    if i == "e":
        write = not write
    
    if write:
        moves.append([x,y])

newgrid = processmoves(moves, grid)
printgrid(newgrid)

