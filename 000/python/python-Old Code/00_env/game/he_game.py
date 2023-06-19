import pygame
import sys

pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption("he, game")
FPS = 30
fpsClock = pygame.time.Clock()

count = 0
while True:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			sys.exit()
		elif event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				print("Esc is pressed")
		elif event.type == pygame.MOUSEMOTION:
			m_posx = event.pos[0]
			m_posy = event.pos[1]
			print("Mouse pos: " + str(m_posx) + ", " + str(m_posy))
	#print("flipiing: " + str(count))
	count += 1
	pygame.display.flip()
	fpsClock.tick(FPS)
