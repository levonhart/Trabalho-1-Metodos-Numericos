IDIR = include/
SDIR = src/

all: $(SDIR)raizes.o

$(SDIR)raizes.o: $(SDIR)raizes.c $(IDIR)raizes.h
	gcc -c -I $(IDIR) $(SDIR)raizes.c -o $(SDIR)raizes.o

clean:
	rm $(SDIR)*.o
