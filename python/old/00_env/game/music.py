import pygame
import time
import sys

pygame.mixer.init()
pygame.display.init()

screen = pygame.display.set_mode( (420, 240) )

playlist = list()
playlist.append("./music/01.mp3")
playlist.append("./music/02.mp3")
playlist.append("./music/03.mp3")

pygame.mixer.music.load(playlist.pop())
pygame.mixer.music.queue(playlist.pop())
pygame.mixer.music.set_endevent(pygame.USEREVENT)
pygame.mixer.music.play()

running = True
while running:
	for event in pygame.event.get():
		if event.type == pygame.USEREVENT:
			if len(playlist) > 0:
				pygame.mixer.music.queue(playlist.pop())
		if event.type == pygame.QUIT:
			running = False
pygame.quit()
sys.exit()
