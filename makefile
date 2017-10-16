helloworld: HelloWorld.cpp
	g++ HelloWorld.cpp \
		-I${HOME}/include \
		${HOME}/lib/libsfml-graphics.dylib \
		${HOME}/lib/libsfml-system.dylib \
		${HOME}/lib/libsfml-window.dylib \
		-o ./build/dist/HelloWorld

clean:
	rm -f ./build/dist/*
