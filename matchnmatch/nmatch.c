/*
* match.c
* author: Eli Pandolfo
*
* checks how many times two strings match, when the second string can contain any number of *.
* for example, "asdf" and "as**" match 3 times; the first * could be "df" and the second could be "",
* 	the first could be "d" and the second could be "f", or the first could be "" and the second could be "df"
*
* similar to match but has a + instead of an || in the last return statement, to count all combinations
* of what each * could represent.
*/

int		match(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 == *s2 && *s1 != '*')
		return (match(s1 + 1, s2 + 1));
	if (*s2 == '*' && !*s1)
		return (match(s1, s2 + 1));
	if (*s2 == '*')
		return (match(s1 + 1, s2) + match(s1, s2 + 1));
	return (0);
}
