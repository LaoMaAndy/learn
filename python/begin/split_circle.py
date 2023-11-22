#!/usr/bin/env python3

from turtle import *
from math import sin,cos,pi

def split_circle(n, r = 100, x = 0, y = 0, offset = 0.5):
	dot = []
	offset = offset * pi
	for i in range(n):
		angle = offset + 2 * pi / n * i
		x_coord = x + int(r * cos(angle))
		y_coord = y + int(r * sin(angle))
		dot.append([x_coord, y_coord])
	return dot

def draw_cir(n , r = 1):
	d = split_circle(n , r)
	#print(d)
	penup()
	goto(d[0][0], d[0][1])
	pendown()
	for i in range(1, n):
		goto(d[i][0], d[i][1])
	goto(d[0][0], d[0][1])

def test_cir():
	print(split_circle(10,100))

def test_draw():
	draw_cir(2, 150)
	draw_cir(3, 150)
	draw_cir(4, 150)
	draw_cir(5, 150)
	draw_cir(6, 150)
	draw_cir(7, 150)
	draw_cir(10, 100)
	draw_cir(500, 200)
	circle(-210)


if __name__ == '__main__':
	test_cir()
	test_draw()

