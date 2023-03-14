int Isspace(int c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\v';
}

int Isdigit(int c)
{
	return c >= '0' && c <= '9';
}
int Isupper(int c)
{
	return c >= 'A' && c <= 'Z';
}

int Islower(int c)
{
	return c >= 'a' && c <= 'z';
}

int Isalpha(int c)
{
	return Isupper(c) || Islower(c);
}

int Isalnum(int c)
{
	return Isalpha(c) || Isdigit(c);
}

int Toupper(int c)
{
	if (Islower(c))
		return c - 'a' + 'A';
	return c;
}

int Tolower(int c)
{
	if (Isupper(c))
		return c - 'A' + 'a';
	return c;
}

