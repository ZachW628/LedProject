CXX= gcc
CXX_FLAGS= -std=c99 -std=gnu99
#POST_CXX_FLAGS = -lwiringPi


all: letters program


program: i2c_base.o characters.o character_queue.o
	$(CXX) i2c_base.o characters.o character_queue.o -o test

letters: i2c_base.o characters.o letters_test_env.o
	$(CXX) i2c_base.o characters.o letters_test_env.o -o letters_test

letters_test_env.o: letters_test_env.c characters.c i2c_base.c
	$(CXX) $(CXX_FLAGS) -c letters_test_env.c characters.c i2c_base.c

character_queue.o: character_queue.c characters.c i2c_base.c
	$(CXX) $(CXX_FLAGS) -c character_queue.c characters.c i2c_base.c

characters.o: characters.c
	$(CXX) $(CXX_FLAGS) -c characters.c

i2c_base.o: i2c_base.c
	$(CXX) $(CXX_FLAGS) -c i2c_base.c

clean:
	rm -rf *.o test
