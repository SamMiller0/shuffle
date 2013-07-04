CARDS = cards

CXXFLAGS += -Werror
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wconversion
CXXFLAGS += -Wunused
CXXFLAGS += -g
CXXFLAGS += -MD

LDFLAGS  += -g

all: test

$(CARDS): Deck.o Card.o shuffle.o main.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_deck: test_deck.o Deck.o Card.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_shuffle: test_shuffle.o shuffle.o Deck.o Card.o
	$(CXX) $(LDFLAGS) -o $@ $^


test: test_deck test_shuffle | cards
	./test_deck 1> /dev/null
	./test_shuffle 1> /dev/null

clean:
	$(RM) *.o $(CARDS) *.d

docs: *.h
	doxygen 1> /dev/null

-include *.d
