CXX= gcc
CXX_FLAGS= -std=c99 
#POST_CXX_FLAGS = -lwiringPi


program: i2c_base.o characters.o
	$(CXX) i2c_base.o characters.o -o test

#character_queue.o: character_queue.c characters.h
#	$(CXX) $(PRE_CXX_FLAGS) -c character_queue.c $(POST_CXX_FLAGS)

characters.o: characters.c i2c_base.h
	$(CXX) $(CXX_FLAGS) -c characters.c

i2c_base.o: i2c_base.c
	$(CXX) $(CXX_FLAGS) -c i2c_base.c

clean:
	rm -rf *.o
