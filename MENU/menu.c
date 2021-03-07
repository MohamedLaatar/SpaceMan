#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"


void charger_image(char image[],SDL_Surface *screen,SDL_Surface *sprite,SDL_Rect *positionsprite)
	{
	sprite = IMG_Load(image);
    	SDL_BlitSurface(sprite, NULL, screen, positionsprite);
    	SDL_Flip(screen);
    	}
    	
    	
int menu1(SDL_Surface *ecran)
{
SDL_Event event;
	SDL_Surface *imgplay=NULL,*imgplay1=NULL,*imgoption=NULL,*imgoption1=NULL,*imgbackground=NULL,*imgquit=NULL,*imgquit1=NULL,*textecm=NULL,*imgembleme=NULL;
	SDL_Surface *animation[8];
	SDL_Rect posetoile,posplay,posoption, posbackground,posquit,poscurseur,postextecm,posembleme,posbgplay;
	Mix_Music *musique;
	Mix_Chunk *son;
	int continuer=1;
	int largeurecran=880;
	int longeurecran=1500;
	int mouse=0;
	int keyboard=0;
	bouton play,option,exit;
	int i=0;
	
//etoiles
	posetoile.x=200;
	posetoile.y=200;
	
/*background*/	
	posbackground.x=0;
	posbackground.y=0;


	charger_image("au13kt33ypb51.png",ecran,imgbackground,&posbackground);

/*play*/

       posplay.x=590;
	posplay.y=300;
	
	play.x=posplay.x;
	play.y=posplay.y;
	play.h=85;
	play.w=320;
	charger_image("play_button1.png",ecran,imgplay1,&posplay);
	
/*option*/
       posoption.x=590;
	posoption.y=420;
	
	option.x=posoption.x;
	option.y=posoption.y;
	option.h=85;
	option.w=320;
	charger_image("option_button1.png",ecran,imgoption1,&posoption);
	
/*quit*/
	posquit.x=590;
	posquit.y=540;
	
	exit.x=posquit.x;
	exit.y=posquit.y;
	exit.h=85;
	exit.w=320;
	charger_image("exit_button1.png",ecran,imgquit1,&posquit);
	
/*embleme*/
	posembleme.x=0;
	posembleme.y=780;
	
	charger_image("embleme.png",ecran,imgembleme,&posembleme);

/*texte*/
	postextecm.x=70;
	postextecm.y=700;
	TTF_Init();
	TTF_Font *police=NULL;
	SDL_Color couleurgris={172,169,169};
	
	police=TTF_OpenFont("OpenSans-Regular1.ttf",20);

	textecm=TTF_RenderText_Blended(police," THE VISIONARIES",couleurgris);
	SDL_BlitSurface(textecm,NULL,ecran,&postextecm);
	SDL_Flip(ecran);

	TTF_CloseFont(police);
	TTF_Quit;
	SDL_WM_SetCaption("GAME	",NULL);

/*Music*/
	Mix_AllocateChannels(5);
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024) == -1)
   	{
  	    printf("%s", Mix_GetError());
   	}
	Mix_VolumeChunk(son, MIX_MAX_VOLUME);
	musique = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(musique,-1);
	son=Mix_LoadWAV("11.wav");



/*evenements*/
	SDL_EnableKeyRepeat(10,10);
while (continuer==1)
{	




    
    	
	animation[0] = IMG_Load("etoile.png");
	animation[1] = IMG_Load("etoile1.png");
	animation[2] = IMG_Load("etoile2.png");
	animation[3] = IMG_Load("etoile3.png");
	animation[4] = IMG_Load("etoile4.png");
	animation[5] = IMG_Load("etoile5.png");
	animation[6] = IMG_Load("etoile6.png");
	animation[7] = IMG_Load("etoile7.png");
     SDL_BlitSurface(animation[i], NULL, ecran, &posbackground);
     SDL_Flip(ecran);
     free(animation[i]);
     SDL_Delay(100);
           i++;
      if (i==8)
      i=0;

    
 


    	
        	while(SDL_PollEvent(&event))
             { 
        	switch(event.type)
        	{
            	case SDL_QUIT:
            		continuer = 0;
            		return continuer;
                break;

		case SDL_MOUSEMOTION:
 	poscurseur.x = event.motion.x;
	poscurseur.y = event.motion.y;
	
         	 if( ( poscurseur.x > play.x ) && ( poscurseur.x < play.x + play.w ) && ( poscurseur.y > play.y ) && ( poscurseur.y < play.y + play.h ) )
            	{
                //Mise à jour du bouton play
               charger_image("play_button2.png",ecran,imgplay1,&posplay);
               mouse=1;
               keyboard=0;
           	 }
           	 else charger_image("play_button1.png",ecran,imgplay1,&posplay);
           	 
           	 if( ( poscurseur.x > option.x ) && ( poscurseur.x < option.x + option.w ) && ( poscurseur.y > option.y ) && ( poscurseur.y < option.y + option.h ) )
            	{
                //Mise à jour du bouton option
                charger_image("option_button2.png",ecran,imgoption1,&posoption);
                mouse=2;
                keyboard=0;
           	 }
           	 else charger_image("option_button1.png",ecran,imgoption1,&posoption);
           	 
           	 if( ( poscurseur.x > exit.x ) && ( poscurseur.x < exit.x + exit.w ) && ( poscurseur.y > exit.y ) && ( poscurseur.y < exit.y + exit.h ) )
            	{
                //Mise à jour du bouton exit
                charger_image("exit_button2.png",ecran,imgquit1,&posquit);
                mouse=3;
                keyboard=0;
                
           	 }
           	 else charger_image("exit_button1.png",ecran,imgquit1,&posquit);
           	 
            
		break;
		case SDL_MOUSEBUTTONUP:
		
		if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 1))
		{
		
					continuer=3;
					return continuer;
            	        
				//apuie sur play
		}
		
		if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 2))
		{
		
				        continuer=2;
					return continuer;
				//apuie sur option
		}
		
		if((event.button.button == SDL_BUTTON_LEFT) && (mouse == 3))
		{
					continuer = 0;
					return continuer;
		}
		
		break ;


                 case SDL_MOUSEBUTTONDOWN :
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
                        
			Mix_PlayChannel(-1,son,0);

			break;
			}
		break;

            	case SDL_KEYDOWN:
            	    switch(event.key.keysym.sym)
            	        {
            	        case SDLK_j:
            	        
					continuer=3;
					return continuer;
            	        
            	        break;
            	        
            	        case SDLK_o:
            	       			continuer=2;
					return continuer;
            	        
            	        break;
            	        
            	        case SDLK_UP:
            	        
				if((keyboard==1) || (keyboard==0))
				keyboard=3;
				
				else
            			keyboard--;
              		break;
              		
			case SDLK_DOWN:
				if(keyboard==3)
				keyboard=1; 
				else 
				keyboard++;
		 	break;
		 	
		 	
		 	
			case SDLK_RETURN: 
				if(keyboard==1)
				{
					continuer=3;
					return continuer;
					//apuie sur play 
				}
				
				
				if(keyboard==2)
				{
					continuer=2;
					return continuer;
				}
				if(keyboard==3)
				{
					continuer = 0;
					return continuer;
				}
		
			break;
			

			

                        case SDLK_ESCAPE:
                        	continuer = 0;
                        	return continuer;
 			break;
 			
 			case SDLK_f:
 			ecran = SDL_SetVideoMode(longeurecran,largeurecran, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN );
 			charger_image("au13kt33ypb51.png",ecran,imgbackground,&posbackground);

				if (ecran==NULL)
				{printf("unable to set video mode:%s \n",SDL_GetError());}
			break;
 			
                        
		 }break;
			
		 }
		
			
			
			if (keyboard!=0)
			{
			
				if(keyboard==1)
				{
				 charger_image("play_button2.png",ecran,imgplay1,&posplay);
				 mouse=0;
				}
				else{charger_image("play_button1.png",ecran,imgplay1,&posplay);
				mouse=0;
				}
				
				if(keyboard==2)
				{
				charger_image("option_button2.png",ecran,imgoption1,&posoption);
				mouse=0;
				}
				else{charger_image("option_button1.png",ecran,imgoption1,&posoption);
				mouse=0;
				}
				
				if(keyboard==3)
				{
				charger_image("exit_button2.png",ecran,imgquit1,&posquit);
				mouse=0;
				}
				else{charger_image("exit_button1.png",ecran,imgquit1,&posquit);
				mouse=0;
				}
			}
			
}
		 
}		 	


	continuer=0;
        return continuer;
//TTF_CloseFont (police);
    TTF_Quit();
    //Mix_FreeMusic(music); // Libére en mémoire notre musique
    Mix_CloseAudio(); // Quitter correctement SDL_Mixer
    
    
    SDL_Quit();


}









int menu2(SDL_Surface *ecran)
{
SDL_Event event;
SDL_Surface  *image=NULL,*sprite1=NULL,*sprite2=NULL,*sprite3=NULL,*sprite4=NULL,*sprite5=NULL,*sprite6=NULL,*sprite7=NULL;
SDL_Rect positionecran,positionsprite1,positionsprite2,positionsprite3,positionsprite4;
int continuer = 1;
int mouse=0;
int keyboard=0;
				    


				//Fond 
				positionecran.x=0;
				positionecran.y=0;
				
				
				//sound on
				positionsprite1.x=85;
				positionsprite1.y=200;
				positionsprite1.w=320;
				positionsprite1.h=85;
			
			
				//sound off
				positionsprite2.x=85;
				positionsprite2.y=300;
				positionsprite2.w=320;
				positionsprite2.h=85;
				
				
				//back
				positionsprite3.x=85;
				positionsprite3.y=400;
				positionsprite3.w=320;
				positionsprite3.h=85;
				
				// options
				positionsprite4.x=85;
				positionsprite4.y=100;
				positionsprite4.w=320;
				positionsprite4.h=85;
				
				
				
				
				
				charger_image("au13kt33ypb51.png",ecran,image,&positionecran);  
				charger_image("sound_on.png",ecran,sprite1,&positionsprite1);
				charger_image("sound_off.png",ecran,sprite2,&positionsprite2);
				charger_image("back.png",ecran,sprite3,&positionsprite3);
				charger_image("option_button1.png",ecran,sprite4,&positionsprite4);
				

				

				    while (continuer!=0)
				    {
					while(SDL_PollEvent(&event))
             { 
					switch(event.type)
					{
					    case SDL_QUIT:
						continuer = 0;
						return continuer;
					break ;
				case SDL_MOUSEMOTION:
	if((event.motion.x>positionsprite1.x)&&(event.motion.x<positionsprite1.x + positionsprite1.w)&&(event.motion.y>positionsprite1.y)&&(event.motion.y<positionsprite1.y + positionsprite1.h))
				{
				mouse=1;
				charger_image("sound_on1.png",ecran,sprite4,&positionsprite1);
				}
				else {charger_image("sound_on.png",ecran,sprite1,&positionsprite1);
				}
	if((event.motion.x>positionsprite2.x)&&(event.motion.x<positionsprite2.x + positionsprite2.w)&&(event.motion.y>positionsprite2.y)&&(event.motion.y<positionsprite2.y + positionsprite2.h))
				{mouse=2;
				charger_image("sound_off1.png",ecran,sprite5,&positionsprite2);
				}else {charger_image("sound_off.png",ecran,sprite2,&positionsprite2);
				}
	if((event.motion.x>positionsprite3.x)&&(event.motion.x<positionsprite3.x + positionsprite3.w)&&(event.motion.y>positionsprite3.y)&&(event.motion.y<positionsprite3.y + positionsprite3.h))
				{mouse=3;
				charger_image("back1.png",ecran,sprite6,&positionsprite3);
				}else {charger_image("back.png",ecran,sprite3,&positionsprite3);
				}
				break; 
				
				
				
				case SDL_MOUSEBUTTONUP:
				if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 3)){
				continuer=1;
				}
				if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 2))
				{Mix_VolumeMusic(0);
                     		/*const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
				// Reconfigure le mode vidéo
				SDL_SetVideoMode(myPointer->current_w, myPointer->current_h, 16, SDL_DOUBLEBUF|SDL_FULLSCREEN);*/}
				
				if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 1))
				{Mix_VolumeMusic(MIX_MAX_VOLUME);}
				
				break; 
				
				
				
				case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				
				case SDLK_UP:
				keyboard--;
				break;
				
				case SDLK_DOWN: 
				 keyboard++;
				 break;
				 
				 
				case SDLK_RETURN:
				 
				if(keyboard==3)
				{continuer = 1;}
				
				if(keyboard==3)
				{Mix_PauseMusic();}
				
				if(keyboard==2)
				{Mix_ResumeMusic();}
				break; 
				
				
				}

				  }
				if(keyboard>3){keyboard=1;}
				if(keyboard<0){keyboard=3;}
				
				
				if(keyboard==1)
				{charger_image("sound_on1.png",ecran,sprite4,&positionsprite1);}
				else {charger_image("sound_on.png",ecran,sprite1,&positionsprite1);}

				if(keyboard==2)
				{charger_image("sound_off1.png",ecran,sprite5,&positionsprite2);}
				else {charger_image("sound_off.png",ecran,sprite2,&positionsprite2);}

				if(keyboard==3){
				charger_image("back1.png",ecran,sprite6,&positionsprite3);}
				else {charger_image("back.png",ecran,sprite3,&positionsprite3);}
				

				break;
				}

				}
				
				/*SDL_FreeSurface(*sprite1);
				SDL_FreeSurface(*sprite2);
				SDL_FreeSurface(*sprite3);
				SDL_FreeSurface(*sprite4);
				SDL_FreeSurface(*sprite5);
				SDL_FreeSurface(*sprite6);
				SDL_FreeSurface(*sprite7);*/
				}
				
