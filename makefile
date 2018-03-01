CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= caravan.h test_caravan.h pack_animal.h general.h shortcut.h

TEST = test_caravan
PROGRAM =

TESTOBJECT = caravan_test_driver.o
MAINOBJECT =
OBJS = general.o shortcut.o caravan.o pack_animal.o test_caravan.o test_pack_animal.o

DOXY            = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp caravan.cpp.sample caravan.cpp
	cp caravan.h.sample caravan.h
	cp pack_animal.cpp.sample pack_animal.cpp
	cp pack_animal.h.sample pack_animal.h

#sets project as assignment
setassignment:
	cp caravan.cpp.assignment caravan.cpp
	cp caravan.h.assignment caravan.h
	cp pack_animal.cpp.assignment pack_animal.cpp
	cp pack_animal.h.assignment pack_animal.h

# defines current state of project as sample solution
definesample:
	cp caravan.cpp caravan.cpp.sample
	cp caravan.h caravan.h.sample
	cp pack_animal.cpp pack_animal.cpp.sample
	cp pack_animal.h pack_animal.h.sample

# defines current sate of project as assignment
defineassignment:
	cp caravan.cpp caravan.cpp.assignment
	cp caravan.h caravan.h.assignment
	cp pack_animal.cpp pack_animal.cpp.assignment
	cp pack_animal.h pack_animal.h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setassignment
	make doxy
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
