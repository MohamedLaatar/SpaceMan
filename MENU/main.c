#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "fonctions.h"

int main (void)
{
	
int continuer= 1;
int largeurecran=880;
int longeurecran=1500;

SDL_Surface *ecran=NULL;
/*init*/
	
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO );



	ecran = SDL_SetVideoMode(longeurecran,largeurecran, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );

	if (ecran==NULL)
	{
	printf("unable to set video mode:%s \n",SDL_GetError());
	return 1;
	}
	
	
	
	while (continuer!=0)
  {
	      switch (continuer)
      {
      //appeler ecran menu
      case 1:
          	continuer = menu1(ecran);
          	
      break;
      //options
      case 2:
      		continuer = menu2(ecran);
          
      break;
      case 3:
          continuer=1;
          // jouer (fonction jouer)
      break;
  
      }     
}

    //TTF_CloseFont (police);
    TTF_Quit();
    //Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio(); // Quitter correctement SDL_Mixer
    
    
    SDL_Quit();

    return EXIT_SUCCESS;


}
