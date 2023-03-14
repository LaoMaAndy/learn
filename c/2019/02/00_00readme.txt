修改：
1)	int Getword(FILE *fp, char *buf, size_t bsize);
	改为：
	int Getword(FILE *fp, char *buf, int bsize);
	同改
	int Getline();
2)将mem.h 融入到head.h中	
	
