sentence = input("Sentence: ")
screen_width = 80
text_width = len(sentence)
box_width = text_width + 6
left_margin = (screen_width - box_width) // 2

print()
print(' ' * left_margin + '+' + '+')
print(' '*left_margin+'|'+ ' |')
print(' '*left_margin+'|'+ ' |')
print(' '*left_margin+'|'+ ' |')
print(' ' * left_margin + '+' + '+')
print()