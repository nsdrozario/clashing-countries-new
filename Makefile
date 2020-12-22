CXX := g++

INCLUDE := -Iinclude/ -I/mingw64/include/ncurses

LIBS_CLIENT := -lncurses -lsfml-network -lsfml-system
LIBS_SERVER := -lsfml-network -lsfml-system

SRCS_CLIENT := $(wildcard client/*.cpp)
SRCS_SERVER := $(wildcard server/*.cpp)
SRCS_SHARED := $(wildcard shared/*.cpp)

OBJS_CLIENT := $(patsubst client/%.cpp, obj/client/%.o, $(SRCS_CLIENT))
OBJS_SERVER := $(patsubst server/%.cpp, obj/server/%.o, $(SRCS_SERVER))
OBJS_SHARED := $(patsubst shared/%.cpp, obj/shared/%.o, $(SRCS_SHARED))


obj/client/%.o: client/%.cpp
	$(CXX) $(INCLUDE) $^ -c -o $@ -std=c++17

obj/server/%.o: server/%.cpp
	$(CXX) $(INCLUDE) $^ -c -o $@ -std=c++17

obj/shared/%.o: shared/%.cpp
	$(CXX) $(INCLUDE) $^ -c -o $@ -std=c++17

server: $(OBJS_SERVER) $(OBJS_SHARED)
	$(CXX) $(OBJS_SERVER) $(OBJS_SHARED) -o server.exe $(LIBS_SERVER)

client: $(OBJS_CLIENT) $(OBJS_SHARED)
	$(CXX) $(OBJS_CLIENT) $(OBJS_SHARED) -o client.exe $(LIBS_CLIENT)
