BINDIR=bin
INCDIR=include
SRCDIR=src

PLATFORM=ML3
FLAGS=-ansi -O -I$(INCDIR) -D${PLATFORM} -DRSA_VERIFY
CARDFLAGS=$(FLAGS) -Falu
SIMFLAGS=$(FLAGS) -g -DSIMULATOR -DTEST

HEADERS=$(wildcard $(INCDIR)/*.h)
SOURCES=$(wildcard $(SRCDIR)/*.c)

SMARTCARD=$(BINDIR)/uprove.smartcard-${PLATFORM}.hzx
SIMULATOR=$(BINDIR)/uprove.simulator-${PLATFORM}.hzx

all: simulator smartcard

fresh: clean all

$(BINDIR):
	mkdir $(BINDIR)

simulator: $(HEADERS) $(SOURCES) $(SIMULATOR)

$(SIMULATOR): $(HEADERS) $(SOURCES) $(BINDIR)
	hcl $(SIMFLAGS) $(SOURCES) -o $(SIMULATOR)

smartcard: $(HEADERS) $(SOURCES) $(SMARTCARD)

$(SMARTCARD): $(HEADERS) $(SOURCES) $(BINDIR)
	hcl $(CARDFLAGS) $(SOURCES) -o $(SMARTCARD)

clean:
	rm -rf $(BINDIR)/* $(SRCDIR)/*~ $(INCDIR)/*~ $(TESTDIR)/*~

.PHONY: all clean fresh simulator smartcard
