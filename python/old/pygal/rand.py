from random import randint
import pygal

loop_time = 100
rand_range = 10
i = 0
result = []
while i < loop_time:
	val = randint(0, rand_range)
	result.append(val)
	i += 1
print(result)
pic = pygal.Bar()
pic.title = "Result of rolling D6"
pic.x_labels = ['1', '2', '3', '4', '5', '6']
pic.x_title = "Result"
pic.y_title = "Frequency"

freq = [155, 167, 168, 170, 159, 181]
pic.add('D6', freq)
pic.render_to_file("die.svg")

