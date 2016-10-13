/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Keos/Day08
** 
** Made by Thomas Riot
** Login   <Keos@epitech.net>
** 
** Started on  Wed Oct 12 10:08:41 2016 Thomas Riot
** Last update Thu Oct 13 10:58:23 2016 Thomas Riot
*/

#include <stdlib.h>

int	word_lenght(char *str)
{
  int	i;
  int	compteur;
  int	compteur_temp;

  i = 0;
  compteur = 0;
  compteur_temp = 0;
  while (str[i] != '\0')
    {
      compteur_temp = compteur_temp + 1;
      if ((str[i] < 48 || str[i] > 57) && (str[i] < 65 || str[i] > 90))
	{
	  if (str[i] < 97 || str[i] > 122)
	    {
	      if (compteur < compteur_temp)
		{
		  compteur = compteur_temp;
		  compteur_temp = 0;
		}
	    }
	}
      i = i + 1;
    }
  return (compteur);
}

int	nbr_words(char *str)
{
  int	k;
  int	compteur;
  
  k = 0;
  compteur = 0;
  while (str[k] != '\0')
    {
      if ((str[k] < 48 || str[k] > 57) && (str[k] < 65 || str[k] > 90))
	{
	  if (str[k] < 97 || str[k] > 122)
	    {
	      compteur = compteur + 1;
	    }
	}
      k = k + 1;
    }
  return (compteur);
}

void	displayer(char **tab, int nb_words, int taille)
{
  int	i;
  int	k;
  char	c;
  
  i = 0;
  while (i <= nb_words)
    {
      k = 0;
      while (k < taille)
	{
	  c = tab[i][1];
	  //printf("%c", c);
	  k = k + 1;
	}
      i = i + 1;
    }
}

char	spliter(char **tab, char *str, int nb_words, int taille)
{
  int	c;
  int	l;
  int	s;

  s = 0;
  c = 0;
  l = 0;
  while (s <= nb_words)
    {
      tab[l][c] = str[s];
      if ((str[s] < 48 || str[s] > 57) && (str[s] < 65 || str[s] > 90))
	{
	  if (str[s] < 97 || str[s] > 122)
	    {
	      tab[l][c] = '\0';
	      l = l + 1;
	      c = 0;
	    }
	}
      s = s + 1;
      c = c + 1;
    }
  displayer(tab, nb_words, taille);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	taille;
  int	nb_words;
  int	m;

  nb_words = nbr_words(str);
  taille = word_lenght(str);
  tab = malloc(sizeof(char) * (nb_words + 1));
  m = 0;
  while (m <= nb_words)
    {
      tab[m] = malloc(sizeof(char) * (taille + 1));
      m = m + 1;
    }
  spliter (tab, str, nb_words, taille);
  //tab[1] = str[2];
  //printf("%c", tab[1]);
  return (tab);
}

int	main()
{
  char	*str = "hello$world<this*is)an-exemple";
  
  my_str_to_wordtab(str);
  return(0);
}
