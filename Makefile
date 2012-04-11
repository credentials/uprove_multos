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

.PHONY: all clean simulator smartcard
