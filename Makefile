.PHONY: all run clean

all:
	@cmake -B build
	@cmake --build build

run: all
	@./build/irm

clean:
	@rm -rf build