CC=gcc
ED=vim
SRC=src/main
DEPS=src/headers
BUILD=build

$(BUILD)/averager: $(SRC)/averager.c $(BUILD)
	$(CC) -o $@ $< -I $(DEPS) 
debug: $(SRC)/averager.c $(BUILD)
	$(CC) -o $(BUILD)/averager $< -I $(DEPS) -g
clean:
	rm -rf $(BUILD)
work: 
	$(ED) $(SRC) 
$(BUILD):
	mkdir -pv $@
