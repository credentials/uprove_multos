BINDIR=bin
INCDIR=include
SRCDIR=src
TESTDIR=test

FLAGS=-ansi
CARDFLAGS=$(FLAGS) -I$(INCDIR)
SIMFLAGS=$(FLAGS) -g -I$(INCDIR) -DSIMULATOR -DTEST

HEADERS=$(wildcard $(INCDIR)/*.h)
SOURCES=$(wildcard $(SRCDIR)/*.c)

SMARTCARD=$(BINDIR)/uprove.smartcard.hzx
SIMULATOR=$(BINDIR)/uprove.simulator.hzx

all: simulator smartcard

simulator: $(HEADERS) $(SOURCES) $(SIMULATOR)

$(SIMULATOR): $(HEADERS) $(SOURCES)
	hcl $(SIMFLAGS) $(SOURCES) -o $(SIMULATOR)

smartcard: $(HEADERS) $(SOURCES) $(SMARTCARD)

$(SMARTCARD): $(HEADERS) $(SOURCES)
	hcl $(CARDFLAGS) $(SOURCES) -o $(SMARTCARD)

clean:
	rm -rf $(BINDIR)/* $(SRCDIR)/*~ $(INCDIR)/*~ $(TESTDIR)/*~

.PHONY: all clean simulator smartcard
