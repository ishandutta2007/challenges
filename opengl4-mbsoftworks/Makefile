INC=-Icommon -Ilibs

AR=ar
CC=clang
CXXFLAGS=-Wall -Wextra
CXXFLAGS+=-march=native -O2
#CXXFLAGS+=-ggdb -g3 -fsanitize=address
CXXFLAGS+=$(INC)
CXXFLAGS+=`sdl2-config --cflags` `pkg-config --cflags assimp`
LDFLAGS=-L./ `sdl2-config --libs` `pkg-config --libs assimp` -lGL -lGLU -lm -lcommon -lstdc++

COMMON=common/*.cpp
COMMON+=common/static_meshes_3d/*.cpp common/static_meshes_3d/primitives/*.cpp
COMMON+=common/static_meshes_2d/*.cpp common/static_meshes_2d/primitives/*.cpp
COMMON+=common/shader_structs/*.cpp
COMMON+=common/transform_feedback/*.cpp

all: bin

lib:
	$(CC) $(CXXFLAGS) -c $(COMMON)
	$(AR) rcs libcommon.a *.o

bin: lib
	$(CC) $(CXXFLAGS) -o creating-opengl4-window 001-creating-opengl4-window/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o first-shader 002-first-shader/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o adding-colors 003-adding-colors/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o entering-third-dimension 004-entering-third-dimension/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o simple-walking-camera 005-camera-pt1-simple-walking-camera/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o flying-camera 006-camera-pt2-flying-camera/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o single-texture 007-textures-pt1-single-texture/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o multi-texture 008-textures-pt2-multitexturing/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o orthographic-2d-projection 009-orthographic-2D-projection/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o refactoring 010-first-great-refactoring/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o indexed-rendering-torus 011-indexed-rendering-torus/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o freetype-fonts 012-freetype-fonts-pt1/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o blending 013-blending-pt1/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o normals-diffuse-lighting 014-normals-diffuse-lighting/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o geometry-shaders 015-geometry-shaders/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o heightmap-random-terrain 016-heightmap-pt1-random-terrain/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o heightmap-skybox 017-heightmap-pt2-from-image-and-skybox/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o heightmap-multiple-layers 018-heightmap-pt3-multiple-layers/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o assimp-model-loading 019-assimp-model-loading/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o fog 020-fog/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o specular-highlight 021-specular-highlight/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o cylinder-and-sphere 022-cylinder-and-sphere/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o point-lights 023-point-lights/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o uniform-buffer-object 024-uniform-buffer-object/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o transform-feedback-particle-system 025-transform-feedback-particle-system/*.cpp $(LDFLAGS)
	$(CC) $(CXXFLAGS) -o orbit-camera 026-camera-pt3-orbit-camera/*.cpp $(LDFLAGS)

format:
	clang-format -i common/*

clean:
	rm -f creating-opengl4-window
	rm -f first-shader
	rm -f adding-colors
	rm -f entering-third-dimension
	rm -f simple-walking-camera
	rm -f flying-camera
	rm -f single-texture
	rm -f multi-texture
	rm -f orthographic-2d-projection
	rm -f refactoring
	rm -f indexed-rendering-torus
	rm -f freetype-fonts
	rm -f blending
	rm -f normals-diffuse-lighting
	rm -f geometry-shaders
	rm -f heightmap-random-terrain
	rm -f heightmap-skybox
	rm -f heightmap-multiple-layers
	rm -f assimp-model-loading
	rm -f fog
	rm -f specular-highlight
	rm -f cylinder-and-sphere
	rm -f point-lights
	rm -f uniform-buffer-object
	rm -f transform-feedback-particle-system
	rm -f orbit-camera
	rm -f *.o *.a
