all:main

opt=-g

main: main.c perc rules characters
	gcc -Wall perc.o rules.o main.c -o perceptron $(opt)

perc: perc.c perc.h characters.h
	gcc -Wall -c perc.c $(opt)

rules: rules.c rules.h characters.h
	gcc -Wall -c rules.c $(opt)

characters: characters.c characters.h
	gcc -Wall -c characters.c $(opt)
clean:
	rm -f *.o perceptron
