CC=x86_64-w64-mingw32-gcc
ED=vim
SRC=src/main
DEPS=src/headers
BUILD=build

$(BUILD)/evilquartiles.exe: $(SRC)/averager.c $(BUILD)
	$(CC) -o $@ $< -I $(DEPS) 
debug: $(SRC)/averager.c $(BUILD)
	$(CC) -o $(BUILD)/averager.exe $< -I $(DEPS) -g
clean:
	rm -rf $(BUILD)
work: 
	$(ED) $(SRC) 
$(BUILD):
	mkdir -pv $@
