/*
* match.c
* author: Eli Pandolfo
*
* checks if two strings match, when the second string can contain any number of *.
* examples: "qwerty" matches "*****er*", "asdf" matches "asd*", "columbus" does not match "*umbu"
*
* goes through each char recursively:
*	if you get to the end of both strings at the same time, return true
*	else if the current char is shared between the 2 strings, increment both counters
*	else if the current char in string 2 is an * and we already got to the end of s1 ("asdf*" and "asdf"), increment s2
*	else if s2 is an *, allow the program to figure out whether the * represents 0, 1, or more chars in
*		s1 by using an || in the return statement. Basically, the program tries every combination of what
*		the asterix could represent and returns true if one of those combos is a match.
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
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	return (0);
}
