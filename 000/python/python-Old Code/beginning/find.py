girls = ['alice', 'bernice', 'clarice', 'allen']
boys = ['chris', 'arnold', 'bob']
letterGirls = {}
for girl in girls:
	letterGirls.setdefault(girl[0], []).append(girl)
print(letterGirls)