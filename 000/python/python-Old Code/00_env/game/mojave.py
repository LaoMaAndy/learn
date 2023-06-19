
 
pygame.init()
 
# 1. 创建游戏窗口
screen = pygame.display.set_mode((480, 800))
 
# 2. 绘制图像
bg = pygame.image.load("./images/background.png")
hero_plane = pygame.image.load("./images/hero.png")
 
# 3. 将图像绘制到屏幕的指定位置
screen.blit(bg, (0, 0))
 
# 记录英雄飞机的初始位置及大小
hero_rect = pygame.Rect(200, 720, 72, 72)
 
# 4. 创建时钟对象
game_clock = pygame.time.Clock()
 
# pygame.display.update()
 
while True:
    game_clock.tick(60)
    hero_rect.y -= 1
    screen.blit(hero_plane, hero_rect)
    pygame.display.update()
 
pygame.quit()