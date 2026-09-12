.PHONY: all run clean

all:
	@cmake -B build
	@cmake --build build

run: all
	@./build/text_editor

clean:
	@rm -rf build