import matplotlib.pyplot as plt

sq = [v**2 for v in range(100)]
input_value = [v for v in range(100)]
plt.plot(input_value, sq, linewidth = 5)
plt.title("Square Numbers", fontsize = 24)
plt.xlabel("Value", fontsize =14)
plt.ylabel("Square of value", fontsize = 14)
plt.tick_params(axis = 'both', labelsize = 14)
plt.show()

