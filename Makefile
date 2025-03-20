CC=x86_64-w64-mingw32-gcc
CC2=gcc
ED=vim
SRC=src/main
DEPS=src/headers
BUILD=build
SC=$(SRC)/averager.c $(SRC)/eq.c

$(BUILD)/eq.exe: $(SC) $(BUILD)
	$(CC) -o $@ $(SC) -I $(DEPS)
$(BUILD)/eq: $(SC) $(BUILD)
	$(CC2) -o $@ $(SC) -I $(DEPS)
debug: $(SC) $(BUILD)
	$(CC2) -o $(BUILD)/eq $(SC) -I $(DEPS) -g
clean:
	rm -rf $(BUILD)
work: 
	$(ED) $(SRC) 
head:
	$(ED) $(DEPS)
$(BUILD):
	mkdir -pv $@
