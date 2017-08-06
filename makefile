CXX= gcc
CXX_FLAGS= -std=c99 -std=gnu99
#POST_CXX_FLAGS = -lwiringPi


program: i2c_base.o characters.o character_queue.o
	$(CXX) i2c_base.o characters.o character_queue.o -o test

character_queue.o: character_queue.c characters.c i2c_base.c
	$(CXX) $(CXX_FLAGS) -c character_queue.c characters.c i2c_base.c

characters.o: characters.c
	$(CXX) $(CXX_FLAGS) -c characters.c

i2c_base.o: i2c_base.c
	$(CXX) $(CXX_FLAGS) -c i2c_base.c

clean:
	rm -rf *.o test
