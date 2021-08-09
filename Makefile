install:
	#"update package list";
	sudo apt update

	sudo apt install libsdl2-dev libsdl2-2.0-0 \
	libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev \
	libsdl2-image-2.0-0 libmikmod-dev libfishsound1-dev libsmpeg-dev \
	liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev \
	libsdl2-mixer-2.0-0 libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y 
	
	#"installeerde sdl2, SDL2_image voor afbeelding,  sdl2_mixer voor geluid, sdle_fonts voor tekst"